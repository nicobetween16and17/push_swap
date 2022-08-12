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
	while (a && a->pos != pos)
	{
		i++;
		a = a->next;
	}
	return (i < size(a) / 2);
}
int get_next_push(t_list *a, int **elim)
{
	int cpt;
	int delta;
	int pos;

	cpt = 0;
	delta = 2147483647;
	pos = -1;
	while (*elim && a)
	{
		cpt++;
		if (lcontain(*elim, a->pos) && (delta > cpt || delta > size(a) - cpt))
		{
			pos = a->pos;
			delta = cpt;
			if (size(a) / 2 < cpt)
				delta = size(a) - cpt;
		}
		a = a->next;
	}
	return (pos);
}
int already_sort(t_list *a)
{
	return (get_last(a)->pos + 1 == a->pos || a->next->pos - 1 == a->pos);//9(8 + 1) 8 7(8 - 1)
}
int best_pos(t_list *a, int pos, int i, int len)
{
	int	proximity;
	int	value;

	value = -1;
	proximity = len;
	while (a)
	{
		if (a->pos == pos + 1)
		{
			if (i < len / 2 && i < proximity)
			{
				value = a->pos;
				proximity = i;
			}
			if (i >= len / 2 && len - i < proximity)
			{
				value = a->pos;
				proximity = len - i;
			}
		}
		i++;
		a = a->next;
	}
	return (value);
}

int is_near(int pos, t_list *a)
{
	int	i;
	int	len;

	len = size(a);
	i = 0;
	if (pos == -1)
		return (0);
	while (a)
	{
		if (a->pos == pos && (i <=2 || len - i <= 2))
			return (1);
		else if (a->pos == pos)
			return (0);
		i++;
		a = a->next;
	}
	return (0);
}
int checklast(int *last, int new)
{
	if (new == 6 && *last == 9)
		return (*last);
	if (new == 9 && *last == 6)
		return (*last);
	*last = new;
	return (new);
}

int absolute_pos(int pos, t_list *b, t_list *start)
{
	int biggest_smol;

	biggest_smol = -1;
	while (b)
	{
		if (b->pos < pos && b->pos >= biggest_smol)
			biggest_smol = b->pos;
		b = b->next;
	}
	if (biggest_smol == -1)
	{
		b = start;
		while (b)
		{
			if (b->nb == get_biggest(start))
				biggest_smol = b->pos;
			b = b->next;
		}
	}
	return (biggest_smol);
}
int nothing_to_push(int *e, t_list *a)
{
	while (a)
	{
		if (!lcontain(e, a->pos))
			return (0);
		a = a->next;
	}
	return (1);
}
int list_contain(t_list *a, int pos)
{
	while (a)
	{
		if (a->pos == pos)
			return (1);
		a = a->next;
	}
	return (0);
}
int get_biggest_pos(t_list *a)
{
	int current;

	current = 0;
	while (a)
	{
		if (a->pos > current)
			current = a->pos;
		a = a->next;

	}
	return (current);
}
t_list *lst_cpy(t_list *a)
{
	t_list *cpy;

	cpy = malloc(sizeof(t_list));
	cpy->pos = a->pos;
	cpy->next = NULL;
	cpy->nb = a->nb;
	return (cpy);
}
t_list *lst_dup(t_list *a)
{
	t_list *cpy = NULL;

	while (a)
	{
		add_back(&cpy, lst_cpy(a));
		a = a->next;
	}
	return (cpy);
}

int next_not_contained(t_list *a, int *elim, int best_rotation)
{
	int	res;

	res = 0;
	if (!lcontain(elim, a->pos))
		return (a->pos);
	while (a)
	{
		if (best_rotation == 9 && !lcontain(elim, a->pos))
			return (a->pos);
		else if (!lcontain(elim, a->pos))
			res = a->pos;
		a = a->next;
	}
	return (res);
}
int mooves(t_list *b, int pos)
{
	int i;
	int len;

	len = size(b);
	i = 0;
	while (b)
	{
		if (b->pos == pos)
		{
			if (i < len / 2)
				return (len - i);
			return (i);
		}
		i++;
		b = b->next;
	}
	return (i);
}
int get_previous(t_list *a, int pos)
{
	int previous;

	previous = -1;
	while (a)
	{
		if (a->pos == pos)
			return (previous);
		previous = a->pos;
		a = a->next;
	}
	return (-1);
}
int get_delta(int pos1, int pos2)
{
	int res;

	res = pos1 - pos2;
	if (res < 0)
		res = -res;
	return (res);
}

int prediction(int pos, t_list *a, t_list *b, int direction)
{
	static int prediction;
	int res[4];

	if (prediction && prediction--)
		return (prediction);
	res[3] = 0;
	res[2] = mooves(b, absolute_pos(a->pos, b, b));
	res[1] = 2147483647;
	if (direction)
		res[0] = get_last(a)->pos;
	while (res[3]++ < res[2])
	{
		if (direction)
			res[0] = get_previous(a, res[0]);
		else
		{
			a = a->next;
			res[0] = a->pos;
		}
		if (get_delta(pos, res[0]) < res[1])
			res[1] = res[0];
		if (res[1] == res[0])
			prediction = res[3];
	}
	return (res[1]);
}
/*************************************************/
//TODO PREDICTION, TEST IT AND MAKE IT 25 LINES
int sort(t_list *a, t_list *b, int **elim)
{
	static int step;
	/*
	if (!step)
	{
		ft_printf("STEP %d\n", step);
		if (nothing_to_push(*elim, a))
			step = 1;
		if (!lcontain(*elim, a->pos))
		{
			if (!b || (size(b) < 2))
				return (5);
			if (b && size(b) >= 2 && b->pos == absolute_pos(a->pos, b, b))
				return (5);
			else if (b && (size(b) >= 2 && b->pos < absolute_pos(a->pos, b, b)
						   || (get_biggest(b) < a->pos)))
				return (7);
			return (10);
		}
		return (best_step_zero);
	}
	if (step == 1)
	{
		ft_printf("STEP %d\n", step);
		if (b->nb != get_biggest(b))
			return (7);
		if (ft_printf("%d > %d\n",get_biggest_pos(a),get_biggest_pos(b)) && get_biggest_pos(a) > get_biggest_pos(b) && a->pos != get_biggest_pos(a))
			return (6);
		if (ft_printf("hey\n") && get_biggest_pos(a) < get_biggest(b) && a->nb != get_smallest(a))
			return (6);
		step = 2;
	}
	if (step == 2)
	{
		ft_printf("STEP %d\n", step);
		if (b && a->nb == get_smallest(a) || b->pos == a->pos - 1)
			return (4);
		else if (b)
			return (6);
		else if (!b && is_kinda_sorted(a))
		{
			ft_printf("IS SORTED\n");
			if (direction_to_pos(a, 0))
				return (9);
			else
				return (6);
		}
	}*/
	if (step == 0)
	{
		if (!b || size(b) < 2)
			return (5);
		else if (b && b->pos == absolute_pos(a->pos, b, b))
			return (5);
		else if (b && (size(b) >= 2 && b->pos < absolute_pos(a->pos, b, b)
			|| (get_biggest(b) < a->pos)))
		{
			if (prediction(a->pos), a, b, 0)
				return (8);
			else
				return (7);
		}
		else if (prediction(a->pos, a, b, 1))
			return (11);
		else
			return (10)
	}
	return (6);
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
		if (l > 70000)
			exit(0);
		select_op(sort(a,b, &pushb), &a, &b);

	}
	ft_printf("a:\n");
	display_list(a);
	ft_printf("b:\n");
	display_list(b);
}