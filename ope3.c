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
/*-----*
* Le premier while stop directement si la cible est au bout
* sinon incremente jusqu'a trouver le max puis, compare un par un les nombre adjacents
* ensuite on repart du debut en comparant depuis le dernier et ce, jusqu'au maximum
* si la suite de comparaison prouve que nb1 > nb2 > nb3 > ... > nbfin alors retourne vrai
* si une comparaison est fausse, renvoit faux
*------*/
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


