/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 16:39:20 by lugonzal          #+#    #+#             */
/*Updated: 2021/07/20 16:39:22 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[2048];
	char		*buffer;
	ssize_t		size;

	if (fd == 2 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	size = 1;
	while (size > 0 && !ft_strchr(str[fd], '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		str[fd] = strjoin(str[fd], buffer);
	}
	free(buffer);
	line = cutstr(str[fd], 0, len_c(str[fd], 10) + 1, 0);
	str[fd] = cutstr(str[fd], len_c(str[fd], 10) + 1,
			len_c(str[fd], 0) - len_c(line, 0), 1);
	return (ret_val(size, line));
}
