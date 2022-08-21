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

int is_soft_invert_sorted(t_list *b, int rdy)
{
	int		bik;
	int		current;
	t_list	*start;

	start = b;
	bik = get_biggest(b);
	current = bik;
	while (b->next && get_last(b)->nb != bik)
	{
		if (b->nb == bik)
			rdy++;
		if (current < b->next->nb )
			return (0);
		if (rdy)
			current = b->next->nb;
		b = b->next;
	}
	while (start && start->nb != bik)
	{
		if (start->next && start->nb != bik && current < start->nb)
			return (0);
		current = start->nb;
		start = start->next;
	}
	return (1);
}


