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
int main(void)
{
	int	i;
	t_list	*start;

	start = new(0, NULL, NULL);
	i = 0;
	while (++i < 10)
	{
		printf("adding...\n");
		add_back(&start, new(i, NULL, get_last(start)));
	}
	while (start->next)
	{
		printf("%d\n", start->nb);
		start = start->next;
	}
}
