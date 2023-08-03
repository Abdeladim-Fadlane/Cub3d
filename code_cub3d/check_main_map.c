/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:52:32 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/07/09 15:08:41 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	check_isolated_zero(char **ptr, int i)
{
	int	j;
	int	x;
	int	y;

	j = 0;
	x = ft_strlen2(ptr[i - 1]);
	y = ft_strlen2(ptr[i + 1]);
	while (ptr[i][j])
	{
		if (ptr[i][j] == '0' && (j > x || j > y))
			(write(2, "EROOR! : isolated zero!", 23), exit(1));
		j++;
	}
}

int	check_and_count_player(char **ptr, int i)
{
	int	j;

	j = ft_check_space_tab(ptr[i]);
	while (ptr[i][j])
	{
		if (ptr[i][j] == 'N')
			return (1);
		else if (ptr[i][j] == 'S')
			return (1);
		else if (ptr[i][j] == 'W')
			return (1);
		else if (ptr[i][j] == 'E')
			return (1);
		j++;
	}
	return (0);
}

int	check_med_map(char **ptr, int i, t_parc *m)
{
	int	x;

	x = 0;
	if (ptr[i + 1])
	{
		while (ptr[i + 1])
		{
			check_isolated_zero(ptr, i);
			check_med_lines(ptr, i);
			if (check_and_count_player(ptr, i) == 1)
				x++;
			stock_player_in_struct(ptr, i, m);
			check_med_wall(ptr, i);
			i++;
		}
	}
	if (x != 1)
		(write(2, "EROOR! : invalid number of player!", 35), exit(1));
	return (i);
}

void	check_med_lines(char **ptr, int i)
{
	int	j;

	j = ft_check_space_tab(ptr[i]);
	while (ptr[i][j])
	{
		if (ptr[i][j] != '1' && ptr[i][j] != ' ' && ptr[i][j] != '0'
			&& ptr[i][j] != 'W' && ptr[i][j] != 'N' && ptr[i][j] != 'S'
			&& ptr[i][j] != 'E')
			(write(2, "EROOR! : invalid Letter!", 24), exit(1));
		if (((ptr[i][j] == '0' || ptr[i][j] == 'W' || ptr[i][j] == 'N'
					|| ptr[i][j] == 'S' || ptr[i][j] == 'E') && ptr[i][j
				+ 1] == ' ') || (ptr[i][j] == ' ' && (ptr[i][j + 1] == '0'
					|| ptr[i][j + 1] == 'W' || ptr[i][j + 1] == 'N' || ptr[i][j
					+ 1] == 'S' || ptr[i][j + 1] == 'E')))
			(write(2, "EROOR! : invalid map V!", 23), exit(1));
		if (((ptr[i][j] == '0' || ptr[i][j] == 'W' || ptr[i][j] == 'N'
					|| ptr[i][j] == 'S' || ptr[i][j] == 'E') && ptr[i
				+ 1][j] == ' ') || (ptr[i][j] == ' ' && (j < ft_strlen2(ptr[i
						+ 1]) && (ptr[i + 1][j] == '0' || ptr[i + 1][j] == 'W'
						|| ptr[i + 1][j] == 'N' || ptr[i + 1][j] == 'S' || ptr[i
						+ 1][j] == 'E'))))
			(write(2, "EROOR! : invalid map H!", 23), exit(1));
		j++;
	}
}

int	ft_check_space_tab(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] && ptr[i] != '1')
	{
		if (ptr[i] == ' ' || ptr[i] == '\t')
			i++;
		if (ptr[i] != '1' && ptr[i] != ' ' && ptr[i] != '\t')
			(write(2, "EROOR! : invalid left wall!", 27), exit(1));
	}
	if (i == ft_strlen2(ptr))
		(write(2, "EROOR! : empty line!", 20), exit(1));
	return (i);
}
