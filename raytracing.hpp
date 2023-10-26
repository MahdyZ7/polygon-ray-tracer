#ifndef RAYTRACING_HPP
#define RAYTRACING_HPP
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector.hpp"
#include "Triangle.hpp"
#include <vector>
#include <cstdlib> // For std::rand() and std::srand()
#include <ctime> // For std::time()
#include <fstream>
#include <sstream>
#include <ostream>


#define WIN_WIDTH 300
#define WIN_HIGHT 100
#define SMALL_NUM 0.0001

struct	Data;

struct RayTraceKit
{
	// int		color;
	// Vector	dir;
	float	aspectratio;
	float	invwidth;
	float	invheight;
	float	angle;
	float	new_x;
	float	new_y;
	// int		x;
	// int		y;
	Vector	int_result;
};

struct Camera
{
	Vector	pos;
	Vector	orientation;
	Vector	xyz_angles;
	float	fov;
	Vector	sin_theta;
	Vector	cos_theta;
};

struct	Data
{
	sf::Uint8				*pixels;
	Vector					dir[WIN_WIDTH][WIN_HIGHT];
	Camera					cam;
	RayTraceKit				kit;
	std::vector<Triangle>	triangles;

};

Vector	trace_tri(Vector &dir, Data &data);
std::vector<Triangle> readfile();

#endif