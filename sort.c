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

int radix (int pos, int bit)
{
	while (bit)
	{
		bit--;
		pos /= 2;
	}
	return (pos % 2);
}

int radix_fin(t_list *a, int bit)
{
	while (a)
	{
		if (!radix(a->pos, bit))
			return (0);
		a = a->next;
	}
	return (1);
}

int get_dir(t_list *a, int pos, int size, int reset)
{
	static int res;
	int i;

	if (reset)
		res = 0;
	if (res)
		return (res);
	i = 0;
	while (a)
	{

		if (a->pos == pos)
			break;
		i++;
		a = a->next;
	}
	res = 6;
	if (i <= size / 2)
		res = 9;
	return (res);
}
