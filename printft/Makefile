# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksainte <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 16:35:31 by ksainte           #+#    #+#              #
#    Updated: 2023/05/04 16:35:39 by ksainte          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = Libft

LIBFT = $(LIBFT_PATH)/libft.a

SRCS = ft_printf.c ft_utils.c

OBJS = $(SRCS:%.c=%.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	
	@make -C $(LIBFT_PATH)
	cp $(LIBFT) $(NAME)
	mv $(LIBFT) $(NAME)
	$(AR) $(NAME) $^

%.o: %.c

	$(CC) $(CFLAGS) -c $< -o $@

clean:

	$(RM) $(OBJS)

	@make clean -C $(LIBFT_PATH)

fclean: clean

	$(RM) $(NAME)

	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re

