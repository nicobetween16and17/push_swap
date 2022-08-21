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

void	fill_stack(t_list **a, char **av, int i, int j)
{
	while (av[++i])
		add_back(a, get_new(ft_atoi(av[i]), NULL));
	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}

int	check_max(char *s, char *max, int signe)
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

int	correct_input(char *s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = -1;
	while (s && s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	if (s && s[0] == '-')
		len--;
	if (len > 10)
		return (0);
	if (len == 10)
		return (check_max(s, "2147483647", s[0] == '-'));
	return (1);
}

t_list	*get_stack(char **av, int i, int j)
{
	t_list	*a;

	a = NULL;
	while (av[++i])
	{
		if (!correct_input(av[i]))
			return (NULL);
		while (av[i][j])
			j++;
		if (j == 1)
			add_back(&a, get_new(ft_atoi(av[i]), NULL));
		else
			fill_stack(&a, ft_split(av[i], ' '), -1, -1);
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
