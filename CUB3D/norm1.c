/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:08:19 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/07/09 13:33:52 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	ft_stock_f_c_in_struct(char c, char **str, t_parc *m)
{
	if (c == 'F')
		m->f = (ft_atoi(str[0]) * 65536) + (ft_atoi(str[1]) * 256)
			+ ft_atoi(str[2]);
	else
		m->c = (ft_atoi(str[0]) * 65536) + (ft_atoi(str[1]) * 256)
			+ ft_atoi(str[2]);
}

void	ft_check_newline(char *map_read)
{
	int	i;

	i = find_map(map_read);
	if (i == -1)
		(write(2, "ERROR! : empty map!", 19), exit(1));
	while (map_read[i])
	{
		if (map_read[i] == '\n' && map_read[i + 1] == '\n')
			(write(2, "ERROR! : new line inside the map!", 33),
				exit(1));
		i++;
	}
}

void	ft_check_main_map_helper(char **ptr, int i, t_parc *m)
{
	check_first_line(ptr, i);
	i++;
	i = check_med_map(ptr, i, m);
	check_last_line(ptr, i);
}

void	check_last_line(char **ptr, int i)
{
	int	j;

	j = 0;
	ft_check_space_tab(ptr[i]);
	while (ptr[i][j])
	{
		if (ptr[i][j] != ' ' && ptr[i][j] != '\t' && ptr[i][j] != '1')
			(write(2, "EROOR! : invalid last line!", 27), exit(1));
		j++;
	}
}

void	check_first_line(char **ptr, int i)
{
	int	j;

	j = 0;
	ft_check_space_tab(ptr[i]);
	while (ptr[i][j])
	{
		if (ptr[i][j] != ' ' && ptr[i][j] != '\t' && ptr[i][j] != '1')
			(write(2, "EROOR! : invalid first line!", 28), exit(1));
		if (ptr[i][j] == ' ' && ptr[i + 1][j] == '0')
			(write(2, "EROOR! : space in  first line and zero in second line!",
					54), exit(1));
		j++;
	}
}
