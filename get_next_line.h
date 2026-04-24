/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afranco- <afranco-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:33:31 by afranco-          #+#    #+#             */
/*   Updated: 2026/04/24 18:56:23 by afranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t	special_strlen(const char *str, char *set);
char	*str_search(const char *s, char c);
char	*my_strdup(const char *src);
char	*strjoin_newline(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
