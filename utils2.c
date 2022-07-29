/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:57:10 by niespana          #+#    #+#             */
/*   Updated: 2022/06/03 10:57:12 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int size(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	get_smallest(t_list *lst)
{
	int	smallest;

	smallest = lst->nb;
	while (lst)
	{
		lst = lst->next;
		if (lst && smallest > lst->nb)
			smallest = lst->nb;
	}
	return (smallest);
}

int	get_biggest(t_list *lst)
{
	int	biggest;

	if (!lst)
		return (-1);
	biggest = lst->nb;
	while (lst)
	{
		lst = lst->next;
		if (lst && biggest < lst->nb)
			biggest = lst->nb;
	}
	return (biggest);
}

void assign_stack(t_list **list, int smallest)
{
	t_list	*start;
	int		nb;
	int		cpt;

	cpt = 0;
	nb = smallest;
	start = *list;
	while (cpt < size(start))
	{
		while(*list)
		{
			if ((*list)->nb == nb)
				(*list)->pos = cpt++;	
			*list = (*list)->next;
		}
		*list = start;
		nb = 2147483647;
		while(*list)
		{
			if ((*list)->pos == -1 && (*list)->nb < nb)
				nb = (*list)->nb;
			*list = (*list)->next;
		}
		*list = start;
	}
}

int get_longest_suite(t_list *a)
{
	int start;
	int len;
	int save[2];

	start = 0;
	save[0] = -1;
	while(a)
	{
		if (a->next && a->next->pos == a->pos + 1 && !start++)
			save[1] = a->nb;
		else if (a->next && a->next->pos == a->pos + 1)
			len++;
		else if (save[0] < len)
		{
			save[0] = len;
			save[1] = a->pos;
		}
		a = a->next;
		start = 0;
	}
	return (save[1]);
}

int get_nearest_suite(t_list *a)
{
	while(a)
	{
		if (a->next && a->next->pos == a->pos + 1)
			return (a->pos);
		a = a->next;
	}
	return (-1);
}