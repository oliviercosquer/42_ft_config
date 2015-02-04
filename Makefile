# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olivier <olivier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 18:12:20 by ocosquer          #+#    #+#              #
#    Updated: 2015/02/04 22:43:08 by olivier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_config.a
CC = gcc
FLAGS = -Wall -Werror -Wextra -m32
INC_PATH = -I./includes \
			-I./lib/42_libft/includes \
			-I./lib/42_get_next_line/includes
SRC_PATH = ./src
SRC_FILES = ft_config.c ft_config2.c ft_config_add.c \
			ft_config_check.c ft_config_debug.c ft_config_del.c \
			ft_config_get.c ft_config_get2.c ft_config_parse.c \
			ft_config_parse_path.c ft_config_read.c
OBJ = $(SRC_FILES)
SRCS = $(patsubst %, $(SRC_PATH)/%, $(SRC_FILES))
all: ${NAME}

${NAME}:
	@echo Compilation de $(NAME)
	$(CC) $(FLAGS) $(INC_PATH) -c $(SRCS)
	ar rc $(NAME) $(OBJ:.c=.o)
	@echo Compilation de $(NAME) terminée

clean:
	@rm -f $(OBJ:.c=.o)

fclean: clean
	@rm -f ${NAME}

re: fclean all
