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

int	get_direction(t_list *lst)
{
	int	smallest;
	int	stop;

	stop = 0;
	smallest = get_smallest(lst);
	while (lst)
	{
		if (lst->nb == smallest)
			return (stop > size(lst) / 2);
		stop++;
		lst = lst->next;
	}
	return (0);
}

float	get_coef(t_list *a)
{
	float	coef;
	float	s;

	if (!a)
		return (0);
	coef = 0;
	s = (float)size(a);
	while (a->next)
	{
		if (a->nb > a->next->nb)
			coef++;
		a = a->next;
	}
	return (coef/s);
}

t_list	*duplicate(t_list *a)
{
	t_list	*res;

	res = get_new(a->nb, NULL, NULL);
	a = a->next;
	while (a)
	{
		add_back(&res, get_new(a->nb, NULL, NULL));
		a = a->next;
	}
	put_previous(&res);
	//display_list(res);
	return (res);
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

int	is_soft_sorted(t_list *b, int sens)
{
	int	first_encounter;
	t_list *dup;
	t_list *tmp;

	if (!b || is_inverse_sorted(b))
		return (1);
	dup = duplicate(b);
	tmp = dup;
	first_encounter = b->nb;
	while ((!is_inverse_sorted(dup) && !sens) || (sens && is_sorted(b, NULL)))
	{
		rotate(&dup, 1);
		put_previous(&dup);
		if (dup->nb == first_encounter)
		{
			dup = tmp;
			while (dup)
			{
				tmp = dup->next;
				free(dup);
				dup = tmp;
			}
			return (0);
		}
	}
	dup = tmp;
	while (dup)
	{
		tmp = dup->next;
		free(dup);
		dup = tmp;
	}
	return (1);
}

int	get_direction_b(t_list *b, int n)
{
	int	nearest;
	int	stop;
	t_list *start;

	start = b;
	stop = 0;
	nearest = n;
	if (!b)
		return (0);
	while (b)
	{
		if (b->nb - n > 0 && b->nb -n < nearest)
			nearest = b->nb - n;
		if (n - b->nb > 0 && n - b->nb < nearest)
			nearest = n - b->nb;
		b = b->next;
	}
	while (start && start->nb != nearest)
	{
		stop++;
		start = start->next;
	}
	return (stop >= size(b) / 2);
}

int	sort_this(t_list *b, int new, t_list *a, int n_smol)
{
	int final_ope;

	final_ope = 0;
	//ft_printf("need to sort this %d %d =? %d\n", get_direction_b(b, new), b->nb, new);
	//display_list(b);
	if (b && b->nb == new && get_direction_b(b, new))
	{
		//ft_printf("hey\n");
		final_ope = 2;
	}
	else if (b && get_direction_b(b, new))
	{
		//ft_printf("ho\n");
		final_ope = 10;
	}
	if (b && b->nb == new && !get_direction_b(b, new)) {
		//ft_printf("ah\n");
		final_ope = 7;
	}
	else if (b && !get_direction_b(b, new)) {
		//ft_printf("hi\n");
		final_ope = 2;
	}
	ft_printf("final ope is %d and best ope for a is %d\n", final_ope, get_best_ope(a, n_smol));
	ft_printf("%d->",n_smol);
	display_list(a);
	if (final_ope == get_best_ope(a, n_smol) + 1)
		return (final_ope + 1);
	return (final_ope);
}

int	must_still_push(t_list *a, t_list *b)
{
	if (!is_sorted(a, NULL))
	{
		//ft_printf("\e[0;31mnot sorted\e[0m\n");
		return (1);
	}

	if (is_sorted(a, NULL) && (get_biggest(b) == -1 || get_smallest(a) < get_biggest(b)))
		return (1);
	//ft_printf("\e[0;33mAAAAAA\e[0m");
	return (0);
}

int	rotate_a(t_list *a)
{
	int	i;
	int	smol;

	smol = get_smallest(a);
	i = 0;
	while (a)
	{
		if (a->nb == smol)
		{
			if (i <= size(a) / 2)
				return (9);
			return (6);
		}
		i++;
		a = a->next;
	}
	return (ft_printf("error number not found\n"));
}

int	rotate_b(t_list *b)
{
	int	i;
	int	bik;

	bik = get_biggest(b);
	i = 0;
	while (b)
	{
		if (b->nb == bik)
		{
			if (i <= size(b) / 2)
				return (10);
			return (7);
		}
		i++;
		b = b->next;
	}
	return (ft_printf("error number not found\n"));
}

int get_best_bope(t_list *b, int smol, int ope, int i)
{
	int	diff[3];
	t_list *start;

	start = b;
	diff[1] = smol;
	if (!b)
		return (0);
	while (b)
	{
		diff[0] = b->nb - smol;
		if (diff[0] < 0)
			diff[0] *= -1;
		if (diff[0] < diff[1])
			diff[2] = b->nb;
		if (diff[0] < diff[1])
			diff[1] = diff[0];
		else if (diff[0] == diff[1] && b->nb > diff[2])
			diff[2] = b->nb;
		b = b->next;
	}
	while (start && (i++ || start->nb != diff[2]))
		start = start->next;
	if (i < size(b) / 2)
		return (10);
	if (i > size(b) / 2)
		return (7);
	return (ope + 1);
}

