/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 08:08:43 by niespana          #+#    #+#             */
/*   Updated: 2022/08/21 08:08:46 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	radix(int pos, int bit)
{
	while (bit)
	{
		bit--;
		pos /= 2;
	}
	return (pos % 2);
}

int	radix_fin(t_list *a, int bit)
{
	while (a)
	{
		if (!radix(a->pos, bit))
			return (0);
		a = a->next;
	}
	return (1);
}

int	get_dir(t_list *a, int pos, int size, int reset)
{
	static int	res;
	int			i;

	if (reset)
	{
		res = 0;
		return (1);
	}
	if (res)
		return (res);
	i = 0;
	while (a)
	{
		if (a->pos == pos)
			break ;
		i++;
		a = a->next;
	}
	res = 6;
	if (i <= size / 2)
		res = 9;
	return (res);
}

int	step_one(int *first, t_list *a, int bit, int *step)
{
	if (!(*first) && radix(a->pos, bit))
		*first = a->pos;
	if (radix_fin(a, bit))
		(*step)++;
	else if (radix(a->pos, bit))
		return (9);
	else
		return (5);
	return (0);
}

int	mini_sort(t_list *a, t_list *b)
{
	static int	sort;

	if (size(a) > 3 && !sort)
		if (a->next->pos == 4)
			return (9);
	if (size(a) > 3 && !sort)
		return (5);
	else if (size(a) == 2 && !sort)
		return (6);
	if (is_sorted(a, NULL))
		sort++;
	if (sort)
	{
		if (b && (b->pos == a->pos - 1 || get_last(a)->pos == b->pos - 1))
			return (4);
		if (b && b->next && (b->next->pos == a->pos - 1
				|| get_last(a)->pos == b->next->pos - 1))
			return (2);
		if (b && get_last(a)->pos -1 == b->pos)
			return (6);
		return (9);
	}
	if (a->next->pos < a->pos)
		return (1);
	return (6);
}
