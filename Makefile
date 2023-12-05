# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperrein <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 12:19:04 by aperrein          #+#    #+#              #
#    Updated: 2023/04/10 09:18:40 by aperrein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

OBJ_DIR =	OBJ/

SRC_DIR =	SRC/

SRC	=	error.c main.c map_check.c map_init.c set_pos.c view.c window.c

OBJ	=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

RM	=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

all     :       $(OBJ_DIR) $(NAME)
	
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		gcc $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
#		@./srct/map
		mkdir $(OBJ_DIR)


$(NAME)	:	make_lib $(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a minilibx/libmlx.a -lX11 -lXext


make_lib :
		@make -s -C libft/

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re 	:	fclean $(NAME)
