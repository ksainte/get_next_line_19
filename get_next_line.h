/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:02 by ksainte           #+#    #+#             */
/*   Updated: 2023/05/23 14:47:04 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char    *print_line(char *left_str);
char    *ft_read_to_left_str(int fd, char *left_str);
char    *new_left_str(char *left_str);
char    *get_next_line(int fd);
int ft_strlen(char *str);
int ft_n_present(char *left_str, char c);
static char *ft_append(char *dest, char const *src);
char	*ft_strjoin(char *left_str, char *buff);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif