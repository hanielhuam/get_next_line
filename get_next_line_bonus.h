/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:55:03 by hmacedo-          #+#    #+#             */
/*   Updated: 2025/01/11 23:03:26 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_line
{
	char			*str;
	size_t			size;
	char			ok;
	struct s_line	*next;
}					t_line;

char	*get_next_line(int fd);
t_line	*creat_t_line(char *str, ssize_t size, char ok);
int		modify_line(t_line *line, char *buffer, size_t len, char ok);

#endif
