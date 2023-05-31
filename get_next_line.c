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
#include <fcntl.h>

char *print_line(char *left_str)
{
    size_t i;
    char *str;

    i = 0;
    while (left_str[i] != '\0' && left_str[i] != '\n')
        i++;
    if (left_str[i] == '\0')
        str = (char *)malloc(sizeof(char) * (i + 1));
    if (left_str[i] == '\n')
        str = (char *)malloc(sizeof(char) * (i + 2));
    if (str == NULL)
        return (NULL);
    *str = 0;
    str = ft_memcpy(str, left_str, i);
    if (left_str[i] == '\n')
        str[i] = left_str[i];
    str[i] = '\0';
    free(left_str);
    return (str);
}
char *ft_read_to_left_str(int fd, char *left_str)
{
    char    *buff;
    int     nb_bytes_to_read;

    buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (buff == NULL)
        return (NULL);
    printf("buffmalloc\n");
    nb_bytes_to_read = -1;
    while(!ft_n_present(left_str,'\n') && nb_bytes_to_read != 0)
    {
        nb_bytes_to_read = read(fd, buff, BUFFER_SIZE);
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

char *new_left_str(char *left_str)
{   
    size_t i;
    size_t j;
    char    *str;

    i = 0;
    while (left_str[i] != '\n')
        i++;
    str = (char*)malloc(sizeof(char)*(ft_strlen(left_str) - i + 1));
    if (str == NULL)
        return (NULL);
    i++;
    j = 0;
    while(left_str[i] != '\0')
        str[j++] = left_str[i++];
    str[j] = '\0';
    free(left_str);
    return (str);  
}

char *get_next_line(int fd)
{
    static char *left_str;
    char    *line;

    printf("fdopened\n");
    if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
    left_str = ft_read_to_left_str(fd, left_str);
    line = print_line(left_str);
    left_str = new_left_str(left_str);
    return (line);
}

int main()
{
    int fd;
    char    *line;
    int i;
    
    printf("fdopen\n");
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
str------------'\0' 



str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));

--------------------------------------------'\0' o bytes left 

avant -----------\n ----------'\0' fd
apres \n new str ------- '\0' fd

 */


//  a b c d '\0'
//  0 1 2 3  4
//  i[4] = '\0'