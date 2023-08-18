/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:17:03 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/07/09 15:07:39 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	ft_str_is_digit(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ft_isdigit2(ptr[i]) == 0)
			(write(2, "EROOR! : no digit in (F or C)!", 30), exit(1));
		i++;
	}
}

void	ft_check_direction(char **spltmap, t_parc *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (spltmap[i])
	{
		if (ft_check_direction_helper(spltmap[i], m) == 0)
			j++;
		i++;
	}
	if (j != 6)
		(write(2, "EROOR! : few direction or more!", 31), exit(1));
}

int	ft_len_double_pointer(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

void	ft_check_comma(char *ptr, int i)
{
	int	x;

	x = 0;
	while (ptr[i])
	{
		if (ptr[i] == ',')
			x++;
		i++;
	}
	if (x > 2)
		(write(2, "EROOR! : more than 2 comma in (F or C)!", 39), exit(1));
}

char	**ft_check_f_c(char *ptr, int i)
{
	char	**str;

	str = NULL;
	i++;
	ft_check_comma(ptr, i);
	while (ptr[i] && ft_isdigit(ptr[i]) == 0)
		i++;
	if (i == ft_strlen2(ptr))
		(write(2, "EROOR! : no arg (F or C)!", 25), exit(1));
	str = ft_split(&ptr[i], ',');
	if (ft_len_double_pointer(str) != 3)
		(write(2, "EROOR! : few arg (F or C) or more!", 34), exit(1));
	ft_check_f_c_helper(str);
	return (str);
}
