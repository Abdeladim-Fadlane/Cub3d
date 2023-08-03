/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:06:35 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/07/09 13:45:20 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

int	find_first_line(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '1')
			return (0);
		if (ptr[i] != '1' && ptr[i] != ' ' && ptr[i] != '\t')
			return (1);
		i++;
	}
	return (1);
}

void	ft_check_main_map(char **ptr, t_parc *m)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (find_first_line(ptr[i]) == 0)
			break ;
		i++;
	}
	if (ptr[i])
		ft_check_main_map_helper(ptr, i, m);
}

int	find_one(char *ptr, int i)
{
	while (ptr[i])
	{
		if (ptr[i] == ' ' || ptr[i] == '\t')
			i++;
		if (ptr[i] == '1')
			return (0);
		else if (ptr[i] != '1' && ptr[i] != ' ' && ptr[i] != '\t')
			return (1);
	}
	return (1);
}

int	find_map(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '\n' && find_one(ptr, i + 1) == 0)
			return (i);
		i++;
	}
	return (-1);
}
