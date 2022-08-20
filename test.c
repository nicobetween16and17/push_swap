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
	ft_printf("\e[0m");
}

void	select_op(int op, t_list **a, t_list **b)
{
	ft_printf("\e[0;35m");
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
void display_pos(t_list *a)
{
	while (a)
	{
		ft_printf("[%d:%d]",a->pos, a->nb);
		a = a->next;
	}
	ft_printf("\n");
}
int is_kinda_sorted(t_list *a)
{
	t_list	*start = a;
	int		smol;

	smol = -1;
	while (a && a->pos != 0)
		a = a->next;
	while (a)
	{
		if (a->pos != ++smol)
			return (0);
		a = a->next;
	}
	while (start && start->pos != 0)
	{
		if (start->pos != ++smol)
			return (0);
		start = start->next;
	}
	return (1);
}

int soft_sorted(t_list *a)
{
	int small;
	int current;
	t_list *start;

	start = a;
	current = get_smallest_pos(a);
	small = current;
	while (a && a->pos != small)
		a = a->next;
	a = a->next;
	while (a)
	{
		if (a->pos != ++current)
			return (0);
		a = a->next;
	}
	a = start;
	while (a && a->pos != small)
	{
		if (a->pos != ++current)
			return (0);
		a = a->next;
	}
	return (1);
}

int radix(int pos, int bit)
{
	int res;

	res = pos / 2;
	while (bit--)
		res /= 2;
	res = res % 2;
	return (res);
}
/*************************************************/
int sort(t_list *a, t_list *b, int size)
{
	static int bit;
	static int step;
	static int current

	if (!current)
		current = size;
	if (step)
	{
		if (b)
			return (4);
		else
		{
			step--;
			bit++;
		}

	}
	if (!step)
	{
		current--;
		if (!current)
			step++;
		if (radix(a->pos, bit))
			return (5);
		else
			return (6);
	}



}
/*************************************************/
int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	static int	nb;
	if (!nb)
		nb = 1;
	b = NULL;
	if (ac == 1)
		return (0);
	a = get_stack(av, 0, 0);
	assign_stack(&a, get_smallest(a));
	display_list(a);
	int *pushb = to_push(a, 0,0, size(a));
	display_list(a);
	int i = -1;
	while (pushb[++i] >= 0)
		ft_printf("[%d]", pushb[i]);
	ft_printf("\n");
	int l = 0;
	display_pos(a);
	display1(pushb);
	while (!is_sorted(a, b) && ++l)
	{
		ft_printf("-------%d-------\n", l);
		if (l > 10)
			exit(0);
		select_op(sort(a,b, &pushb), &a, &b);
		ft_printf("a:\n");
		display_list(a);
		ft_printf("b:\n");
		display_list(b);
	}

}