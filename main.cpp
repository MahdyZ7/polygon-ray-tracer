#include "raytracing.hpp"

void hardcoded_data(Data &data)
{
	std::cout << "A";
	data.cam.pos = Vector(0, 0, -10);
	data.cam.orientation =Vector(0, 0, 1);
	data.cam.fov = 60;

	data.triangles = readfile();
	
}

// std::vector<Triangle> add_tri()
// {
// 	std::vector<Triangle> triangles;
// 	Triangle T;
	
// 	T.p0 = Vector(0, 0, 0);
// 	T.p1 = Vector(0, 1, 0);
// 	T.p2 = Vector(1, 0, 0);
// 	std::cout << "triangle is " << T.p0 << " " << T.p1 << " " << T.p2 << std::endl;
// 	// triangles.push_back(T);
// 	// std::cout << "triangle is " << triangles[0].p0 << " " << triangles[0].p1 << " " << triangles[0].p2 << std::endl;
// 	std::cout << "triangle = " << triangles.size() << std::endl;
// 	return triangles;
// }

void init_data(Data &data)
{
	uint	screen_size = WIN_HIGHT * WIN_WIDTH * 4;
	for (int i = 0; i < screen_size ; i++)
		data.pixels[i] = (i%4 == 0) * 255;
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

// int main() {
// 	// Create a window
// 	sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HIGHT), "raytracing");
// 	window.setKeyRepeatEnabled(false);
//     // sf::Uint8* pixels = new sf::Uint8[WIN_WIDTH * WIN_HIGHT * 4]; // pixels for an 800x600 image, with 4 components per pixel (RGBA)
//     sf::Texture texture;
//     texture.create(WIN_WIDTH, WIN_HIGHT);
    
//     // Color some pixels
//     // for (int i = 0; i < WIN_WIDTH*WIN_HIGHT*4; i += 4)
//     // {
//     //     pixels[i] = 255;     // Red component
//     //     pixels[i+1] = i%255;     // Green component
//     //     pixels[i+2] = 0;     // Blue component
//     //     pixels[i+3] = 255;   // Alpha (transparency) component 
//     // }
  
//     // Create texture and sprite for displaying the pixels
// 	Data dt;
// 	hardcoded_data(dt);
// 	init_data(dt);
// 	// dt.triangles = add_tri();
// 	// raytracing_loop;
// 	std::cout << "triangle = " << dt.triangles.size() << std::endl;
// 	std::cout << "triangle is " << dt.triangles[0].p0 << " " << dt.triangles[0].p1 << " " << dt.triangles[0].p2 << std::endl;
// 	for (int i = 0; i < WIN_WIDTH; ++i)
// 	{
// 		for (int j = 0; j < WIN_HIGHT; ++j)
// 		{
// 			std::cout << i << " " << j << std::endl;
// 			Vector color = trace_tri(dt.dir[i][j],  dt);
// 			dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 0] = color.x;
// 			dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 1] = color.y;
// 			dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 2] = color.z;
// 		}
// 	}
// 	std::cout << "output is ready";
//     texture.update(dt.pixels);
//     sf::Sprite sprite(texture);
// 	// Main loop
// 	while (window.isOpen()) {
// 		// Event processing
// 		sf::Event event;
// 		while (window.pollEvent(event)) {
// 			if (event.type == sf::Event::Closed) {
// 				window.close();
// 			}
// 			else if (event.type == sf::Event::KeyPressed)
// 			{
// 				key_press(&window);
// 				if (event.key.code == sf::Keyboard::Escape)
// 					window.close();
// 			}
// 		}
// 		// Clear window
// 		window.clear();		
// 		window.draw(sprite);
// 		// Show what was drawn
// 		window.display();
// 	}

// 	return 0;
// }


int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // window.clear();
        window.draw(shape);
        // window.display();
    }

    return 0;
}
