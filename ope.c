/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:42:14 by niespana          #+#    #+#             */
/*   Updated: 2022/06/02 15:42:16 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new(int nb, t_list *next, t_list *previous)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = next;
	new->previous = previous;
	return (new);
}

void	add_front(t_list *start, t_list *new)
{
	new->next = start;
}

void	add_back(t_list *start, t_list *new)
{
	t_list	*next;

	next = start->next;
	if (next)
		add_back(next, new);
	start->next = start;
}

void	swap(t_list *swap1, t_list *swap2)
{
	t_list	*mem_previous;
	t_list	*mem_next;
	int		mem_nb;

	mem_previous = swap1->previous;
	mem_next = swap1->next;
	mem_nb = swap1->nb;
	swap1->previous = swap2->previous;
	swap1->next = swap2->next;
	swap1->nb = swap2->nb;
	swap2->previous = mem_previous;
	swap2->next = mem_next;
	swap2->nb = mem_nb;
}

t_list	*get_last(t_list *start)
{
	t_list *last;

	last = start;
	while (last->next)
		last = last->next;
	return (last);
}

void	free_lst(t_list *start)
{
	while (start->next)
		free(get_last(start));
}