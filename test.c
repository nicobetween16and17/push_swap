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
void display1(int *lst)
{
	int i = -1;
	while (lst[++i] > -1)
		ft_printf("[\e[0;31m%d\e[0m]", lst[i]);
	write(0, "\n",1);
}
int lcontain(int *lst, int pos)
{
	int i;

	i = -1;
	while (lst[++i] >= 0)
	{
		if (lst[i] == pos)
			return (1);
	}
	return (0);
}
static void change_list(int **nbs, int posi)
{
	int pos;
	
	pos = 0;
	display1(*nbs);
	while ((*nbs)[pos] >= 0)
		pos++;	
	(*nbs)[pos++] = posi;
	(*nbs)[pos] = -1;
	display1(*nbs);
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
int direction_to_pos(t_list *a, int pos)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i < size(a) / 2);
}
/*************************************************/
int sort(t_list *a, t_list *b, int **elim)
{
	if (!b && is_kinda_sorted(a))
	{
		if (direction_to_pos(a, 0))
			return (9);
		else
			return (6);
	}
	else if (b && (b->pos == a->pos - 1 || b->pos == get_last(a)->pos + 1))
	{
		change_list(elim, b->pos);
		return (4);
	}
	else if (a->pos == a->next->next->pos - 1 || get_last(a)->pos == a->next->pos - 1 || a->pos - 1 == a->next->pos)
		return (1);
	else if (!lcontain(*elim, a->pos))
		return (5);
	return (6);
}
/*************************************************/
int main(int ac, char **av)
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
	display_list(a);
	int *pushb = to_push(a, 0,0, size(a));
	display_list(a);
	int i = -1;
	while (pushb[++i] >= 0)
		ft_printf("[%d]", pushb[i]);
	ft_printf("\n");
	int l = 0;
	display_pos(a);
	while (!is_sorted(a, b) && ++l)
	{
		ft_printf("-------%d-------\n", l);
		if (l > 50)
			exit(0);
		select_op(sort(a,b, &pushb), &a, &b);
		ft_printf("a:\n");
		display_list(a);
		ft_printf("b:\n");
		display_list(b);
	}
}