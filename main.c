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
#include <stdio.h>

void	fill_stack(t_list **a, char **av, int i, int j)
{
	while (av[++i])
	{
		printf("hey %d\n", ft_atoi(av[i]));
		add_back(a, get_new(ft_atoi(av[i]), NULL, get_last(*a)));
	}
	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
}

t_list	*get_stack(char **av, int i, int j)
{
	t_list	*a;

	a = NULL;
	while (av[++i])
	{
		while (av[i][j])
			j++;
		printf("%d char long\n", j);
		if (j == 1)
			add_back(&a, get_new(ft_atoi(av[i]), NULL, get_last(a)));
		else
			fill_stack(&a, ft_split(av[i], ' '), -1,-1);
		j = 0;
	}
	return (a);
}

int main(int ac, char **av)
{
	t_list *a;
	t_list *b;

	if (ac == 1)
		return (0);
	a = get_stack(av, 0, 0);
	while (a)
	{
		printf("[%d]", a->nb);
		a = a->next;
	}
}
