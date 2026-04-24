/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:20:42 by afranco-          #+#    #+#             */
/*   Updated: 2026/04/24 17:41:40 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/*int main(int argc, char **argv)
{
	char	*line;
	int		max;
	int		fd;

	if (argc < 1)
		return (1);
	max = 2;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("line:%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/

int main(int argc, char **argv)
{
	char	*line;
	int		max;
	int		fd;

	if (argc < 1)
		return (1);
	max = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (max < 10)
	{
		printf("line:%s", line);
		line = get_next_line(fd);
		max++;
	}
	close(fd);
	return (0);
}
