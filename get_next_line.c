/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:19:50 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/27 12:28:04 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_endl(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static void	get_new_buf(char **str, char buf[], int res)
{
	char	*tmp;

	tmp = *str;
	*str = ft_strnew(ft_strlen(*str) + res + 1);
	*str[0] = '\0';
	ft_strcpy(*str, tmp);
	ft_strncat(*str, buf, res);
	free(tmp);
}

static int	get_new_str(char *str)
{
	int		endl;

	if (ft_strchr(str, '\n'))
	{
		ft_strcpy(str, str + get_endl(str) + 1);
		return (1);
	}
	endl = get_endl(str);
	if (endl)
	{
		ft_strcpy(str, str + endl);
		return (1);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUF_SIZE + 1];
	static char	*strs[FD_NB];
	char		*str;
	int			res;

	if (fd < 0 || BUF_SIZE < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!strs[fd] &&!(strs[fd] = ft_strnew(0)))
		return (-1);
	str = strs[fd];
	res = 0;
	while ((!ft_strchr(str, '\n')) && (res = read(fd, buf, BUF_SIZE)) > 0)
	{
			buf[BUF_SIZE] = '\0';
			get_new_buf(&str, buf, res);
	}
	if (res == -1)
		return (-1);
	*line = ft_strsub(str, 0, get_endl(str));
	strs[fd] = str;
	return (get_new_str(strs[fd]));
}
