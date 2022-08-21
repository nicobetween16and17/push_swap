#include <stdio.h>
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
	select_op2(a, b, op);
}


int radix(int pos, int bit)
{
	while (bit)
	{
		bit--;
		pos /= 2;
	}
	return (pos % 2);
}

int radix_fin(t_list *a, int bit)
{
	while (a)
	{
		if (!radix(a->pos, bit))
			return (0);
		a = a->next;
	}
	return (1);
}
int get_dir(t_list *a, int pos, int size, int reset)
{
	static int res;
	int i;

	if (reset)
		res = 0;
	if (res)
		return (res);
	i = 0;
	while (a)
	{

		if (a->pos == pos)
			break;
		i++;
		a = a->next;
	}
	res = 6;
	if (i <= size / 2)
		res = 9;
	return (res);
}
/*************************************************/
int sort(t_list *a, t_list *b)
{
	static int bit;
	static int step;
	static int first;

	if (step == 1)
	{
		if (a->pos == first)
			step++;
		else
			return (get_dir(a, first, size(a), 0));
	}
	if (step == 2)
	{
		get_dir(a, first, size(a), 1);
		if (b)
			return (4);
		else
		{
			first = 0;
			step = 0;
			bit++;
		}
	}
	if (!step)
	{
		if (radix_fin(a, bit))
			step++;
		else if (radix(a->pos, bit))
		{
			if (!first)
				first = a->pos;
			return (9);
		}
		else
			return (5);
	}
	return (0);
}
/*************************************************/
int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (ac == 1)
		return (0);
	a = get_stack(av, 0, 0);
	assign_stack(&a, get_smallest(a));
	while (!is_sorted(a, b))
		select_op(sort(a, b), &a, &b);
	/*ft_printf("a:\n");
	display_list(a);
	ft_printf("b:\n");
	display_list(b);*/
}