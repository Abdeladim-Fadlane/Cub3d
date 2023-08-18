/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:47:17 by afadlane          #+#    #+#             */
/*   Updated: 2023/08/10 17:36:30 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	draw_wall(t_test *test, t_ray ray, double delta)
{
	double	t_rad;
	double	wall;
	double	floor;
	int		y;

	t_rad = M_PI * test->teta / 180;
	wall = LENGH_WALL / fabs(ray.length_ray * cos(t_rad - delta));
	floor = (WINDOW - wall) / 2;
	y = 0;
	while (y <= floor)
	{
		my_mlx_put(test->img, test->xi, y, test->sky);
		y++;
	}
	y = floor;
	texture(test, ray, wall, floor);
	y = floor + wall;
	while (y <= WINDOW)
	{
		my_mlx_put(test->img, test->xi, y, test->floor);
		y++;
	}
}

void	put_one_ray(double ang, t_test *test, float t_rad)
{
	t_ray	ray;
	t_ray	ray1;

	t_rad = M_PI * ang / 180;
	ray = intresection_horizontal(test, t_rad);
	ray1 = intresection_vertical(test, t_rad);
	if (ray.length_ray - ray1.length_ray > 0)
		ray = ray1;
	draw_wall(test, ray, t_rad);
}

void	put_rays(t_test *test)
{
	double	in;
	double	angle;
	float	t_rad;

	test->xi = 0;
	t_rad = 0.0;
	in = 60;
	angle = test->teta - 30;
	while (angle < test->teta + 30)
	{
		put_one_ray(angle, test, t_rad);
		angle += in / WINDOW;
		test->xi++;
	}
}

void	render_map(t_test *test)
{
	put_rays(test);
	mlx_put_image_to_window(test->mlx, test->win, test->img->ptr, 0, 0);
}
