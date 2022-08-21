/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:53:08 by niespana          #+#    #+#             */
/*   Updated: 2022/06/06 10:53:09 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	correct_output(char *output, int size)
{
	if (!ft_strncmp(output, "sa\n", size))
		return (1);
	if (!ft_strncmp(output, "sb\n", size))
		return (2);
	if (!ft_strncmp(output, "ss\n", size))
		return (3);
	if (!ft_strncmp(output, "pa\n", size))
		return (4);
	if (!ft_strncmp(output, "pb\n", size))
		return (5);
	if (!ft_strncmp(output, "ra\n", size))
		return (6);
	if (!ft_strncmp(output, "rb\n", size))
		return (7);
	if (!ft_strncmp(output, "rr\n", size))
		return (8);
	if (!ft_strncmp(output, "rra\n", size))
		return (9);
	if (!ft_strncmp(output, "rrb\n", size))
		return (10);
	if (!ft_strncmp(output, "rrr\n", size))
		return (11);
	return (0);
}

void	do_op2(t_list **a, t_list **b, int op)
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

void	do_op(t_list **a, t_list **b, int op)
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
	if (op == 6 && ft_printf("ra\n"))
		rotate(a);
	if (op == 7 && ft_printf("rb\n"))
		rotate(b);
	do_op2(a, b, op);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*stdin;
	int		sort_type;

	a = get_stack(av, 0, 0);
	assign_stack(&a, get_smallest(a));
	if (contain_duplicates(a))
		return (ft_printf("contain duplicates\n"));
	b = NULL;
	stdin = get_next_line(0);
	while (stdin)
	{
		sort_type = correct_output(stdin, (int)ft_strlen(stdin));
		if (!sort_type)
			return (ft_printf("KO\n"));
		else
			do_op(&a, &b, sort_type);
		free(stdin);
		stdin = get_next_line(0);
	}
	if (is_sorted(a, b))
		return (ft_printf("OK\n"));
	ft_printf("KO\n");
}
