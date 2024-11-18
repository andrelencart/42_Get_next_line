/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:52:57 by andcarva          #+#    #+#             */
/*   Updated: 2024/11/18 18:12:52 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
		{
			free(line);
			return (NULL);
		}
		clean_buff(buffer);
		if (line[ft_linelen(line) - 1] == '\n')
			return (line);
	}
	return (line);
}

/* int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    char *line;
	
    if (fd == -1)
    {
        printf("Error opening file");
        return 1;
	}
    while (line != NULL)
    {
		line = get_next_line(fd);
        printf("line: %s", line);
    	free(line);
    }
    close(fd);
    return 0;
} */