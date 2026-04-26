/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:57:32 by afranco-          #+#    #+#             */
/*   Updated: 2026/04/26 00:50:38 by afranco-         ###   ########.fr       */
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
		newline++;
		//printf("newline:%s\n", newline);
		while (newline[i++])
			buffer[i - 1] = newline[i - 1];
		i--;
		//printf("trim1:%s\n", buffer);
		//printf("trim2:%s\n", buffer + i);
	}
	while (buffer[i++])
		buffer[i - 1] = '\0';
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes;
	char		*result;

	buffer[BUFFER_SIZE] = '\0';
	trimbuffer(buffer);
	//printf("InitialBuffer:%s;\n", buffer);
    result = strjoin_newline("", buffer);
	if (result == NULL)
		return (NULL);
	bytes = 1;
    //printf("buffer:%s; result:%s;\n", buffer, result);
	while (bytes && !str_search(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		//printf("buffer:%s; result:%s;\n", buffer, result);
		if (bytes == -1)
			return (free(result), NULL);
        if (bytes)
            result = strjoin_newline(result, buffer);
	}
    //printf("FinalBuffer:%s;\n", buffer);
	if (special_strlen(buffer, "") == 0)
		return (NULL);
	if (!str_search(result, '\n'))
		return (strjoin_newline(result, "\n"));
	return (result);
}

/*int main()
{
	char *teste = my_strdup("yyyysh\njjjj");
	printf("teste:%s\n", teste);
	trimbuffer(teste);
	printf("teste:%s\n", teste);
}*/