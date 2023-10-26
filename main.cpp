#include "raytracing.hpp"

void hardcoded_data(Data &data)
{
	std::cout << "A";
	data.cam.pos = Vector(0, 0, -100);
	data.cam.orientation =Vector(0, 0, 1);
	data.cam.fov = 60;

	// data.triangles = readfile();
	
}

void add_tri(Data &data)
{
	Triangle T(Vector(-10, 0, 0), Vector(0, 10, 0), Vector(10, 0, 0));
	
	data.triangles.push_back(T);
	std::cout << "triangle is " << T << std::endl;
	std::cout << "triangle = " << data.triangles.size() << std::endl;
}

void init_data(Data &data)
{
	uint	screen_size = WIN_HIGHT * WIN_WIDTH * 4;
	for (int i = 0; i < screen_size ; i++)
		data.pixels[i] = (char)((i%4 == 3) * 255);
	data.cam.pos= Vector(0, 0, 0); // temp adjustment
	data.cam.orientation = Vector(0, 0, 1); // temp adjustment
	// data.cam.up(0, 1, 0); // temp adjustment
	data.cam.fov = 60; // temp adjustment

	data.kit.invwidth = 1 / (float)WIN_WIDTH;
	data.kit.invheight = 1 / (float)WIN_HIGHT;
	data.kit.aspectratio = (float)WIN_WIDTH / (float)WIN_HIGHT;
	data.kit.angle = tan(M_PI * 0.5 * data.cam.fov / 180.);
	// data.kit.color = 0;

	for (int x = 0; x < WIN_WIDTH; x++)
	{
		for (int y = 0; y < WIN_HIGHT; y++)
		{
			float x_ = (2 * ((x + 0.5) * data.kit.invwidth) - 1) 
				* data.kit.angle * data.kit.aspectratio;
			float y_ = (1 - 2 * ((x + 0.5) * data.kit.invwidth)) * data.kit.angle;
			data.dir[x][y] = Vector(x_, y_, 1);
			// rotate_direction(data.dir[x][y]);
		}		
	}
	
	// for(int i = 0; i < WIN_HIGHT; i++)
	// 	for(int j = 0; j < WIN_WIDTH; j++)
			
	
}

void draw(Data &data)
{
	
}

void key_press(sf::RenderWindow *window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window->close();
}

int main() {
	// Create a window
	sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HIGHT), "raytracing");
	window.setKeyRepeatEnabled(false);
    sf::Texture texture;
    texture.create(WIN_WIDTH, WIN_HIGHT);
    
	Data dt;
    // Color some pixels
    dt.pixels = new sf::Uint8[WIN_WIDTH * WIN_HIGHT * 4]; // pixels for an 800x600 image, with 4 components per pixel (RGBA)
    // for (int i = 0; i < WIN_WIDTH*WIN_HIGHT*4; i += 4)
    // {
    //     dt.pixels[i] = 255;     // Red component
    //     dt.pixels[i+1] = i%255;     // Green component
    //     dt.pixels[i+2] = 0;     // Blue component
    //     dt.pixels[i+3] = 255;   // Alpha (transparency) component 
    // }
  
    // Create texture and sprite for displaying the pixels
	init_data(dt);
	hardcoded_data(dt);
	add_tri(dt);
	// raytracing_loop;
	std::cout << "triangle = " << dt.triangles.size() << std::endl;
	std::cout << "triangle is " << dt.triangles[0] << std::endl;
	for (int i = 0; i < WIN_HIGHT; ++i)
	{
		for (int j = 0; j < WIN_WIDTH; ++j)
		{
			std::cout << i << " " << j << " " << WIN_WIDTH << " " << WIN_HIGHT << std::endl;
			Vector color = trace_tri(dt.dir[i][j],  dt);
			// Vector color(std::rand() % 256, std::rand() % 256, std::rand() % 256); 
			dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 0] = (char)color.x;
			dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 1] = (char)color.y;
			dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 2] = (char)color.z;
			std::cout << (int)dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 0] << " " << (int)dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 1] << " " << (int)dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 2] << std::endl;
		}
	}
	std::cout << "output is ready";
    texture.update(dt.pixels);
    sf::Sprite sprite(texture);
	// Main loop
	while (window.isOpen()) {
		// Event processing
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				key_press(&window);
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}
		// Clear window
		window.clear();		
		window.draw(sprite);
		// Show what was drawn
		window.display();
	}
	delete[] dt.pixels;

	return 0;
}


// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//     sf::CircleShape shape(100.f);
//     shape.setFillColor(sf::Color::Green);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         window.draw(shape);
//         window.display();
//     }

//     return 0;
// }
