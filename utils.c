/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:25:51 by niespana          #+#    #+#             */
/*   Updated: 2022/06/02 20:25:52 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_wordlen(char const *s, char c, int j)
{
	size_t	i;

	i = 0;
	while (s[j + i] != c && s[j + i])
		i++;
	return (i + 1);
}

size_t	ft_countwords(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		if (*s != c && *s)
		{
			i++;
			while (*(s + 1) != c && *(s + 1))
				s++;
		}
		s++;
	}
	return (i);
}

char	**ft_free_all(char **split, int start)
{
	while (start >= 0)
		free(split[start--]);
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		k;

	i = -1;
	k = 0;
	if (!s)
		return (0);
	split = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	while (s[++i])
	{
		if ((!ft_strncmp(s, &s[i], ft_strlen(s)) || s[i - 1] == c) && s[i] != c)
		{
			split[k] = malloc((ft_wordlen(s, c, i) + 1) * sizeof(char));
			if (!split[k])
				return (ft_free_all(split, k));
			ft_strlcpy(split[k++], &s[i], ft_wordlen(s, c, i));
		}
	}
	split[k] = 0;
	return (split);
}

int	ft_atoi(const char *str)
{
	int			signe;
	long		res;

	res = 0;
	signe = 1;
	while (*str != '\0')
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '-')
			signe = -1;
		if (*str == '+' || *str == '-')
			str++;
		while (ft_isdigit(*str))
		{
			res = (10 * res) + ((*str++) - 48);
			if (signe == 1 && res > 2147483647)
				return (-1);
			if (signe == -1 && res > 2147483648)
				return (0);
		}
		while (*str != '\0')
			str++;
	}
	return ((int)(res * signe));
}