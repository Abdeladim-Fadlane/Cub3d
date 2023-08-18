/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:27:22 by mmajdoub          #+#    #+#             */
/*   Updated: 2022/10/28 09:26:40 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int x, size_t len)
{
	size_t			i;
	unsigned char	*k;
	unsigned char	c;

	i = 0;
	k = (unsigned char *)str;
	c = (unsigned char)x;
	while (len > 0)
	{
		k[i] = c;
		i++;
		len--;
	}
	return (k);
}
