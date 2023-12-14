#ifndef RAYTRACING_HPP
#define RAYTRACING_HPP
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include "Vector.hpp"
#include "Triangle.hpp"
#include <vector>
#include <cstdlib> // For std::rand() and std::srand()
#include <ctime> // For std::time()
#include <fstream>
#include <sstream>
#include <ostream>


#define WIN_WIDTH 700
#define WIN_HIGHT 300
// #define WIN_WIDTH 600
// #define WIN_HIGHT 400
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

struct AmbLight
{
	float	brightness;
	Vector	color;
};

struct SpotLight
{
	Vector	pos;
	float	brightness;
	Vector	color;
};

struct	Data
{
	sf::Uint8				*pixels;
	Vector					dir[WIN_WIDTH][WIN_HIGHT];
	Camera					cam;
	RayTraceKit				kit;
	AmbLight				amblight;
	SpotLight				spotlight;
	std::vector<Triangle>	triangles;
};

Vector	trace_tri(Vector &dir, Data &data);
float intersect_RayTriangle(Vector &origin, Vector &dir, Triangle &T, Vector &I);
Vector	compute_color_to_vec(
Vector &dir, Triangle *tri, Data &data, Vector hit_point);
bool hit_other_object(Vector hit_point, Vector light_vec, Data &data);
Vector	vec_to_color(Vector vec, Vector &mul);
std::vector<Triangle> readfile();
std::vector<Triangle> readstl();

#endif