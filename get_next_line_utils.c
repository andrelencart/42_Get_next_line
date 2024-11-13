/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:48:37 by andcarva          #+#    #+#             */
/*   Updated: 2024/11/13 17:11:06 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*newstr;
	size_t		cnt1;
	size_t		cnt2;

	cnt1 = 0;
	newstr = malloc(sizeof(char) * ((ft_linelen(s1) + ft_linelen(s2)) + 1));
	if (!newstr)
		return (NULL);
	while (s1 && s1[cnt1] != '\0')
	{
		newstr[cnt1] = s1[cnt1];
		cnt1++;
	}
	cnt2 = 0;
	while (s2 && s2[cnt2] != '\n')
	{
		newstr[cnt1 + cnt2] = s2[cnt2];
		cnt2++;
	}
	newstr[cnt1 + cnt2] = '\0';
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
