#include "raytracing.hpp"

bool hit_other_object(Vector hit_point, Vector light_vec, Data &data)
{
	float		temp_t;
	int			i;

	for (std::vector<Triangle>::iterator it = data.triangles.begin();
		it != data.triangles.end(); ++it)
	{
		temp_t = intersect_RayTriangle(data.cam.pos, light_vec, *it, hit_point);
		if (temp_t > 0.001 && temp_t < 1.0)
			return (1);
	}
	return (0);
}