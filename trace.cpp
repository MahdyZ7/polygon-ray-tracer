// #include "raytracing.hpp"

// void	basic_raytracing(t_img *img)
// {
// 	ray_trace_kit	r;

// 	init_rototion_angels_with_hooks(img->scene);
// 	printf("\nOrientation = ");
// 	vis_vector(img->scene->camera.orientation);
// 	printf("\n\n");
// 	init_ray_trace_kit(&r, img);
// 	printf("before rotaitons angels are ");
// 	vis_vector(img->scene->camera.xyz_angles);
// 	printf(" \n");
// 	trace_all_shapes(&r, img);
// }

// void	trace_all_shapes(ray_trace_kit *r, t_img *img)
// {
// 	while (r->x < WIN_WIDTH)
// 	{
// 		r->y = 0;
// 		while (r->y < WIN_HIGHT)
// 		{
// 			r->new_x = (2 * ((r->x + 0.5) * r->invwidth) - 1)
// 				* r->angle * r->aspectratio;
// 			r->new_y = (1 - 2 * ((r->y + 0.5) * r->invheight)) * r->angle;
// 			vec_init(&r->dir, r->new_x, r-> new_y, 1);
// 			r->dir = dir_with_camera_orientation(&r->dir, img->scene);
// 			r->plane_result = trace_plane(&r->dir, img->scene);
// 			r->sphere_result = trace_sphere(
// 					&r->dir, 0, img->scene);
// 			r->cylinder_result = trace_cylinder(
// 					&r->dir, 0, img->scene);
// 			r->color = pick_shape_color(r);
// 			pixel_put(img->scene->win->img, r->x, r->y, r->color);
// 			++r->y;
// 		}
// 		r->x++;
// 	}
// }

// int	pick_shape_color(ray_trace_kit *r)
// {
// 	if (r->plane_result.x < r->sphere_result.x
// 		&& r->plane_result.x < r->cylinder_result.x)
// 		r->color = r->plane_result.y;
// 	else if (r->sphere_result.x < r->plane_result.x
// 		&& r->sphere_result.x < r->cylinder_result.x)
// 		r->color = r->sphere_result.y;
// 	else
// 		r->color = r->cylinder_result.y;
// 	return (r->color);
// }

// void	init_ray_trace_kit(ray_trace_kit *r)
// {
// 	r->x = 0;
// 	r->y = 0;
// 	r->invwidth = 1 / (float)WIN_WIDTH;
// 	r->invheight = 1 / (float)WIN_HIGHT;
// 	r->aspectratio = (float)WIN_WIDTH / (float)WIN_HIGHT;
// 	r->angle = tan(M_PI * 0.5 * 60 / 180.);
// 	r->color = 0;
// 	fill_single_vector(&r->plane_result, 0, 0, 0);
// 	fill_single_vector(&r->sphere_result, 0, 0, 0);
// 	fill_single_vector(&r->cylinder_result, 0, 0, 0);
// }