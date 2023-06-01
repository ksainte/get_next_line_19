/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksainte <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:05:28 by ksainte           #+#    #+#             */
/*   Updated: 2023/05/04 17:05:38 by ksainte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s
{
	int	len;
}		t_s;

int		ft_printf(const char *s, ...);
int		ft_write_str(char *str);
int		ft_len_print_nbr(int nbr);
int		ft_putchar(int c);
int		handle_ptr(unsigned long ptr, int c);
char	ft_hexadecimal(long int n, char c);
int		ft_putnbr_u(unsigned int n);
int		arg_search(va_list arg, char str, t_s *s);
int		text_read(t_s *s, char str);
int		ft_printf(const char *str, ...);

#endif
