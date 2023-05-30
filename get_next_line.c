/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:46:50 by ksainte           #+#    #+#             */
/*   Updated: 2023/05/23 14:46:52 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**	GET_NEXT_LINE
*	-------------
*	DESCRIPTION
*	This function takes an opened file descriptor and returns its next line.
*	This function has undefined behavior when reading from a binary file.
*	PARAMETERS
*	#1. A file descriptor 
*	RETURN VALUES
*	If successful, get_next_line returns a string with the full line ending in
*	a line break (`\n`) when there is one. 
*	If an error occurs, or there is nothing more to read, it returns NULL.*/

#include "get_next_line.h"
#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

int ft_n_present(char *left_str, char c)
{
    while ( left_str != '\0')
    {
        if ( left_str == c)
            return ;
        i++;
    }
    return (0);
}

static char	*ft_append(char *left_str, char const *buff)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (left_str[i])
		i++;
	len = i;
	i = 0;
	while (buff[i] != '\0')
	{
		left_str[len + i] = buff[i];
		i++;
	}
	left_str[len + i] = '\0';
	return (buff);
}

char	*ft_strjoin(char const *left_str, char const *buff)
{
	size_t	len_s2;
	size_t	len_s1;
	char	*ms;

	if (!left_str || !buff)
		return (NULL);
	len_s1 = ft_strlen(left_str);
	len_s2 = ft_strlen(buff);
	ms = (char *)malloc(sizeof(*ms) * (len_s1 + len_s2 + 1));
	if (ms == NULL)
		return (NULL);
	*ms = 0;
	ms = ft_append(ms, s1);
	ms = ft_append(ms, s2);
	return (ms);
}
char *ft_read_to_left_str(int fd, char *left_str)
{
    char    *buff;
    int     nb_bytes_to_read;

    nb_bytes_to_read = -1;
    while(!ft_n_present(left_str,'\n') && nb_bytes_toread != 0)
    {
        nb_bytes_toread = read(fd, buff, BUFFER_SIZE);
        if (nb_bytes_to_read == -1)
        {
            printf("Read error!\n");
			return (0);
        }
        buff[nb_bytes_to_read] = '\0';
        left_str = ft_strjoin(left_str, buff);
    }
    free(buff);
    return (left_str);
}

char *print_line()
char *get_next_line(int fd)
{
    static char *left_str;
    char    *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
    left_str = ft_read_to_left_str(fd, left_str);
    line = print_line(left_str);
}

int main()
{
    int fd;
    char    *line;
    int i;

    fd = open("test.txt", O_RDONLY);
    i = 0;
    while (i < 10)
    {
        line = get_next_line(fd);
        printf("%s",line);
        i++;
    }
    close(fd);
    return (0);

}

/*

--------------\n
-------------'\0' str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';

ou 

--------------\n  i
str------------'\0' str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));

--------------------------------------------'\0' o bytes left 

avant -----------\n ----------'\0' fd
apres \n new str ------- '\0' fd

 */