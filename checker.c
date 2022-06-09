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
	if (op == 6)
		rotate(a, 1);
	if (op == 7)
		rotate(b, 1);
	if (op == 8)
	{
		rotate(a, 1);
		rotate(b, 1);
	}
	if (op == 9)
		rotate(a, 0);
	if (op == 10)
		rotate(b, 0);
	if (op == 11)
	{
		rotate(a, 0);
		rotate(b, 0);
	}
}

void	do_op(t_list **a, t_list **b, int op)
{
	if (op == 1)
		swap(*a, (*a)->next);
	if (op == 2)
		swap(*b, (*b)->next);
	if (op == 3)
	{
		swap(*a, (*a)->next);
		swap(*b, (*b)->next);
	}
	if (op == 4)
		push(b, a);
	if (op == 5)
		push(a, b);
	do_op2(a, b, op);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	*stdin;
	int		sort_type;

	if (ac != 2)
		return (1);
	a = get_stack(av, 0, 0);
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
		display_list(a);
		display_list(b);
		stdin = get_next_line(0);
	}
	if (is_sorted(a, b))
		return (ft_printf("OK\n"));
	ft_printf("KO\n");
}
