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

int	get_smallest_pos(t_list *lst)
{
	int	smallest;

	smallest = lst->pos;

	while (lst)
	{
		lst = lst->next;
		if (lst && smallest > lst->pos)
			smallest = lst->pos;
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

