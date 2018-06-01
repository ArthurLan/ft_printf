# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 21:05:53 by alanter           #+#    #+#              #
#    Updated: 2018/06/01 18:53:03 by alanter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDE = ./includes/
SRCS_DIR = ./srcs/
O_DIR = ./ofiles/
FILES = ft_printf convert flags
LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, $(O_DIR)%.o, $(FILES))

all : $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft/

$(OFILES): $(CFILES)
	gcc $(CFLAGS) -c -I$(INCLUDE) $(CFILES)
	mv *.o $(O_DIR)

$(NAME): $(LIBFT) $(OFILES)
	cp ./libft/libft.a ./$(NAME)
	ar -rc $(NAME) $(OFILES)
	ranlib $(NAME)

clean:
	rm -f $(OFILES)
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft/ 

re: fclean all
