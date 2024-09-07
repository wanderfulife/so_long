# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jowander <Jowander@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 14:30:29 by jowander          #+#    #+#              #
#    Updated: 2024/09/05 15:27:20 by Jowander         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_DIR = srcs
INC_DIR = includes
SRCS = $(SRC_DIR)/ft_format.c \
       $(SRC_DIR)/ft_numbers.c \
       $(SRC_DIR)/ft_string.c \
       $(SRC_DIR)/ft_utils.c \
       $(SRC_DIR)/ft_printf.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIE
RM = rm -f

.c.o:
	$(CC) -c $(CFLAGS) -I$(INC_DIR) $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re