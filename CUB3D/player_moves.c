/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:04:45 by afadlane          #+#    #+#             */
/*   Updated: 2023/08/10 13:33:53 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	move_up(t_test *test)
{
	float	t_rad;
	t_ray	ray;
	t_ray	ray1;

	if (test->m_u == 0)
		return ;
	t_rad = M_PI * test->teta / 180;
	ray = intresection_horizontal(test, t_rad);
	ray1 = intresection_vertical(test, t_rad);
	if (ray.length_ray - ray1.length_ray > 0)
		ray = ray1;
	if (ray.length_ray < WALL_DISTANCE)
		return ;
	test->x += cos(t_rad) * SPEED;
	test->y -= sin(t_rad) * SPEED;
}

void	move_left(t_test *test)
{
	float	t_rad;
	t_ray	ray;
	t_ray	ray1;

	if (test->m_l == 0)
		return ;
	t_rad = M_PI * (test->teta + 90) / 180;
	ray = intresection_horizontal(test, t_rad);
	ray1 = intresection_vertical(test, t_rad);
	if (ray.length_ray - ray1.length_ray > 0)
		ray = ray1;
	if (ray.length_ray < WALL_DISTANCE)
		return ;
	test->x += cos(t_rad) * SPEED;
	test->y -= sin(t_rad) * SPEED;
}

void	move_right(t_test *test)
{
	float	t_rad;
	t_ray	ray;
	t_ray	ray1;

	if (test->m_r == 0)
		return ;
	t_rad = M_PI * (test->teta - 90) / 180;
	ray = intresection_horizontal(test, t_rad);
	ray1 = intresection_vertical(test, t_rad);
	if (ray.length_ray - ray1.length_ray > 0)
		ray = ray1;
	if (ray.length_ray < WALL_DISTANCE)
		return ;
	test->x += cos(t_rad) * SPEED;
	test->y -= sin(t_rad) * SPEED;
}

void	move_down(t_test *test)
{
	float	t_rad;
	t_ray	ray;
	t_ray	ray1;

	if (test->m_d == 0)
		return ;
	t_rad = M_PI * (test->teta + 180) / 180;
	ray = intresection_horizontal(test, t_rad);
	ray1 = intresection_vertical(test, t_rad);
	if (ray.length_ray - ray1.length_ray > 0)
		ray = ray1;
	if (ray.length_ray < WALL_DISTANCE)
		return ;
	test->x += cos(t_rad) * SPEED;
	test->y -= sin(t_rad) * SPEED;
}
