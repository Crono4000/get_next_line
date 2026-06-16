/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:57:32 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/16 13:36:57 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes;
	char		*result;

	trimbuffer(buffer, &bytes);
	result = strjoin_newline("", buffer, 0);
	if (result == NULL || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes && !str_search(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(result), NULL);
		if (bytes)
		{
			buffer[bytes] = '\0';
			result = strjoin_newline(result, buffer, 1);
			if (result == NULL)
				return (NULL);
		}
	}
	if (normal_strlen(buffer) == 0)
		return (free(result), NULL);
	return (result);
}

/*int main()
{
	char *teste = my_strdup("yyyysh\njjjj");
	printf("teste:%s\n", teste);
	trimbuffer(teste);
	printf("teste:%s\n", teste);
}*/
