/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:52:57 by andcarva          #+#    #+#             */
/*   Updated: 2024/11/12 19:19:16 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <fcntl.h>
#define BUFFER_SIZE 2048

char	*get_next_line(int fd)
{
	int		bytes_read;
	char	temp_buffer[BUFFER_SIZE + 1];
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	line = (char *)malloc(sizeof(char) * (bytes_read + 1));
	if (!line)
		return (NULL);
	while (bytes_read > 0)
	{
		
	}
	return (line);
}

int	main(void)
{
	
}
