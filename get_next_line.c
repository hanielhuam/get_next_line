/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:46:34 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/22 19:46:18 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*verify_line(t_line *line)
{
	t_line	*temp;
	char	*l;

	l = NULL;
	temp = line;
	if (line->ok)
	{
		l = line->str;
		line = line->next;
		free(temp);
	}
	return (l);
}

int	create_line(t_line *line, char *buffer, size_t len, char ok)
{
	size_t		count;
	char		*str;

	count = 0;
	if (line->str)
		len += line->size;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (-1);
	while (count < line->size)
	{
		str[count] = (line->str)[count];
		count++;
	}
	while (count < len)
		str[count++] = *buffer++;
	str[count] = '\0';
	free(line->str);
	line->str = str;
	line->size = len;
	line->ok = ok;
	return (0);
}

int	put_new_line(t_line *line, char *buffer, size_t len)
{
	unsigned int	i;
	unsigned int	init;
	t_line			*temp;

	init = 0;
	i = 0;
	while (i < len)
	{
		if (buffer[i] == '\n')
			{
				if (create_line(line, &buffer[init], i - init + 1, 1))
					return (-1);
				init = i + 1;
				temp = creat_t_line(NULL, 0, 0);
				if (!temp)
					return (-1);
				line->next = temp;
				line = temp;
			}
		i++;
	}
	if (!line->ok)
	{
		if (create_line(line, &buffer[init], i - init, 0))
			return (-1);
	}
	return (0);
}

int	read_file(t_line *line, int fd)
{
	char	*buffer;
	ssize_t	lenght;
	t_line	*temp;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (-1);
	temp = line;
	while (!line->ok)
	{
		lenght = read(fd, buffer, BUFFER_SIZE);
		if (lenght <= 0)
		{
			free(buffer);
			if (lenght < 0)
				return (-1);
			temp->ok = 1;
			return (0);
		}
		if (put_new_line(temp, buffer, (size_t) lenght))
		{
			free(buffer);
			return (-1);
		}
	}
	free(buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_line	**line;
	char			*l;
	t_line			*temp;

	if (!line)
	{
		temp = creat_t_line(NULL, 0, 0);
		if (!temp)
			return (NULL);
		line = &temp;
	}
	l = verify_line(*line);
	if (l)
		return (l);
	temp = *line;
	if (read_file(*line, fd))
		return (NULL);
	if (!temp)
		return (NULL);
	l = temp->str;
	line = &(temp->next);
	free(temp);
	return (l);
}

#include <fcntl.h>
//#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("teste.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
