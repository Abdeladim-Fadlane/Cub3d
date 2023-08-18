/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:48:25 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/08/10 16:42:21 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	__main__(t_test *test)
{
	test->img = malloc(sizeof(t_img));
	player_direction(test->prc, test);
	test->mlx = mlx_init();
	test->win = mlx_new_window(test->mlx, WINDOW, WINDOW, "CUB_3D");
	test->img->ptr = mlx_new_image(test->mlx, WINDOW, WINDOW);
	test->img->addr = mlx_get_data_addr(test->img->ptr,
			&test->img->bits_per_pixel, &test->img->line_length,
			&test->img->endian);
	init_var(test, test->prc);
	img_init(test);
	render_map(test);
	mlx_hook(test->win, 17, 1L << 0, ft_exit, NULL);
	mlx_hook(test->win, 2, 1L << 0, presse_key, test);
	mlx_hook(test->win, 3, 1L << 1, relesse_key, test);
	mlx_loop_hook(test->mlx, motion, test);
	mlx_loop(test->mlx);
}

/////////////////////This is the way!!

int	main(int ac, char **av)
{
	int		fd;
	t_test	*m;

	m = malloc(sizeof(t_test));
	m->prc = malloc(sizeof(t_parc));
	if (ac != 2)
		(write(2, "EROOR! : number of argement!", 28), exit(1));
	ft_open_fd(av[1], &fd);
	ft_check_map_infd(fd, m->prc);
	__main__(m);
}
