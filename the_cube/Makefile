# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 14:47:42 by hed-dyb           #+#    #+#              #
#    Updated: 2024/01/17 20:31:08 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEADER = header.h parcing/parcing.h

CC = cc 

RM = rm -f 

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3#-Imlx -g

LINKING_FLAGS = -lmlx -framework OpenGL -framework AppKit

# SRC_PARCING = $(addprefix parcing/, example.....)
SRC_INITIALIZATION = $(addprefix initialization/, initialize.c)
SRC_RAY_CASTING = $(addprefix ray_casting/, raycast.c hit.c castingr1.c castingr2.c castingr3.c castingr4.c cast_utils.c )
SRC_RENDERING = $(addprefix rendering/, render.c position.c events.c collision.c updates.c 3Dwalls.c xtile.c mlx.c)
SRC_MINIMAP = $(addprefix minimap/, mini.c walls.c)

SRC = main.c test.c $(SRC_INITIALIZATION) $(SRC_RENDERING) $(SRC_RAY_CASTING)  $(SRC_PARCING)  $(SRC_MINIMAP)

OBJECTS = ./obj

OBJ = $(addprefix $(OBJECTS)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(LINKING_FLAGS) $(OBJ) -o $(NAME)
	
$(OBJECTS)/%.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS)  -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all