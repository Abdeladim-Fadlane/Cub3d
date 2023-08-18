/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:22:28 by afadlane          #+#    #+#             */
/*   Updated: 2023/08/03 15:56:19 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

int	my_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	get_lenght(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	bosol(int c)
{
	return (c == 'W' || c == 'N' || c == 'E' || c == 'S');
}

int	ft_exit(void)
{
	write(1, "YOU ARE EXIT FROM CUB\n", 22);
	exit(1);
}
