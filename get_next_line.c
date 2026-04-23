/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:57:32 by afranco-          #+#    #+#             */
/*   Updated: 2026/04/23 16:40:46 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	trimbuffer(char *buffer)
{
	char	*newline;
	int		i;

	i = 0;
	newline = str_search(buffer, '\n');
	if (newline)
	{
		while (newline[i++])
			buffer[i - 1] = newline[i - 1];
		i--;
	}
	while (buffer[i++])
		buffer[i - 1] = '\0';
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes;
	char		*result;

	trimbuffer(buffer);
	result = my_strdup("\n");
	if (result == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes)
	{
		if (str_search(buffer, '\n'))
			break ;
		result = strjoin_newline(result, buffer);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(result), NULL);
	}
	if (!result[1])
		return (NULL);
	return (result);
}
