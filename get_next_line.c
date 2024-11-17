/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:52:57 by andcarva          #+#    #+#             */
/*   Updated: 2024/11/14 14:01:23 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	int				bytes_read;
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	line = NULL;
	while (buffer[0] || bytes_read > 0)
	{
		line = ft_strjoin(line, buffer);
		if(!line)
			return(NULL);
		clean_buff(buffer);
		if (line[ft_linelen(line) - 1] == '\n')
			return (line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
	}
	return (line);
}

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    char *line;
	
	line = get_next_line(fd);
    if (fd == -1)
    {
        printf("Error opening file");
        return 1;
	}
    while (line != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}