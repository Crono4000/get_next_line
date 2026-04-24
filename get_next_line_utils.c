/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:05:14 by afranco-          #+#    #+#             */
/*   Updated: 2026/04/24 18:55:53 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_search(const char *s, char c)
{
	int		kk;

	kk = 0;
	while (s[kk])
	{
		if (s[kk] == c)
			return ((char *)(s + kk));
		kk++;
	}
	if (s[kk] == c)
		return ((char *)(s + kk));
	return (NULL);
}

size_t	special_strlen(const char *str, char *set)
{
	unsigned int	current;

	current = 0;
	while (!str_search(set, str[current]))
		current++;
	return (current);
}

char	*strjoin_newline(char const *s1, char const *s2)
{
	char	*str;
	int		index1;
	int		index2;

	str = malloc(sizeof(char) * (special_strlen(s1, "\n") + special_strlen(s2, "\n") + 2));
	if (str == NULL)
		return (NULL);
	index1 = 0;
	index2 = 0;
	while (s1[index1] != '\n' && s1[index1])
	{
		str[index1] = s1[index1];
		index1++;
	}
	while (s2[index2] != '\n' && s2[index2])
	{
		str[index1 + index2] = s2[index2];
		index2++;
	}
	str[index1 + index2] = '\n';
	str[index1 + index2 + 1] = '\0';
	return (str);
}

char	*my_strdup(const char *src)
{
	char	*new;
	int		size;
	int		ii;

	size = special_strlen(src, "");
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

/*int main()
{
	printf("%s", strjoin_newline("yyyysh\njjjj", "google"));
	printf("%s", strjoin_newline("ola ", "google"));
	printf("%s", strjoin_newline("ola \n", "goo\ngle"));
}*/