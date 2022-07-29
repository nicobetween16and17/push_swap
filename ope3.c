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
		if (smallest > end->nb)
			smallest = end->nb;
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

int is_soft_invert_sorted(t_list *b)
{
	int		bik;
	int		current;
	t_list	*start;

	current = bik;
	start = b;
	bik = get_biggest(b);
	ft_printf("bikkest is %d\n", bik);
	while (b->next)
	{

		if (b->nb == bik)
			
		if (current < b->next->nb && ft_printf("1 current %d and next %d\n", current, b->next->nb))
		{
			return (0);
			current = b->next->nb;
		}
		b = b->next;
	}
	while (start && start->nb != bik)
	{
		if (start->next && start->next->nb != bik && current < start->next->nb && ft_printf("2 current %d and next %d\n", current, start->next->nb))
			return (0);
		current = b->next->nb;
		start = start->next;
	}
	return (1);
}

