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

static int	check_max(char *s, char *max, int signe)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	if (signe)
		i++;
	if (signe)
		max[9]++;
	if (!ft_strncmp(s, max, 10))
		return (1);
	while (s && s[++i])
		if (s[i] < max[++j])
			return (1);
	return (0);
}

static int	correct_input(char *s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = -1;
	while (s && s[++i])
		if (!ft_isdigit(s[i]) && s[i] != '-')
			return (0);
	if (s && s[0] == '-')
		len--;
	if (len > 10)
		return (0);
	if (len == 10)
		return (check_max(s, "2147483647", s[0] == '-'));
	return (1);
}

static int	fill_stack(t_list **a, char **av, int i, int j)
{
	int	res;

	res = 1;
	while (av[++i])
	{
		if (!correct_input(av[i]))
		{
			res = 0;
			break ;
		}
		add_back(a, get_new(ft_atoi(av[i]), NULL));
	}
	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
	return (res);
}

t_list	*get_stack(char **av, int i, int j)
{
	t_list	*a;

	a = NULL;
	while (av[++i])
	{
		while (av[i][j])
			j++;
		if (j == 1)
		{
			if (!correct_input(av[i]))
				return (NULL);
			add_back(&a, get_new(ft_atoi(av[i]), NULL));
		}
		else if (!fill_stack(&a, ft_split(av[i], ' '), -1, -1))
			return (NULL);
		j = 0;
	}
	return (a);
}

int	is_sorted(t_list *b, t_list *b2)
{
	int	current;

	if (b2 != NULL)
		return (0);
	current = b->nb;
	while (b && b->next)
	{
		if (current <= b->nb)
			current = b->nb;
		else
			return (0);
		b = b->next;
	}
	if (current > b->nb)
		return (0);
	return (1);
}
