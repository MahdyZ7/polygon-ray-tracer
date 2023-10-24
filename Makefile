NAME = raytracing
NAMEDEBUG = raytracing-debug

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')

HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

OBJDIR = obj

_OBJS = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJDIR)/,$(_OBJS))

$(shell mkdir -p $(OBJDIR))

CXX = c++ 
override CXXFLAGS += -g -Wno-everything -MMD -MP 

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -ldl

DEPS = $(OBJS:.o=.d)


all: $(NAME)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LIBS) -c $< -o $@


$(NAME): $(OBJS) Makefile
	$(CXX) $(CXXFLAGS)  $(OBJS) -o $(NAME) $(LIBS)

$(NAMEDEBUG): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -O0 $(OBJS) -o $(NAMEDEBUG) $(LIBS)

run : $(NAME)
	./$(NAME)

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re