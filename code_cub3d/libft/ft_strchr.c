/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:56:55 by mmajdoub          #+#    #+#             */
/*   Updated: 2022/11/02 15:58:52 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*k;

	i = 0;
	k = (char *)s;
	while (i <= (int)ft_strlen(k))
	{
		if (k[i] == (char)c)
			return (&k[i]);
		else
			i++;
	}
	return (0);
}
