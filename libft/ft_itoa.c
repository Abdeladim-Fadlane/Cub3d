/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:38:17 by mmajdoub          #+#    #+#             */
/*   Updated: 2022/11/02 15:34:47 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		n *= (-1);
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int m)
{
	int			l;
	long long	n;
	char		*s;

	n = m;
	l = ft_len(n);
	s = (char *)malloc(sizeof(char) *(l + 1));
	if (!s)
		return (NULL);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = n * -1;
	}
	s[l] = '\0';
	l--;
	while (n > 0)
	{
		s[l] = n % 10 + '0';
		n = n / 10;
		l--;
	}
	return (s);
}
