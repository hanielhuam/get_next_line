/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:17:51 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/21 20:38:35 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line  *creat_t_line(char *str, ssize_t size, char ok)
{
	t_line	*line;

	line = malloc(sizeof(t_line) * 1);
	if (!line)
		return (NULL);
	line->str = str;
	line->size = size;
	line->ok = ok;
	return (line);
}
