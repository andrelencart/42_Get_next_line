/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:48:37 by andcarva          #+#    #+#             */
/*   Updated: 2024/11/21 18:50:11 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char		*newstr;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	newstr = malloc(sizeof(char) * ((ft_linelen(str1) + ft_linelen(str2)) + 1));
	if (!newstr)
		return (free(str1), NULL);
	while (str1 && str1[i] != '\0')
	{
		newstr[i] = str1[i];
		i++;
	}
	while (str2[j] && str2[j] != '\n')
	{
		newstr[i + j] = str2[j];
		j++;
	}
	if (str2[j] == '\n')
		newstr[i + j++] = '\n';
	newstr[i + j] = '\0';
	free(str1);
	return (newstr);
}

size_t	ft_linelen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	if (str && str[len] == '\n')
		len++;
	return (len);
}

void	ft_buff_move(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[j] != '\0')
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}