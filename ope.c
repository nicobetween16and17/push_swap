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

t_list	*get_new(int nb, t_list *next, t_list *previous)
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

t_list	*get_last(t_list *start)
{
	if (!start)
		return (start);
	while (start->next)
		start = start->next;
	return (start);
}

void	add_front(t_list **start, t_list *new)
{
	new->next = *start;
}

void	add_back(t_list **start, t_list *new)
{
	t_list	*tmp;

	if ((*start) == NULL)
	{
		*start = new;
		return ;
	}
	tmp = get_last(*start);
	tmp->next = new;
}

void	swap(t_list *swap1, t_list *swap2)
{
	int		mem_nb;

	mem_nb = swap1->nb;
	swap1->nb = swap2->nb;
	swap2->nb = mem_nb;
}


void	free_lst(t_list *start)
{
	while (start->next)
		free(get_last(start));
}