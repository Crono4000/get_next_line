/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:05:14 by afranco-          #+#    #+#             */
/*   Updated: 2026/04/23 16:37:04 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	current;

	current = 0;
	while (str[current] != '\0')
	{
		current++;
	}
	return (current);
}

char	*strjoin_newline(char const *s1, char const *s2)
{
	char	*str;
	int		index1;
	int		index2;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	index1 = 0;
	index2 = 0;
	while (s1[index1] != '\n')
	{
		str[index1] = s1[index1];
		index1++;
	}
	while (s2[index2])
	{
		str[index1 + index2] = s2[index2];
		index2++;
	}
	str[index1 + index2] = '\n';
	str[index1 + index2 + 1] = '\0';
	return (str);
}

char	*str_search(const char *s, int c)
{
	int		kk;
	char	ch;

	ch = c;
	kk = 0;
	while (s[kk])
	{
		if (s[kk] == ch)
			return ((char *)(s + kk));
		kk++;
	}
	return (NULL);
}

char	*my_strdup(const char *src)
{
	char	*new;
	int		size;
	int		ii;

	size = ft_strlen(src);
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	ii = 0;
	while (ii < size + 1)
	{
		new[ii] = src[ii];
		ii++;
	}
	return (new);
}
