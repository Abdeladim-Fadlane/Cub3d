/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_horizontal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:38:12 by afadlane          #+#    #+#             */
/*   Updated: 2023/08/03 15:53:42 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	sin_positive(t_ray ray, t_test *t, double teta_rad)
{
	t->k = SIZE;
	ray.dx = ray.dy / tan(teta_rad);
	t->inter_y = t->y - ray.dy;
	t->inter_x = t->x + ray.dx;
	t->h_ray = sqrt(pow((t->x - t->inter_x), 2) + pow((t->y - t->inter_y), 2));
}

void	sin_negative(t_ray ray, t_test *t, double teta_rad)
{
	ray.dx = ray.dy / tan(teta_rad);
	t->inter_y = t->y + ray.dy;
	t->inter_x = t->x - ray.dx;
	t->h_ray = sqrt(pow((t->x - t->inter_x), 2) + pow((t->y - t->inter_y), 2));
}

t_ray	inis_struct(t_ray ray, t_test *t)
{
	ray.x = t->inter_x;
	ray.y = t->inter_y;
	ray.length_ray = t->h_ray;
	return (ray);
}

t_ray	intresection_horizontal(t_test *t, double teta_rad)
{
	t_ray	ray;

	t->k = 0;
	ray.dy = fmod(t->y, SIZE);
	if (sin(teta_rad) < 0)
		ray.dy = SIZE - fmod(t->y, SIZE);
	while (1337)
	{
		if (sin(teta_rad) >= 0)
		{
			ray.dir = 'N';
			sin_positive(ray, t, teta_rad);
		}
		else if (sin(teta_rad) <= 0)
		{
			ray.dir = 'S';
			sin_negative(ray, t, teta_rad);
		}
		if (check_wall(t->inter_x, t->inter_y - t->k, t) == 0)
			break ;
		ray.dy += SIZE;
	}
	return (inis_struct(ray, t));
}
