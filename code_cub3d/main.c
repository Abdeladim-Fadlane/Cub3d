/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:48:25 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/08/03 15:57:13 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	my_mlx_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW || y < 0 || y >= WINDOW)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	__main__(t_parc *m)
{
	t_test	*test;

	test = malloc(sizeof(t_test));
	test->img = malloc(sizeof(t_img));
	player_direction(m, test);
	test->mlx = mlx_init();
	test->win = mlx_new_window(test->mlx, WINDOW, WINDOW, "CUB_3D");
	test->img->ptr = mlx_new_image(test->mlx, WINDOW, WINDOW);
	test->img->addr = mlx_get_data_addr(test->img->ptr,
			&test->img->bits_per_pixel, &test->img->line_length,
			&test->img->endian);
	init_var(test, m);
	render_map(test);
	mlx_hook(test->win, 17, 0, ft_exit, NULL);
	mlx_hook(test->win, 2, 0, presse_key, test);
	mlx_hook(test->win, 3, 0, relesse_key, test);
	mlx_loop_hook(test->mlx, motion, test);
	mlx_loop(test->mlx);
}

/////////////////////This is the way!!

int	main(int ac, char **av)
{
	int		fd;
	t_parc	*m;

	m = malloc(sizeof(t_parc));
	if (ac != 2)
		(write(2, "EROOR! : number of argement!", 28), exit(1));
	ft_open_fd(av[1], &fd);
	ft_check_map_infd(fd, m);
	__main__(m);
}
