/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:57:32 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/09 01:39:41 by afranco-         ###   ########.fr       */
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
	while (i++ <= BUFFER_SIZE)
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
    result = strjoin_newline("", buffer, 0);
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
        //printf("buffer:%s;\n", buffer);
        if (bytes)
        {
            buffer[bytes] = '\0';
            result = strjoin_newline(result, buffer, 1);
        }
	}
    //printf("FinalBuffer:%s;\n", buffer);
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
