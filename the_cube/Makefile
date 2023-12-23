# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 14:47:42 by hed-dyb           #+#    #+#              #
#    Updated: 2023/12/23 15:39:17 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

HEADER = header.h

CC = cc 

RM = rm - f 

FLAGS = -Wall -Wextra -Werror -fsanitize=address #-Imlx

#LINKING_FLAGS = -lmlx -framework OpenGL -framework AppKit

# SRC_PARCING = $(addprefix parcing/, example.....)
# SRC_RAY_CASTING = $(addprefix ray_casting/, example.....)
# SRC_RENDERING = $(addprefix rendering/, example.....)

SRC = main.c test.c #$(SRC_PARCING) $(SRC_RAY_CASTING) $(SRC_RENDERING)

OBJECTS = ./obj

OBJ = $(addprefix $(OBJECTS)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
$(OBJECTS)/%.o : %.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all