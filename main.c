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
	if (op == 11 && ft_printf("rrr\n"))
	{
		rotate(a);
		rotate(b);
	}
	if (op == 6 && ft_printf("ra\n"))
		reverse_rotate(a);
	if (op == 7 && ft_printf("rb\n"))
		reverse_rotate(b);
	if (op == 8 && ft_printf("rr\n"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void	select_op(int op, t_list **a, t_list **b)
{
	if (!op)
		return ;
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
	if (op == 9 && ft_printf("rra\n"))
		rotate(a);
	if (op == 10 && ft_printf("rrb\n"))
		rotate(b);
	select_op2(a, b, op);
}

void	cycle_up(int *first, int *step, int *bit)
{
	*first = 0;
	*step = 0;
	(*bit) = *bit + 1;
}

int	sort(t_list *a, t_list *b)
{
	static int	bit;
	static int	step;
	static int	first;

	if (step == 1)
	{
		if (a->pos == first)
			step++;
		else
			return (get_dir(a, first, size(a), 0));
	}
	if (step == 2 && get_dir(a, first, size(a), 1))
	{
		if (b)
			return (4);
		else
			cycle_up(&first, &step, &bit);
	}
	if (!step)
		return (step_one(&first, a, bit, &step));
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (ac == 1)
		return (0);
	a = get_stack(av, 0, 0);
	if (!a && ft_printf("Error\n"))
		return (0);
	if (contain_duplicates(a) && ft_printf("Error\n"))
		return (0);
	assign_stack(&a, get_smallest(a));
	if (size(a) <= 5)
	{
		while (!is_sorted(a, b))
			select_op(mini_sort(a, b), &a, &b);
	}
	while (!is_sorted(a, b))
		select_op(sort(a, b), &a, &b);
	free_lst(a);
}
