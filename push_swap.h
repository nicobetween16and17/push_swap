/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:42:29 by niespana          #+#    #+#             */
/*   Updated: 2022/06/02 15:42:30 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "get_next_line.h"
#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*previous;
	int				nb;
}	t_list;


void	add_front(t_list **start, t_list *new);
void	add_back(t_list **start, t_list *new);
void	swap(t_list *swap1, t_list *swap2);
t_list	*get_last(t_list *start);
void	free_lst(t_list *start);
t_list	*get_new(int nb, t_list *next, t_list *previous);
t_list	*get_stack(char **av, int i, int j);
void	fill_stack(t_list **a, char **av, int i, int j);
void	rotate(t_list **list, int sens);
void	push(t_list **list, t_list **list2);
void	display_list(t_list *a);
int		is_sorted(t_list *b, t_list *b2);

#endif
