/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:24:41 by mmajdoub          #+#    #+#             */
/*   Updated: 2022/11/02 15:34:28 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	if (!src && !dst)
		return (NULL);
	if (dst == src)
		return (dst);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n > i)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
