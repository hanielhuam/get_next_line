/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hmacedo-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:46:34 by hmacedo-          #+#    #+#             */
/*   Updated: 2024/12/17 16:14:06 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	return ("asdf");
}

int	main(void)
{
	int	fd;

	fd = open("testc.txt", O_WRONLY);
	get_next_line(fd);
	close(fd);
	return (0);
}
