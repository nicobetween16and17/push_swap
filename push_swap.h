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
int 	contain_duplicates(t_list *a);
void	put_previous(t_list **a);
int 	size(t_list *lst);
int		get_direction(t_list *lst);
int		get_smallest(t_list *lst);
float	get_coef(t_list *a);
t_list	*duplicate(t_list *a);
int		get_nearest_smallest(t_list *a);
int		contain(t_list *a, int n);
int		get_best_ope(t_list *a, int n);
int		is_inverse_sorted(t_list *b);
int		get_biggest(t_list *lst);
int		is_soft_sorted(t_list *b, int sens);
int		is_favorable(t_list *list, int ope, int to_push);
int		sort_this(t_list *b, int new, t_list *a, int n_smol);
int		get_direction_b(t_list *b, int n);
int		must_still_push(t_list *a, t_list *b);
int		rotate_a(t_list *a);
int		rotate_b(t_list *b);
int 	get_best_bope(t_list *b, int smol, int ope, int i);

#endif
