/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:48:25 by afadlane          #+#    #+#             */
/*   Updated: 2023/08/03 13:40:48 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

int	relesse_key(int key, t_test *test)
{
	if (key == 123)
		test->rot_rhit = 0;
	if (key == 124)
		test->rot_left = 0;
	if (key == 126 || key == 13)
		test->m_u = 0;
	if (key == 125 || key == 1)
		test->m_d = 0;
	if (key == 0)
		test->m_r = 0;
	if (key == 2)
		test->m_l = 0;
	return (0);
}

int	presse_key(int key, t_test *test)
{
	if (key == 123)
		test->rot_rhit = 1;
	if (key == 124)
		test->rot_left = 1;
	if (key == 53)
		ft_exit();
	if (key == 126 || key == 13)
		test->m_u = 1;
	if (key == 125 || key == 1)
		test->m_d = 1;
	if (key == 0)
		test->m_r = 1;
	if (key == 2)
		test->m_l = 1;
	return (0);
}

int	motion(t_test *test)
{
	move_right(test);
	move_left(test);
	move_up(test);
	move_down(test);
	rotation(test);
	render_map(test);
	return (0);
}

void	rotation(t_test *test)
{
	if (test->rot_left == 1)
		test->teta += ROTATION;
	if (test->rot_rhit == 1)
		test->teta -= ROTATION;
}
