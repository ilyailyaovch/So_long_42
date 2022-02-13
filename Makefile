# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 09:09:11 by pleoma            #+#    #+#              #
#    Updated: 2022/02/13 10:30:16 by pleoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB_FLAGS = -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit

HEADER = includes/so_long.h
MINILIBX = libmlx.a
OBJ = $(patsubst %.c,%.o,$(SRC))
SRC	=		src//so_long.c \
			src//ft_map_create.c \
			src//ft_map_create_utils.c \
			src//lib_utils_1.c \
			src//lib_utils_2.c \
			src//lib_utils_3.c \
			src//keys_1.c \
			src//keys_2.c \
			src//mlx_func.c \
			src//movements.c \
			src//clear.c \
			src//gnl.c \

.c.o:
	@$(CC) $(FLAGS) -Imlx -c $< -o $@
	@echo "Compiling $@"

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@make -C minilibx
	@cp minilibx/libmlx.a .
	@$(CC) $(FLAGS) $(LIB_FLAGS) $(OBJ) -o $@
	@echo "Compiling $@"

clean :
	@rm -f $(OBJ)
	@make clean -C minilibx
	@echo "Removing obj"

fclean : clean
	@rm -f $(NAME)
	@rm -f libmlx.a
	@echo "Removing all"

re : fclean all

.PHONY : all clean fclean re bonus