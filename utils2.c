/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:57:10 by niespana          #+#    #+#             */
/*   Updated: 2022/06/03 10:57:12 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int size(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	get_smallest(t_list *lst)
{
	int	smallest;

	smallest = lst->nb;
	while (lst)
	{
		lst = lst->next;
		if (lst && smallest > lst->nb)
			smallest = lst->nb;
	}
	return (smallest);
}

int	get_biggest(t_list *lst)
{
	int	biggest;

	if (!lst)
		return (-1);
	biggest = lst->nb;
	while (lst)
	{
		lst = lst->next;
		if (lst && biggest < lst->nb)
			biggest = lst->nb;
	}
	return (biggest);
}

void assign_stack(t_list **list, int smallest)
{
	t_list	*start;
	int		nb;
	int		cpt;

	cpt = 0;
	nb = smallest;
	start = *list;
	while (cpt < size(start))
	{
		while(*list)
		{
			if ((*list)->nb == nb)
				(*list)->pos = cpt++;	
			*list = (*list)->next;
		}
		*list = start;
		nb = 2147483647;
		while(*list)
		{
			if ((*list)->pos == -1 && (*list)->nb < nb)
				nb = (*list)->nb;
			*list = (*list)->next;
		}
		*list = start;
	}
}

int get_longest_suite(t_list *a)
{
	int start;
	int len;
	int save[2];

	start = 0;
	save[0] = -1;
	while(a)
	{
		if (a->next && a->next->pos == a->pos + 1 && !start++)
			save[1] = a->nb;
		else if (a->next && a->next->pos == a->pos + 1)
			len++;
		else if (save[0] < len)
		{
			save[0] = len;
			save[1] = a->pos;
		}
		a = a->next;
		start = 0;
	}
	return (save[1]);
}

int get_last_element_of_suite_b(t_list *a, t_list *b)
{
	int pos;

	pos = a->pos;
	while (a->next)
	{
		if (a->next->pos != a->pos - 1)
			return (pos);
		pos = a->next->pos;
		a = a->next;
	}
	if (!pos)
		return (size(a) + size(b));
	return (pos);
}

int get_nearest_suite(t_list *a)
{
	while(a)
	{
		if (a->next && a->next->pos == a->pos + 1)
			return (a->pos);
		a = a->next;
	}
	return (-1);
}

int is_already_well_placed(t_list *a, int pos)
{
	int previous_pos;
	int next_pos;
	t_list *start;

	previous_pos = -1;
	start = a;
	while (a->next)
	{
		if (a->next->pos == a->pos + 1)
			previous_pos = a->next->pos;
		a = a->next;
	}
	next_pos = get_nearest_suite(start);
	if (start->nb == get_biggest(start) && start->next->nb == get_smallest(start))
		return (1);
	if (previous_pos > next_pos)
		return (pos < next_pos && next_pos > 0);
	return (pos > previous_pos && pos < next_pos && next_pos > 0);
}

int need_swap(t_list *a)
{
	if (size(a) <= 2 || get_nearest_suite(a) == a->pos)
		return (0);
	if (get_last(a)->pos == a->pos - 1)
		return (0);
	if (a->next->next && a->pos == a->next->next->pos - 1)
		return (1);
	if (get_last(a)->pos == a->next->pos - 1)
		return (1);
	return (0);
}

int	everything_well_placed(t_list *a)
{
	int pos;
	t_list *start;

	start = a;
	pos = -1;
	while (a)
	{
		if (get_nearest_suite(a) != a->pos && pos + 1 != a->pos
			&& a->next && a->next->pos < a->pos)
			return (0);
		pos = a->pos;
		a = a->next;
	}
	return (1); 
}

int need_push(t_list *a, t_list *b)
{
	ft_printf("%d =? %d:%d\n", get_last_element_of_suite_b(b, a) , get_last(a)->nb, get_last(a)->pos + 1);
	return (a && b && get_last_element_of_suite_b(b, a) == get_last(a)->pos + 1);
}

int	is_a_starting_suite(t_list *a)
{
	return ((a->pos == get_nearest_suite(a)
		&& get_last(a)->pos != a->pos - 1) || size(a) == 1);
}

int get_last_suite(t_list *c)
{
	int pos;

	pos = -1;
	while(c)
	{
		if (c->pos == get_nearest_suite(c) && (pos != c->pos - 1 || pos == -1))
			pos = c->pos;
		c = c->next;
	}
	return (pos);
}
//if type is 0 return a distance (number of rotation) else return a direction (-1 is backward and 1 forward)
int delta_suite(t_list *a, int pos)
{
	int len;
	int cpt;

	cpt = 0;
	len = size(a);
	while (a && a->pos + 1 == pos && ++cpt)
		a = a->next;
	return (len / 2 <= cpt);
}

int direction(t_list *b)
{
	int len;
	int cpt;

	cpt = 0;
	len = size(b);
	while (b && b->nb != get_biggest(b) && ++cpt)
		b = b->next;
	return (len / 2 <= cpt);
}
int find_position_b(t_list *b, int pos)
{
	int len;
	int cpt;

	cpt = 0;
	len = size(b);
	while (b && b->nb > pos && ++cpt)
		b = b->next;
	return (len / 2 <= cpt);
}
int aftermath_rotations(t_list *a, t_list *b)
{
	if (need_push(a, b))
		return (4);
	else if (b && b->nb == get_biggest(b))
	{
		if (delta_suite(a, get_last_element_of_suite_b(b, a)))
			return (6);
		else
			return (9);
	}
	else if (direction(b))
		return (7);
	return (10);
}
int *to_push(t_list *a, int i, int j, int nb_pos)
{
	int *positions;
	int max;
	t_list *start;
	int *cpy;
	int last_pos;

	last_pos = size(a);
	start = a;
	nb_pos = 0;
	positions = malloc(sizeof(int) * (size(a) + 1));
	cpy = malloc(sizeof(int) * (size(a) + 1));
	while (++j < size(a))
	{
		ft_printf("~~~~~%d~~~~\n", j);
		i = 0;
		max = 0;
		positions[i++] = a->pos;
		while (a)
		{
			if (!max && a->pos < last_pos && ft_printf("!added %d\n", a->pos))
				positions[i++] = a->pos;
			else
				last_pos = a->pos;
			if (((a->pos > start->pos) || (a->pos > last_pos)) && ft_printf("?added %d\n", a->pos))
				positions[i++] = a->pos;
			else
				last_pos = a->pos;
			if (ft_printf("looking at %d\n", a->pos) && a->pos == size(start) - 1)
			{
				max++;
				last_pos = 0;
			}
			positions[i] = -1;
			a = a->next;
		}
		a = start;
		if (nb_pos < i)
		{
			int p = -1;
			ft_printf("-------------\n");
			while (++p < i)
				ft_printf("[%d]", positions[p]);
			ft_printf("------------\n");
			cpy = positions;
			nb_pos = i;
		}
		rotate(&a);
		start = a;
	}
	rotate(&start);
	a = start;
	positions[i] = -1;
	free(positions);
	return (cpy);
}



