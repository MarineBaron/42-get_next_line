/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:31:04 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/29 18:24:46 by mbaron           ###   ########.fr       */
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

int		gnl_exit(int fd, int fdo, char *output_name, char *str)
{
	if (str)
		free(str);
	if (output_name)
		free(output_name);
	if (-1 == close(fd))
		return (put_error("File to read can't be closed !"));
	if (-1 == close(fdo))
		return (put_error("File to write can't be closed !"));
	return (1);
}

int		main(int argc, char *argv[])
{
	char	*str[10];
	char	*output_name[10];
	int		fd[10];
	int		fdo[10];
	int		gnl[10];
	int		is_open;
	int		i;

	if (argc > 11)
		return (put_error("We need one file !"));
	if (argc == 1)
	{
		gnl[0] = -1;
		if (!(str[0] = ft_strnew(0)))
			return (put_error("Malloc Error"));
		ft_putendl("-----> test fd = 0");
		while (gnl[0])
		{
			ft_putstr("Enter a string (terminated by ENTER) : ");
			gnl[0] = get_next_line(0, &str[0]);
			if (gnl[0] == -1)
				return (put_error("Error in GNL"));
			else if (gnl[0])
			{
				ft_putstr("You've entered : ");
				ft_putendl(str[0]);
			}
			else
			{
				if (str[0])
					free(str[0]);
			}
		}
	}
	else
	{
		ft_putendl("-----> test mult fd");
		i = 0;
		is_open = 0;
		while (i < argc - 1)
		{
			if (!(fd[i] = open(argv[i + 1], O_RDONLY)))
				return (put_error("File to read can't be opened !"));
			if (!(output_name[i] = ft_strnew(ft_strlen(argv[i + 1]) + 8)))
				return (put_error("Malloc Error"));
			ft_strcpy(output_name[i], "./samples/output_");
			ft_strcat(output_name[i], ft_strrchr(argv[i + 1], '/') + 1);
			if (!(fdo[i] = open(output_name[i], O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)))
				return (put_error("File to write can't be opened !"));
			if (!(str[i] = ft_strnew(0)))
				return (put_error("Malloc Error"));
			is_open++;
			gnl[i] = -1;
			i++;
		}
		while (is_open)
		{
			i = 0;
			while (i < argc - 1)
			{
				if (gnl[i])
				{
					gnl[i] = get_next_line(fd[i], &str[i]);
					if (gnl[i] == -1)
						return (put_error("Error in GNL"));
					else if (gnl[i])
						ft_putendl_fd(str[i], fdo[i]);
					else
					{
						if (!(gnl_exit(fd[i], fdo[i], output_name[i], str[i])))
							return (1);
						is_open--;
					}
				}
				i++;
			}
		}
	}
	ft_putendl("<----- exit gnl OK");
	return (0);
}
