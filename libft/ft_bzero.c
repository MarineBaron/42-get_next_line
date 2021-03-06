/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:36:17 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/26 13:22:28 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *b, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		((unsigned char*)b)[i] = '\0';
		i++;
	}
}
