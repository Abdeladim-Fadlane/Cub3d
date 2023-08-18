/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:58:56 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/07/09 15:06:39 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_parc.h"

int	skep_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

int	skep_space2(char *str, int i)
{
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t') && ft_isdigit(str[i + 1]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_number_in_f_c(char *str)
{
	int	i;

	i = skep_space(str);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 && skep_space2(str, i) == 1)
			(write(2, "EROOR! : invalide (F or C)!", 28), exit(1));
		i++;
	}
}
