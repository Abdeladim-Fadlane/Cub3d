/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inisiall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:22:26 by afadlane          #+#    #+#             */
/*   Updated: 2023/08/03 15:22:59 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	init_var(t_test *test, t_parc *m)
{
	test->sky = m->c;
	test->floor = m->f;
	test->inter_y = 0;
	test->inter_x = 0;
	test->m_r = 0;
	test->m_l = 0;
	test->m_u = 0;
	test->m_d = 0;
	test->rot_rhit = 0;
	test->rot_left = 0;
	test->map = m->map;
	test->win_h = get_lenght(m->map);
	get_position(test);
}

int	check_wall(int x, int y, t_test *t)
{
	int	size_array;

	size_array = t->win_h - 1;
	if (y / SIZE < 0 || y / SIZE > size_array)
		return (0);
	if (x / SIZE < 0 || x / SIZE > my_strlen(t->map[y / SIZE]) - 1)
		return (0);
	if (t->map[y / SIZE][x / SIZE] == '1')
		return (0);
	return (1);
}

void	player_direction(t_parc *m, t_test *test)
{
	if (m->player == 'n')
		test->teta = 90;
	if (m->player == 's')
		test->teta = 270;
	if (m->player == 'e')
		test->teta = 0;
	if (m->player == 'w')
		test->teta = 180;
}

void	get_position(t_test *t)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (t->map[y])
	{
		x = 0;
		while (t->map[y][x])
		{
			if (bosol(t->map[y][x]) == 1)
			{
				t->x = x * SIZE + 41;
				t->y = y * SIZE + 41;
			}
			x++;
		}
		y++;
	}
}
