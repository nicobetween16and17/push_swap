/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:54:05 by niespana          #+#    #+#             */
/*   Updated: 2022/04/16 13:54:15 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *line, int i)
{
	while (line[i] != '\0')
	{
		if (line[i++] == '\n')
			line[i] = '\0';
	}
	return (line);
}

static int	ft_set_j(int *j, int n)
{
	*j = n;
	return (n);
}

static int	ft_init_line(char *memory, char **line)
{
	*line = malloc(1);
	if (!(*line))
		return (1);
	(*line)[0] = 0;
	if (memory[0] != 0)
	{
		ft_get_start(memory);
		ft_strdup_gnl(line, memory);
		if (!(*line))
			return (1);
	}
	return (0);
}

static int	ft_loop_instructions(char *reader, char **line, int j, char *memory)
{
	reader[j] = '\0';
	ft_strcpy_gnl(memory, reader);
	if (!ft_strjoin_gnl(line, reader))
	{
		free(*line);
		return (1);
	}
	if (!(*line))
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	memory[OPEN_MAX][1 + 1];
	char		reader[1 + 1];
	char		*line;
	int			j;

	if (fd < 0 || ft_init_line(memory[fd], &line))
		return (NULL);
	if (does_contain(line, '\n'))
		return (get_line(line, 0));
	while (ft_set_j(&j, read(fd, reader, 1)) && j > 0)
	{
		if (ft_loop_instructions(reader, &line, j, memory[fd]))
			return (NULL);
		if (does_contain(line, '\n'))
			return (get_line(line, 0));
	}
	if (memory[fd][0] != 0)
	{
		memory[fd][0] = 0;
		return (get_line(line, 0));
	}
	free(line);
	return (NULL);
}
