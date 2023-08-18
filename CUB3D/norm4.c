/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:58:33 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/07/09 15:08:20 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

void	stock_player_in_struct(char **ptr, int i, t_parc *m)
{
	int	j;

	j = ft_check_space_tab(ptr[i]);
	while (ptr[i][j])
	{
		if (ptr[i][j] == 'N')
			m->player = 'n';
		else if (ptr[i][j] == 'S')
			m->player = 's';
		else if (ptr[i][j] == 'W')
			m->player = 'w';
		else if (ptr[i][j] == 'E')
			m->player = 'e';
		j++;
	}
}
