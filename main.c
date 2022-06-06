/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:42:07 by niespana          #+#    #+#             */
/*   Updated: 2022/06/02 15:42:08 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_op2(t_list **a, t_list **b, int op)
{
	if (op == 8 && ft_printf("rr\n"))
	{
		rotate(a, 1);
		rotate(b, 1);
	}
	if (op == 9 && ft_printf("rra\n"))
		rotate(a, 0);
	if (op == 10 && ft_printf("rrb\n"))
		rotate(b, 0);
	if (op == 11 && ft_printf("rrr\n"))
	{
		rotate(a, 0);
		rotate(b, 0);
	}
}

void	select_op(int op, t_list **a, t_list **b)
{
	if (op == 1 && ft_printf("sa\n"))
		swap(*a, (*a)->next);
	if (op == 2 && ft_printf("sb\n"))
		swap(*b, (*b)->next);
	if (op == 3 && ft_printf("ss\n"))
	{
		swap(*a, (*a)->next);
		swap(*b, (*b)->next);
	}
	if (op == 4 && ft_printf("pa\n"))
		push(b, a);
	if (op == 5 && ft_printf("pb\n"))
		push(a, b);
	if (op == 6 && ft_printf("ra\n"))
		rotate(a, 1);
	if (op == 7 && ft_printf("rb\n"))
		rotate(b, 1);
	select_op2(a, b, op);
}

int	sort_next(t_list **a, t_list **b)
{

}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1)
		return (0);
	a = get_stack(av, 0, 0);
	while (a)
	{
		ft_printf("[%d]", a->nb);
		a = a->next;
	}
	while (!(is_sorted(a, b)))
		select_op(sort_next(&a, &b), &a, &b);
	return (1);
}
