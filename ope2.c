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
	ft_printf("[X]");
	while (a)
	{
		ft_printf("[\e[0;32m%d\e[0m]", a->nb);
		a = a->next;
	}
	ft_printf("[X]\n");
}

void	swap(t_list **list)
{
	int	mem_nb;
	int mem_pos;

	if (size(*list) < 2)
		return ;
	mem_pos = (*list)->pos;
	mem_nb = (*list)->nb;
	(*list)->nb = (*list)->next->nb;
	(*list)->next->nb = mem_nb;
	(*list)->pos = (*list)->next->pos;
	(*list)->next->pos = mem_pos;
}

void	push(t_list **list, t_list **list2)
{
	t_list	*start;

	start = (*list)->next;
	add_front(list2, *list);
	(*list) = start;
}

void	reverse_rotate(t_list **list)
{
	t_list	*start;

	if (size(*list) == 2)
		swap(list);
	if (size(*list) <= 2)
		return ;
	start = (*list)->next;
	(*list)->next = NULL;
	add_back(&start, *list);
	(*list) = start;
}

void	rotate(t_list **list)
{
	int mem;
	t_list *to_move;
	t_list *start;

	start = *list;
	if (size(*list) == 2)
		swap(list);
	if (size(*list) <= 2)
		return ;	
	to_move = get_last(*list);
	while((*list)->next->next)
		(*list) = (*list)->next;
	(*list)->next = NULL;
	add_front(&start, to_move);
	(*list) = to_move;
	
}
