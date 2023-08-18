/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:57:01 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/08/10 17:05:15 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	ft_put_image_to_window_e(double wall, t_test *test, double floor,
		t_ray ray)
{
	double	y;
	float	h;
	float	w;

	h = 0;
	w = 0;
	y = floor;
	if (wall >= WINDOW)
	{
		h = (test->ptr[3].height / wall) * ((wall - WINDOW) / 2);
		y = 0;
	}
	w = (int)(test->ptr[3].width * ray.y / SIZE) % (test->ptr[3].width);
	while (y <= wall + floor)
	{
		my_mlx_put(test->img, test->xi, y++,
			ft_get_color_from_img(test, w, h, 3));
		h += test->ptr[3].height / wall;
	}
}

void	ft_put_image_to_window_n(double wall, t_test *test, double floor,
		t_ray ray)
{
	double	y;
	float	h;
	float	w;

	h = 0;
	w = 0;
	y = floor;
	if (wall >= WINDOW)
	{
		h = test->ptr[0].height / wall * (wall - WINDOW) / 2;
		y = 0;
	}
	w = (int)(test->ptr[0].width * ray.x / SIZE) % test->ptr[0].width;
	while (y <= wall + floor)
	{
		my_mlx_put(test->img, test->xi, y++,
			ft_get_color_from_img(test, w, h, 0));
		h += test->ptr[0].height / wall;
	}
}

void	ft_put_image_to_window_s(double wall, t_test *test, double floor,
		t_ray ray)
{
	double	y;
	float	h;
	float	w;

	h = 0;
	w = 0;
	y = floor;
	if (wall >= WINDOW)
	{
		h = (test->ptr[1].height / wall) * ((wall - WINDOW) / 2);
		y = 0;
	}
	w = (int)(test->ptr[1].width * ray.x / SIZE) % test->ptr[1].width;
	while (y <= wall + floor)
	{
		my_mlx_put(test->img, test->xi, y++,
			ft_get_color_from_img(test, w, h, 1));
		h += test->ptr[1].height / wall;
	}
}

void	ft_put_image_to_window_w(double wall, t_test *test, double floor,
		t_ray ray)
{
	double	y;
	float	h;
	float	w;

	h = 0;
	w = 0;
	y = floor;
	if (wall >= WINDOW)
	{
		h = (test->ptr[2].height / wall) * ((wall - WINDOW) / 2);
		y = 0;
	}
	w = (int)(test->ptr[2].width * ray.y / SIZE) % test->ptr[2].width;
	while (y <= wall + floor)
	{
		my_mlx_put(test->img, test->xi, y++,
			ft_get_color_from_img(test, w, h, 2));
		h += test->ptr[2].height / wall;
	}
}
