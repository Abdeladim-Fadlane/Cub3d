/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:05:40 by afadlane          #+#    #+#             */
/*   Updated: 2023/08/03 14:08:21 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

/////THIS IS YOUUR FUNCTION /////////
void	texture(t_test *test,t_ray ray, double wall, double floor, int x)
{
	int	y;
	y = floor;
	// X : RAY.X    //the intersection coordinate x;
	// X : RAY.Y    //the intersection coordinate y;
	// LENGHT OF RAY : WALL ;
	while (y <= wall + floor)
	{
		if (ray.dir == 'E')
			my_mlx_put(test->img, x, y, 6451);
		if (ray.dir == 'N')
			my_mlx_put(test->img, x, y, 0X067463);
		if (ray.dir == 'W')
			my_mlx_put(test->img, x, y, 0X6366f4);
		if (ray.dir == 'S')
			my_mlx_put(test->img, x, y, 0x00cccc);
		y++;
	}
}
/////THIS IS YOUUR FUNCTION /////////