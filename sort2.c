/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:53:42 by niespana          #+#    #+#             */
/*   Updated: 2022/08/22 09:53:43 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_3(t_list *a)
{
	if (a->pos > a->next->pos)
		return (1);
	return (9);
}

static int	soft_sort(t_list *a)
{
	int	start;
	int	res;
	int	block;

	block = 0;
	res = 0;
	start = a->pos;
	while (a->pos != start || !block++)
	{
		if (is_sorted(a, NULL))
			res = 1;
		rotate(&a);
	}
	return (res);
}

static int	sort_fin(t_list *a, t_list *b, int max)
{
	if (size(b) > 1 && b->pos > b->next->pos && b->pos != max - 1)
		return (2);
	if (size(a) == max)
	{
		if (a->pos <= max / 2)
			return (9);
		return (6);
	}
	if (a->pos == b->pos + 1 || get_last(a)->pos == b->pos - 1
		|| (b->pos == max - 1 && a->pos == 0)
		|| b->pos == 0 && get_last(a)->pos == max - 1)
		return (4);
	if (b->pos > a->pos)
		return (6);
	return (9);
}

int	mini_sort(t_list *a, t_list *b)
{
	static int	sorted;
	static int	max;

	if (!max)
		max = size(a);
	if (soft_sort(a))
		sorted++;
	if (sorted)
		return (sort_fin(a, b, max));
	if (size(a) == 2)
		return (1);
	if (size(a) == 3)
		return (sort_3(a));
	return (5);
}
