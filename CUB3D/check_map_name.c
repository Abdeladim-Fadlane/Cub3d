/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:48:29 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/07/09 12:46:09 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	ft_check_inp(char *s)
{
	int	i;

	i = 0;
	i = ft_strlen(s) - 4;
	if (ft_strcmp(&s[i], ".cub") == 0)
		return ;
	else
		(write(2, "EROOR! : name of map!", 21), exit(1));
}

void	ft_open_fd(char *s, int *fd)
{
	*fd = open(s, O_RDONLY);
	if (*fd == -1)
	{
		perror("ERROR");
		exit(1);
	}
	ft_check_inp(s);
}

void	check_med_wall(char **ptr, int i)
{
	while (ptr[i])
	{
		if (check_med_wall_helper(ptr[i]) == 1)
			i++;
		else
			(write(2, "EROOR! : invalid right wall!", 28), exit(1));
	}
}

int	check_med_wall_helper(char *ptr)
{
	int	i;

	i = 0;
	i = ft_check_space_tab(ptr);
	while (ptr[i])
	{
		if (ft_strrchr(ptr) != 0)
			return (1);
		i++;
	}
	return (0);
}
