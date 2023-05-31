/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:47:16 by ksainte           #+#    #+#             */
/*   Updated: 2023/05/23 14:47:17 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_n_present(char *left_str, char c)
{
    int i;

    i = 0;
    if (!left_str)
		return (0);
    while (left_str[i] != '\0')
    {
        if (left_str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

// static char	*ft_append(char *dest, char const *src)
// {
// 	size_t	i;
//     size_t  j;
// 	size_t	len;

// 	i = 0;
// 	while (dest[i] != '\0')
// 		i++;
//     j = 0;
// 	while (src[j])
// 		dest[i++] = src[j++];
// 	dest[i] = '\0';
// 	return (dest);
// }

static char	*ft_append(char *dest, char const *src)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (dest[i])
		i++;
	len = i;
	i = 0;
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *left_str,char *buff)
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
	ms = ft_append(ms, left_str);
	ms = ft_append(ms, buff);
    free(left_str);
    //free(buff);
	return (ms);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst2;
	char	*src2;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst2 = (char *)dst;
	src2 = (char *)src;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
    free(src2);
	return (dst2);
}

