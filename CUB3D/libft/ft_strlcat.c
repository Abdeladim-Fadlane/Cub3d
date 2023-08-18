/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:04:43 by mmajdoub          #+#    #+#             */
/*   Updated: 2022/11/02 15:58:07 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	j;

	i = 0;
	if (!dstsize && !src)
		return (0);
	if (!dstsize && !dst)
		return (ft_strlen(src));
	n = (ft_strlen(src) + ft_strlen(dst));
	j = (ft_strlen(dst));
	if (dstsize == 0 || dstsize <= j)
		return (ft_strlen(src) + dstsize);
	while (src[i] && i < dstsize - j - 1)
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (n);
}
