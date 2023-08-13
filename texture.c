/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:05:40 by afadlane          #+#    #+#             */
/*   Updated: 2023/08/10 17:49:49 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	img_init(t_test *ptr_win)
{
	ptr_win->ptr[0].img_ptr = mlx_xpm_file_to_image(ptr_win->mlx,
			ptr_win->prc->no, &ptr_win->ptr[0].width, &ptr_win->ptr[0].height);
	ptr_win->ptr[0].imge_data = mlx_get_data_addr(ptr_win->ptr[0].img_ptr,
													&ptr_win->ptr[0].bits_per_pixel,
													&ptr_win->ptr[0].size_line,
													&ptr_win->ptr[0].endian);
	ptr_win->ptr[1].img_ptr = mlx_xpm_file_to_image(ptr_win->mlx,
			ptr_win->prc->so, &ptr_win->ptr[1].width, &ptr_win->ptr[1].height);
	ptr_win->ptr[1].imge_data = mlx_get_data_addr(ptr_win->ptr[1].img_ptr,
													&ptr_win->ptr[1].bits_per_pixel,
													&ptr_win->ptr[1].size_line,
													&ptr_win->ptr[1].endian);
	ptr_win->ptr[2].img_ptr = mlx_xpm_file_to_image(ptr_win->mlx,
			ptr_win->prc->we, &ptr_win->ptr[2].width, &ptr_win->ptr[2].height);
	ptr_win->ptr[2].imge_data = mlx_get_data_addr(ptr_win->ptr[2].img_ptr,
													&ptr_win->ptr[2].bits_per_pixel,
													&ptr_win->ptr[2].size_line,
													&ptr_win->ptr[2].endian);
	ptr_win->ptr[3].img_ptr = mlx_xpm_file_to_image(ptr_win->mlx,
			ptr_win->prc->ea, &ptr_win->ptr[3].width, &ptr_win->ptr[3].height);
	ptr_win->ptr[3].imge_data = mlx_get_data_addr(ptr_win->ptr[3].img_ptr,
													&ptr_win->ptr[3].bits_per_pixel,
													&ptr_win->ptr[3].size_line,
													&ptr_win->ptr[3].endian);
}

int	ft_get_color_from_img(t_test *t, int x, int y, int i)
{
	char	*dst;
	int		color;

	if (x < 0 || x >= t->ptr[i].width || y < 0 || y >= t->ptr[i].height)
		return (0);
	dst = t->ptr[i].imge_data + (y * t->ptr[i].size_line + x
			* (t->ptr[i].bits_per_pixel / 8));
	// printf("x %d >>>.. y %d\n", x, y);
	color = *(unsigned int *)dst;
	return (color);
}

/////THIS IS YOUUR FUNCTION /////////
void	texture(t_test *test, t_ray ray, double wall, double floor, int x)
{
	int	y;
    float   h = 0;
    float  w = 0;
	y = floor;
	if (ray.dir == 'E')//y
	{
        if(wall >= WINDOW)
		{
			h = (test->ptr[3].height/wall) * ((wall - WINDOW) / 2);
			y = 0;
		}  
        w = (int)(test->ptr[3].width * ray.y/SIZE) % (test->ptr[3].width);
		while (y <= wall + floor && y < WINDOW)
		{
			// printf("%d\n", (int )y);
			my_mlx_put(test->img, x, y++, ft_get_color_from_img(test, w, h, 3));
			h += test->ptr[3].height / wall;
		}
	}
	if (ray.dir == 'N')
	{
        if(wall >= WINDOW)
		{
			h = test->ptr[0].height/wall * (wall - WINDOW) / 2;
			y = 0;
		}    
        w = (int)(test->ptr[0].width * ray.x/SIZE) % test->ptr[0].width;
		while (y <= wall + floor   && y < WINDOW)
		{
			// printf("%d\n", (int )y);
			my_mlx_put(test->img, x, y++, ft_get_color_from_img(test, w, h, 0));
			h += test->ptr[0].height / wall;
		}
	}
	if (ray.dir == 'W')//y
	{
        if(wall >= WINDOW)
		{
            h = (test->ptr[2].height/wall) * ((wall - WINDOW) / 2);
			y = 0;
		}
        w = (int)(test->ptr[2].width * ray.y/SIZE) % test->ptr[2].width;
		while (y <= wall + floor && y < WINDOW )
		{
			// printf("%d\n", (int )y);
			my_mlx_put(test->img, x, y++, ft_get_color_from_img(test, w, h, 2));
			h += test->ptr[2].height / wall;
		}
	}
	if (ray.dir == 'S')
	{
        if(wall >= WINDOW)
		{
            h = (test->ptr[1].height/wall) * ((wall - WINDOW) / 2);
			y = 0;
		}
        w = (int)(test->ptr[1].width * ray.x/SIZE) % test->ptr[1].width;
		while (y <= wall + floor  && y < WINDOW)
		{
			// printf("%d\n", (int )y);
			my_mlx_put(test->img, x, y++, ft_get_color_from_img(test, w, h, 1));
			h += test->ptr[1].height / wall;
		}
	}
}
/////THIS IS YOUUR FUNCTION /////////