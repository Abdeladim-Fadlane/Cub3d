/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastin_vertical.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:51:39 by afadlane          #+#    #+#             */
/*   Updated: 2023/08/03 15:54:33 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

t_ray	inis_struct2(t_ray ray, t_test *t)
{
	ray.x = t->inter_v_x;
	ray.y = t->inter_v_y;
	ray.length_ray = t->v_ray;
	return (ray);
}

void	cos_positive(t_ray ray, t_test *t, double teta_rad)
{
	ray.dy = ray.dx * tan(teta_rad);
	t->inter_v_y = t->y - ray.dy;
	t->inter_v_x = t->x + ray.dx;
	t->v_ray = sqrt(pow((t->x - t->inter_v_x), 2) + pow((t->y - t->inter_v_y),
				2));
}

void	cos_negative(t_ray ray, t_test *t, double teta_rad)
{
	t->k = SIZE;
	ray.dy = ray.dx * tan(teta_rad);
	t->inter_v_y = t->y + ray.dy;
	t->inter_v_x = t->x - ray.dx;
	t->v_ray = sqrt(pow((t->x - t->inter_v_x), 2) + pow((t->y - t->inter_v_y),
				2));
}

t_ray	intresection_vertical(t_test *t, double teta_rad)
{
	t_ray	ray;

	t->k = 0;
	ray.dx = fmod(t->x, SIZE);
	if (cos(teta_rad) > 0)
		ray.dx = SIZE - fmod(t->x, SIZE);
	while (1337)
	{
		if (cos(teta_rad) >= 0)
		{
			ray.dir = 'E';
			cos_positive(ray, t, teta_rad);
		}
		else if (cos(teta_rad) <= 0)
		{
			ray.dir = 'W';
			cos_negative(ray, t, teta_rad);
		}
		if (check_wall(t->inter_v_x - t->k, t->inter_v_y, t) == 0)
			break ;
		ray.dx += SIZE;
	}
	return (inis_struct2(ray, t));
}
