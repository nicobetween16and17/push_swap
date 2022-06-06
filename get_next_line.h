/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:54:23 by niespana          #+#    #+#             */
/*   Updated: 2022/04/16 13:54:25 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
int		does_contain(char *s, char c);
int		ft_strjoin_gnl(char **s1, char const *s2);
int		ft_get_start(char *s);
void	ft_strdup_gnl(char **s1, const char *s2);
char	*ft_strcpy_gnl(char *s, char *s2);

#endif