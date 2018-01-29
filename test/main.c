/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:31:04 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/29 10:37:45 by mbaron           ###   ########.fr       */
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

int		gnl_exit(int fd, int fd_output, char *file_name, char *str)
{
	ft_putendl("------- >");
	ft_putstr(file_name);
	ft_putendl(" is writen.");
	if (str)
		free(str);
	if (file_name)
		free(file_name);
	if (-1 == close(fd))
		return (put_error("File to read can't be closed !"));
	if (-1 == close(fd_output))
		return (put_error("File to_write can't be closed !"));
	return (0);
}

int		main(int argc, char *argv[])
{
	char	*str[10];
	int		fd[10];
	int		fd_output[10];
	char	*output_file[10];
	int		gnl[10];
	int		i;

	if (argc < 2 || argc > 10)
		return (put_error("We need between one and 10 file(s) !"));
	i = 0;
	while (i < argc - 1)
	{
		if (!(fd[i] = open(argv[i], O_RDONLY)))
			return (put_error("File to read can't be opened !"));
		output_file[i] = ft_strnew(ft_strlen(argv[i + 1]) + 8);
		ft_strncpy(output_file[i], argv[i + 1], ft_strlen(argv[i + 1]) - ft_strlen(ft_strrchr(argv[i + 1], '/') + 1));
		ft_strcat(output_file[i], "output_");
		ft_strcat(output_file[i], ft_strrchr(argv[i + 1], '/') + 1);
		if (!(fd_output[i] = open(output_file[i], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)))
			return (put_error("File to write can't be opened !"));
		gnl[i] = -1;
		if (!(str[i] = ft_strnew(BUF_SIZE)))
			return (put_error("Malloc Error"));
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (gnl[i])
			{
				ft_putendl("Begin GNL");
				gnl[i] = get_next_line(fd[i], &str[i]);
				ft_putendl("End GNL");
				if (gnl[i] == -1)
					return (put_error("Error in GNL"));
				else if (gnl[i] == 1)
				{
					ft_putstr_fd(str[i], fd_output[i]);
					ft_putendl(str[i]);
					ft_putstr("is written in file : ");
					ft_putendl(output_file[i]);
				}
				else if (gnl_exit(fd[i], fd_output[i], output_file[i], str[i]))
					return (1);
				exit(0);
				/*
				ft_putstr_fd("coucou", fd_output[i]);
				ft_putstr("'");
				ft_putstr("coucou");
				ft_putstr("' is written in file : ");
				ft_putendl(output_file[i]);
				gnl_exit(fd[i], fd_output[i], output_file[i], str[i]);
				gnl[i] = 0;
				*/
			}
			i++;
		}
	}
	return (0);
}
