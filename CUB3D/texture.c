/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:05:40 by afadlane          #+#    #+#             */
/*   Updated: 2023/08/10 17:15:54 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	img_init_helper(t_test *ptr_win)
{
	ptr_win->ptr[2].img_ptr = mlx_xpm_file_to_image(ptr_win->mlx,
			ptr_win->prc->we,
			&ptr_win->ptr[2].width,
			&ptr_win->ptr[2].height);
	if (!ptr_win->ptr[2].img_ptr)
		(write(2, "EROOR! : invalide path!", 24), exit(1));
	ptr_win->ptr[2].imge_data = mlx_get_data_addr(ptr_win->ptr[2].img_ptr,
			&ptr_win->ptr[2].bits_per_pixel,
			&ptr_win->ptr[2].size_line,
			&ptr_win->ptr[2].endian);
	ptr_win->ptr[3].img_ptr = mlx_xpm_file_to_image(ptr_win->mlx,
			ptr_win->prc->ea,
			&ptr_win->ptr[3].width,
			&ptr_win->ptr[3].height);
	if (!ptr_win->ptr[3].img_ptr)
		(write(2, "EROOR! : invalide path!", 24), exit(1));
	ptr_win->ptr[3].imge_data = mlx_get_data_addr(ptr_win->ptr[3].img_ptr,
			&ptr_win->ptr[3].bits_per_pixel,
			&ptr_win->ptr[3].size_line,
			&ptr_win->ptr[3].endian);
}

void	img_init(t_test *ptr_win)
{
	ptr_win->ptr[0].img_ptr = mlx_xpm_file_to_image(ptr_win->mlx,
			ptr_win->prc->no,
			&ptr_win->ptr[0].width,
			&ptr_win->ptr[0].height);
	if (!ptr_win->ptr[0].img_ptr)
		(write(2, "EROOR! : invalide path!", 24), exit(1));
	ptr_win->ptr[0].imge_data = mlx_get_data_addr(ptr_win->ptr[0].img_ptr,
			&ptr_win->ptr[0].bits_per_pixel,
			&ptr_win->ptr[0].size_line,
			&ptr_win->ptr[0].endian);
	ptr_win->ptr[1].img_ptr = mlx_xpm_file_to_image(ptr_win->mlx,
			ptr_win->prc->so,
			&ptr_win->ptr[1].width,
			&ptr_win->ptr[1].height);
	if (!ptr_win->ptr[1].img_ptr)
		(write(2, "EROOR! : invalide path!", 24), exit(1));
	ptr_win->ptr[1].imge_data = mlx_get_data_addr(ptr_win->ptr[1].img_ptr,
			&ptr_win->ptr[1].bits_per_pixel,
			&ptr_win->ptr[1].size_line,
			&ptr_win->ptr[1].endian);
	img_init_helper(ptr_win);
}

int	ft_get_color_from_img(t_test *t, int x, int y, int i)
{
	char	*dst;
	int		color;

	if (x < 0 || x >= t->ptr[i].width || y < 0 || y >= t->ptr[i].height)
		return (0);
	dst = t->ptr[i].imge_data + (y * t->ptr[i].size_line + x
			* (t->ptr[i].bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	texture(t_test *test, t_ray ray, double wall, double floor)
{
	if (ray.dir == 'E')
		ft_put_image_to_window_e(wall, test, floor, ray);
	if (ray.dir == 'N')
		ft_put_image_to_window_n(wall, test, floor, ray);
	if (ray.dir == 'W')
		ft_put_image_to_window_w(wall, test, floor, ray);
	if (ray.dir == 'S')
		ft_put_image_to_window_s(wall, test, floor, ray);
}
