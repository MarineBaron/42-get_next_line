/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:31:04 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/27 11:42:27 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int		put_error(char *str)
{
	ft_putendl((const char*) str);
	return (1);
}

int		gnl_exit(int fd, char *str)
{
	if (str)
		free(str);
	if (-1 == close(fd))
		return (put_error("File can't be closed !"));
	return (0);
}

int		main(int argc, char *argv[])
{
	char	*str;
	int		fd;
	int		gnl;

	if (argc < 2)
		return (put_error("We need one file !"));
	if (!(fd = open(argv[1], O_RDONLY)))
		return (put_error("File can't be opened !"));
	str[0] = '\0';
	while(1)
	{
		gnl = get_next_line(fd, &str);
		if (gnl == -1)
			return (put_error("Error in GNL"));
		if (gnl)
			ft_putendl(str);
		else
			return (gnl_exit(fd, str));
	}
	return (0);
}
