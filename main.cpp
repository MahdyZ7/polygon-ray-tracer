#include "raytracing.hpp"

void add_tri(Data &data)
{
	Triangle T(Vector(0, -4, -10), Vector(10, -4, 10), Vector(-10, -4, 10), Vector(0,1,0));
	Triangle T1(Vector(0, -4, -10), Vector(10, -4, 10), Vector(10, -4, -10), Vector(0,1,0));
	Triangle T2(Vector(0, -4, -10), Vector(-10, -4, -10), Vector(-10, -4, 10), Vector(0,1,0));
	Triangle T3(Vector(0, 10, 10), Vector(10, -4, 10), Vector(-10, -4, 10), Vector(0,0,-1));
	Triangle T4(Vector(0, 10, 10), Vector(10, 10, 10), Vector(10, -4, 10), Vector(0,0,-1));
	Triangle T5(Vector(0, 10, 10), Vector(-10, -4, 10), Vector(-10, 10, 10), Vector(0,0,-1));
	data.triangles.push_back(T);
	data.triangles.push_back(T1);
	data.triangles.push_back(T2);
	data.triangles.push_back(T3);
	data.triangles.push_back(T4);
	data.triangles.push_back(T5);
}

void hardcoded_data(Data &data)
{
	data.amblight.brightness = 0.3;
	data.amblight.color = Vector(0.6, 0.6 , 1);
	data.spotlight.brightness = 1;
	data.spotlight.color = Vector(1, 0.5 , 0);
	data.spotlight.pos = Vector(0, 0, -10);
	data.triangles = readstl();
	add_tri(data);
	// data.triangles = readfile();
}


void init_data(Data &data)
{
	uint	screen_size = WIN_HIGHT * WIN_WIDTH * 4;
	for (int i = 0; i < screen_size ; i++)
		data.pixels[i] = (char)((i%4 == 3) * 255);
	data.cam.pos = Vector(0, 4, -10); // temp adjustment
	data.cam.orientation = Vector(0, 0, 1); // temp adjustment
	// data.cam.up(0, 1, 0); // temp adjustment
	data.cam.fov = 60.0; // temp adjustment

	data.kit.invwidth = 1.0 / (float)WIN_WIDTH;
	data.kit.invheight = 1.0 / (float)WIN_HIGHT;
	data.kit.aspectratio = (float)WIN_WIDTH / (float)WIN_HIGHT;
	data.kit.angle = tan(M_PI * 0.5 * data.cam.fov / 180.0);

	for (int x = 0; x < WIN_WIDTH; x++)
	{
		for (int y = 0; y < WIN_HIGHT; y++)
		{
			float x_ = (2 * ((x + 0.5) * data.kit.invwidth) - 1) 
				* data.kit.angle * data.kit.aspectratio;
			float y_ = (1 - 2 * ((y + 0.5) * data.kit.invheight)) * data.kit.angle;
			data.dir[x][y] = Vector(x_, y_, 1);
			// rotate_direction(data.dir[x][y]);
		}		
	}
}

void key_press(sf::RenderWindow *window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window->close();
}

void compute_pixel(int i, int j, Data dt) {
   Vector color = trace_tri(dt.dir[j][i], dt);
   dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 0] = (char)(color.x).toInt();
   dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 1] = (char)(color.y).toInt();
   dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 2] = (char)(color.z).toInt();
}


int main() {
	// Create a window
	sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HIGHT), "raytracing");
	window.setKeyRepeatEnabled(false);
	sf::Texture texture;
	texture.create(WIN_WIDTH, WIN_HIGHT);
	
	Data dt;
	// Color some pixels
	dt.pixels = new sf::Uint8[WIN_WIDTH * WIN_HIGHT * 4]; // pixels with 4 components per pixel (RGBA)

	init_data(dt);
	hardcoded_data(dt);
	// add_tri(dt);
	// raytracing_loop;
	std::cout << "triangle = " << dt.triangles.size() << std::endl;
	std::cout << "triangle is " << dt.triangles[0] << std::endl;

	for (int i = 0; i < WIN_HIGHT; ++i) {
		std::vector<std::thread> threads;
		for (int j = 0; j < WIN_WIDTH; ++j) {
			threads.push_back(std::thread(compute_pixel, i, j, std::ref(dt)));
		}
		std::cout << "line: " << i << std::endl;
		for (auto &th : threads)
			th.join();
	}


	// for (int i = 0; i < WIN_HIGHT; ++i)
	// {
	// 	for (int j = 0; j < WIN_WIDTH; ++j)
	// 	{
	// 		Vector color = trace_tri(dt.dir[j][i],  dt);
	// 		dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 0] = (char)color.x;
	// 		dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 1] = (char)color.y;
	// 		dt.pixels[i * WIN_WIDTH * 4 + j * 4 + 2] = (char)color.z;
	// 	}
	// 	std::cout << "line " << i << std::endl;
	// }
	std::cout << "output is ready" << std::endl;
	texture.update(dt.pixels);
	sf::Sprite sprite(texture);
	// Main loop
	std::cout << "output is ready" << std::endl;
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
		window.display();
	}
	delete[] dt.pixels;

	return 0;
}


