/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajdoub <mmajdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:49:33 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/07/09 11:32:14 by mmajdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt(const char *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			cont++;
			i++;
		}
		else
			i++;
	}
	return (cont);
}

static int	ft(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			j++;
		else
			return (j);
		i++;
	}
	return (j);
}

char	**ft_free(char **k)
{
	int	i;

	i = 0;
	while (k[i])
	{
		free(k[i]);
		i++;
	}
	free(k);
	return (NULL);
}

static int	ft_skiip(int n, char const *s, int i, char c)
{
	if (n == 1)
	{
		while (s[i] == c)
			i++;
	}
	if (n == 2)
	{
		while (s[i] != c && s[i])
			i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**sk;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	sk = (char **)malloc(sizeof(char *) * (ft_cnt(s, c) + 1));
	if (!sk)
		return (0);
	while (s[i])
	{
		i = ft_skiip(1, s, i, c);
		if (s[i] == '\0')
			break ;
		sk[j] = (ft_substr(s, i, ft(&s[i], c)));
		if (sk[j] == NULL)
			return (ft_free(sk));
		i = ft_skiip(2, s, i, c);
		j++;
	}
	sk[j] = 0;
	return (sk);
}
