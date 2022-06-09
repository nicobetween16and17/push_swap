/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:56:31 by niespana          #+#    #+#             */
/*   Updated: 2022/06/03 10:56:34 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//yo supp ca un jour
void	display_list(t_list *a)
{
	if (a && a->previous == NULL)
		ft_printf("[X]");
	else if (a)
		ft_printf("!%d!", a->previous->nb);
	while (a)
	{
		ft_printf("[%d]", a->nb);
		a = a->next;
	}
	ft_printf("[X]\n");
}

void	swap(t_list *swap1, t_list *swap2)
{
	int	mem_nb;

	mem_nb = swap1->nb;
	swap1->nb = swap2->nb;
	swap2->nb = mem_nb;
}

void	push(t_list **list, t_list **list2)
{
	int		i;
	t_list	*start;

	start = (*list)->next;
	add_front(list2, *list);
	(*list) = start;
	if ((*list))
		(*list)->previous = NULL;
	if ((*list2)->previous)
		(*list2) = (*list2)->previous;
}

void	reverse(t_list **list)
{
	t_list	*start;

	start = *list;
	while (*list && (*list)->next)
		*list = (*list)->next;
	if (start == *list)
		return ;
	if ((*list) && (*list)->previous)
		(*list)->previous->next = NULL;
	if (*list)
		(*list)->previous = NULL;
	if (*list)
		(*list)->next = start;
	put_previous(list);
}

void	rotate(t_list **list, int sens)
{
	t_list	*start;

	if (size(*list) == 2)
		swap(*list, (*list)->next);
	if (size(*list) == 2)
		return ;
	if (!(*list) || !(*list)->next)
		return ;
	start = (*list)->next;
	if (sens)
	{
		reverse(list);
		return ;
	}
	(*list)->next->previous = NULL;
	(*list)->next = NULL;
	add_back(&start, *list);
	(*list) = start;
	put_previous(list);
}
