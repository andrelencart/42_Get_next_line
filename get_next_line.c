/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:52:57 by andcarva          #+#    #+#             */
/*   Updated: 2024/11/19 16:53:58 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	int				i;
	int				len;

	line = NULL;
	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		while (i <= BUFFER_SIZE)
			buffer[i++] = '\0';
		return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(line), NULL);
		len = ft_linelen(line);
		ft_buff_move(buffer);
		if (line[len - 1] == '\n')
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