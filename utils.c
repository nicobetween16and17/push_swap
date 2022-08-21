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

t_list	*get_stack(char **av, int i, int j)
{
	t_list	*a;

	a = NULL;
	while (av[++i])
	{
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

int	contain_duplicates(t_list *a)
{
	int	current;

	if (a)
		current = a->nb;
	else
		return (0);
	while (a->next)
	{
		if (current == a->next->nb)
			return (1);
		current = a->next->nb;
		a = a->next;
	}
	return (0);
}
