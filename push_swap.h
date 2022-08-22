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
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	struct s_list	*next;
	int				nb;
	int				pos;
}	t_list;

void	add_front(t_list **start, t_list *new);
void	add_back(t_list **start, t_list *new);
void	swap(t_list **list);
t_list	*get_last(t_list *start);
void	free_lst(t_list *start);
t_list	*get_new(int nb, t_list *next);
t_list	*get_stack(char **av, int i, int j);
void	fill_stack(t_list **a, char **av, int i, int j);
void	rotate(t_list **list);
void	reverse_rotate(t_list **list);
void	push(t_list **list, t_list **list2);
void	display_list(t_list *a);
int		is_sorted(t_list *b, t_list *b2);
int		contain_duplicates(t_list *a);
int		size(t_list *lst);
int		get_smallest(t_list *lst);
void	assign_stack(t_list **list, int smallest);
int		radix(int pos, int bit);
int		radix_fin(t_list *a, int bit);
int		get_dir(t_list *a, int pos, int size, int reset);
int		step_one(int *first, t_list *a, int bit, int *step);
int		mini_sort(t_list *a, t_list *b);
#endif
