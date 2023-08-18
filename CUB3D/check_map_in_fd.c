/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_in_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:08:37 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/07/09 15:10:57 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

char	**get_texture_path(char *ptr)
{
	char	**str;

	str = ft_split(ptr, ' ');
	if (ft_len_double_pointer(str) != 2)
		(write(2, "EROOR! : more  than one derection of texture!", 46),
			exit(1));
	return (str);
}

void	ft_stock_texture_d_in_struct(char *ptr, int i, t_parc *m)
{
	char	**str;

	if (ptr[i] == 'N' && ptr[i + 1] == 'O')
	{
		str = get_texture_path(&ptr[i]);
		m->no = ft_strdup(str[1]);
	}
	else if (ptr[i] == 'S' && ptr[i + 1] == 'O')
	{
		str = get_texture_path(&ptr[i]);
		m->so = ft_strdup(str[1]);
	}
	else if (ptr[i] == 'W' && ptr[i + 1] == 'E')
	{
		str = get_texture_path(&ptr[i]);
		m->we = ft_strdup(str[1]);
	}
	else if (ptr[i] == 'E' && ptr[i + 1] == 'A')
	{
		str = get_texture_path(&ptr[i]);
		m->ea = ft_strdup(str[1]);
	}
	else
		return ;
	ft_free(str);
}

int	ft_check_direction_helper(char *ptr, t_parc *m)
{
	int		i;
	char	**str;

	(void)m;
	i = 0;
	while (ptr[i])
	{
		if ((ptr[i] == 'N' && ptr[i + 1] == 'O') || (ptr[i] == 'S'
				&& ptr[i + 1] == 'O') || (ptr[i] == 'W' && ptr[i + 1] == 'E')
			|| (ptr[i] == 'E' && ptr[i + 1] == 'A'))
		{
			ft_check_path_direction(ptr, i);
			ft_stock_texture_d_in_struct(ptr, i, m);
			return (0);
		}
		if (ptr[i] == 'F' || ptr[i] == 'C')
		{
			str = ft_check_f_c(ptr, i);
			ft_stock_f_c_in_struct(ptr[i], str, m);
			ft_free(str);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_check_path_direction(char *ptr, int i)
{
	int	fd;

	while (ptr[i])
	{
		if (ptr[i] == '.' && ptr[i + 1] == '/')
		{
			fd = open(&ptr[i], O_RDWR);
			if (fd == -1)
			{
				perror("ERROR");
				exit(1);
			}
		}
		i++;
	}
}
