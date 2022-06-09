/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:56:38 by niespana          #+#    #+#             */
/*   Updated: 2022/06/03 10:56:39 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nearest_smallest(t_list *a)
{
	t_list	*end;
	int		i;
	int		smallest;

	i = -1;
	smallest = a->nb;
	end = get_last(a);
	while (++i < 1)
	{
		if (a->next && smallest > a->next->nb)
			smallest = a->next->nb;
		if (end->previous && smallest > end->nb)
			smallest = end->nb;
		end = end->previous;
		a = a->next;
	}
	return (smallest);
}

int	contain(t_list *a, int n)
{
	while (a && a->next)
	{
		if (a->nb == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	get_best_ope(t_list *a, int n)
{
	if (a->next && n == a->next->nb)
		return (9);
	else
		return (6);
}

int	is_inverse_sorted(t_list *b)
{
	int	nb;

	if (!b)
		return (1);
	nb = b->nb;
	while (b->next)
	{
		if (nb < b->next->nb)
			return (0);
		nb = b->next->nb;
		b = b->next;
	}
	return (1);
}
