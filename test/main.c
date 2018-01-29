/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:31:04 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/29 13:28:11 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int		put_error(char *str)
{
	ft_putendl(str);
	return (1);
}

int		gnl_exit(int fd, char *str)
{
	if (str)
		free(str);
	if (-1 == close(fd))
		return (put_error("File can't be closed !"));
	return (1);
}

int		main(int argc, char *argv[])
{
	char	*str[10];
	int		fd[10];
	int		gnl[10];
	int		is_open;
	int		i;
	int		j;

	if (argc < 2 || argc > 11)
		return (put_error("We need one file !"));
	i = 0;
	while (i < argc)
	{
		if (!(fd[i] = open(argv[i + 1], O_RDONLY)))
			return (put_error("File can't be opened !"));
		if (!(str[i] = ft_strnew(0)))
			return (put_error("Malloc Error"));
		is_open++;
		i++;
	}
	while (is_open)
	{
		gnl[i] = get_next_line(fd[i], &str[i]);
		if (gnl[i] == -1)
			return (put_error("Error in GNL"));
		if (gnl[i])
		{
			ft_putendl(str[i]);
		}
		else
		{
			if (!(gnl_exit(fd[i], str[i])))
				return (1);
			is_open--;
		}
	}
	return (0);
}
