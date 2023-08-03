/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:15:02 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/07/09 14:59:16 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	ft_check_f_c_helper(char **str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		ft_str_is_digit(str[i]);
		ft_check_number_in_f_c(str[i]);
		x = ft_atoi(str[i]);
		if (x < 0 || x > 255)
			(write(2, "EROOR! : range in (F or C)!", 27), exit(1));
		i++;
	}
}

char	*ft_read_fd(int fd)
{
	char	*buf;
	char	*bufjoin;
	int		i;

	i = 1;
	bufjoin = ft_strdup("");
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			free(bufjoin);
			return (NULL);
		}
		buf[i] = '\0';
		bufjoin = ft_strjoin1(bufjoin, buf);
		if (!bufjoin)
			return (NULL);
	}
	free(buf);
	return (bufjoin);
}

int	len_map(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ptr[i])
	{
		if (find_first_line(ptr[i]) == 0)
			break ;
		i++;
	}
	while (ptr[i])
	{
		i++;
		j++;
	}
	return (j);
}

void	ft_stock_map_in_struct(char **ptr, t_parc *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	m->map = malloc(sizeof(char *) * (len_map(ptr) + 1));
	while (ptr[i])
	{
		if (find_first_line(ptr[i]) == 0)
			break ;
		free(ptr[i]);
		i++;
	}
	while (ptr[i])
	{
		m->map[j] = strdup(ptr[i]);
		free(ptr[i]);
		i++;
		j++;
	}
	m->map[j] = NULL;
}

void	ft_check_map_infd(int fd, t_parc *m)
{
	char	*map_countent;
	char	**spltmap;

	map_countent = ft_read_fd(fd);
	spltmap = ft_split(map_countent, '\n');
	ft_check_direction(spltmap, m);
	ft_check_newline(map_countent);
	free(map_countent);
	ft_check_main_map(spltmap, m);
	ft_stock_map_in_struct(spltmap, m);
	free(spltmap);
}
