/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:32:02 by mmajdoub          #+#    #+#             */
/*   Updated: 2022/11/02 15:58:19 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;
	char	*s;

	i = 0;
	b = (char *)str;
	s = (char *)to_find;
	if (!b && len == 0)
		return (NULL);
	if (s[i] == '\0')
		return (b);
	while (b[i] && len > i)
	{
		j = 0;
		while (b[i] && b[i + j] == s[j] && i + j < len)
		{
			if (s[j + 1] == '\0')
				return (&b[i]);
			j++;
		}
		i++;
	}
	return (0);
}
