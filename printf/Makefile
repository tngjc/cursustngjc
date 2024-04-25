# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaing <jtaing@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 13:29:25 by jtaing            #+#    #+#              #
#    Updated: 2024/03/19 13:29:28 by jtaing           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -g3
SOURCE = ft_printf.c ft_print_char.c ft_print_nbr.c ft_print_hexa.c \
			ft_print_ptr.c ft_print_str.c 
OBJ = $(SOURCE:.c=.o)
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ) 

fclean : clean
	$(RM) $(NAME)

re: fclean all