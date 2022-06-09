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
#include <stdio.h>
int	sort_next(t_list *a, t_list *b)
{
	int			res;
	static int	n_smol;
	static int	has_pushed;
	static int	test;
	static int	new;
	static int	siza;

	//ft_printf("smol is %d =? %d and old is %d\n", n_smol, a->nb, new);
	//if (!siza)
	//	siza = size(a);
	//test++;
	//if ((size(a) + size(b) < siza || test > 50) && ft_printf("%de ope has leaks/stopped\n", test - 1))
	//	exit(0);
	if (is_sorted(a, NULL) && b
		&& is_inverse_sorted(b) && get_biggest(b) < get_smallest(a))
	{
		//ft_printf("1\n");
		return (4);
	}

	/*if (!is_sorted(a, NULL) && is_soft_sorted(a, 1)
		&& is_soft_sorted(b, 0) && get_smallest(a) > get_biggest(b))
	{
		ft_printf("2\n");
		return (rotate_a(a));
	}*/

	if (is_sorted(a, NULL) && is_soft_sorted(b, 0) && !is_inverse_sorted(b))
	{
		//ft_printf("3\n");
		return (rotate_b(b));
	}

	if (!has_pushed && !has_pushed++)
	{
		new = n_smol;
		n_smol = get_nearest_smallest(a);
	}
	if (!is_soft_sorted(b, 0))
	{
	//	ft_printf("4\n");
		return (sort_this(b, new, a, n_smol));
	}

	//ft_printf("%d =? %d hp == %d\n", a->nb, n_smol, has_pushed);
	if (must_still_push(a, b) && (a->nb == get_smallest(a)
		|| a->nb == n_smol) && has_pushed--)
		return (5);
	res = get_best_ope(a, n_smol);
	if (res + 1 == get_best_bope(b, n_smol, res, 0))
		return (res + 2);
	return (res);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		op;

	b = NULL;
	if (ac == 1)
		return (0);
	a = get_stack(av, 0, 0);
	while (!(is_sorted(a, b))) {
		op = sort_next(a, b);
		select_op(op, &a, &b);
		//ft_printf("a ->");
		//display_list(a);
		//ft_printf("b ->");
		//display_list(b);
	}
	//ft_printf("a ->");
	//display_list(a);
	//ft_printf("b ->");
	//display_list(b);
	return (1);
}
