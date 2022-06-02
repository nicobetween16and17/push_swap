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
# include <stdlib.h>
typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*previous;
	int				nb;
}	t_list;

t_list	*new(int nb, t_list *next, t_list *previous);
void	add_front(t_list **start, t_list *new);
void	add_back(t_list **start, t_list *new);
void	swap(t_list *swap1, t_list *swap2);
t_list	*get_last(t_list *start);
void	free_lst(t_list *start);

#endif
