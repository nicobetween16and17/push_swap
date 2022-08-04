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
		rotate(a);
		rotate(b);
	}
	if (op == 9 && ft_printf("rra\n"))
		reverse_rotate(a);
	if (op == 10 && ft_printf("rrb\n"))
		reverse_rotate(b);
	if (op == 11 && ft_printf("rrr\n"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void	select_op(int op, t_list **a, t_list **b)
{
	if (op == 1 && ft_printf("sa\n"))
		swap(a);
	if (op == 2 && ft_printf("sb\n"))
		swap(b);
	if (op == 3 && ft_printf("ss\n"))
	{
		swap(a);
		swap(b);
	}
	if (op == 4 && ft_printf("pa\n"))
		push(b, a);
	if (op == 5 && ft_printf("pb\n"))
		push(a, b);
	if (op == 6 && ft_printf("ra\n"))
		rotate(a);
	if (op == 7 && ft_printf("rb\n"))
		rotate(b);
	select_op2(a, b, op);
}
#include <stdio.h>
int	sort_next(t_list *a, t_list *b)
{
	static int go;
	static int test;
	if (!test)
		test = 1;
	if (test++ > 30)
		exit(0);
	int	res;
	if (b && a && b->pos == a->pos -1)
		return (4);
	else if (size(b) > 2 && !is_soft_invert_sorted(b, 0))
	{
		if (b->next->pos > b->pos)
		{
			if (need_swap(a))
				return (3);
			else
				return (2);
		}
		else if (get_last(b)->pos < b->pos)
		{
			if (a->pos != get_nearest_suite(a))
				return (8);
			return (7);
		}
		else if (a->pos != get_nearest_suite(a))
			return(11);
		return (10);
	}
	else if (everything_well_placed(a) || go)
	{
		go =1;
		return (aftermath_rotations(a, b));
	}
	else if (need_swap(a))
		return (1);
	else if (is_already_well_placed(a, a->pos))
		return (9);
	else if (a->pos != get_nearest_suite(a) && get_last(a)->pos + 1 != a->pos)
		return (5);
	return (9);
}
//TODO NEED_PUSH FONTIONNE PAS JE CROIS 
int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		op;
	static int	nb;
	if (!nb)
		nb = 1;
	b = NULL;
	if (ac == 1)
		return (0);
	a = get_stack(av, 0, 0);
	assign_stack(&a, get_smallest(a));
	while (!(is_sorted(a, b)))
	{
		op = sort_next(a, b);
		select_op(op, &a, &b);
		ft_printf("--------------%d-------------\n", nb++);
		ft_printf("a ->");
		display_list(a);
		ft_printf("b ->");
		display_list(b);
		ft_printf("----------------------------\n");
	}
	ft_printf("a ->");
	display_list(a);
	ft_printf("b ->");
	display_list(b);
	return (1);
}
