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

char *ft_read_to_left_str(int fd, char *left_str)
{
    char    *buff;
    int     nb_bytes;

    nb_bytes_toread = -1;
    while(!ft_n_present && nb_bytes_toread != 0)
    {
        
    }

}

char *get_next_line(int fd)
{
    static char *left_str;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
    left_str = ft_read_to_left_str(fd, left_str);


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