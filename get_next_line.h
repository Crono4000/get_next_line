/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:33:31 by afranco-          #+#    #+#             */
/*   Updated: 2026/06/10 20:46:03 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t	special_strlen(const char *str);
size_t	normal_strlen(const char *str);
char	*str_search(const char *s, char c);
char	*strjoin_newline(char *s1, char const *s2, int free_s1);
char	*get_next_line(int fd);
void	trimbuffer(char *buffer, int *bytes);

#endif
