# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/01 16:22:59 by astrelov          #+#    #+#              #
#    Updated: 2018/08/16 12:29:40 by astrelov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Reset
Color_Off=\033[0m

# Regular Colors
Black=\033[0;30mk
Red=\033[0;31md
Green=\033[0;32mn
Yellow=\033[0;33mw
Blue=\033[0;34me
Purple=\033[0;35me
Cyan=\033[0;36mn
White=\033[0;37me

# Bold
BBlack=\033[1;30m
BRed=\033[1;31m
BGreen=\033[1;32m
BYellow=\033[1;33m
BBlue=\033[1;34m
BPurple=\033[1;35m
BCyan=\033[1;36m
BWhite=\033[1;37m

NAME =          	fdf

SRC =           	src/main.c \
					src/render.c \
					src/parse_file.c \
					src/handle_events.c \
					src/rotations.c \
					src/calculate_2d.c \
					src/calculate_3d_map.c \
					src/view_change_actions.c \
					src/print_info.c \
					src/image.c \
					src/sundry.c

OBJS =         		$(patsubst src/%.c, $(OBJDIR)%.o, $(SRC))

OBJDIR =        	obj/

HEADER =			./includes/fdf.h

HEADERS =			-I ./includes -I /usr/local/include

LIBFTFLAG =			-L ./libft -lft

CFLAGS =			-Wall -Wextra -Werror

MLXFLAG_MAC =		-lmlx -framework OpenGL -framework AppKit

MLXFLAG_LINUX =		-lmlx -lXext -lX11

all:				objdir
					@make -C libft/
					@make $(NAME)

LINK_MAC:
					@printf "\n$(BCyan)Linking with MAC OS flags$(Color_Off)"
					@gcc -o $(NAME) $(OBJS) $(LIBFTFLAG) $(MLXFLAG_MAC) -lm

LINK_LINUX:
					@printf "\n$(BCyan)Linking with Linux flags$(Color_Off)"
					@gcc -o $(NAME) $(OBJS) $(LIBFTFLAG) $(MLXFLAG_LINUX) -lm

$(NAME):        	$(OBJS)
					@make LINK_MAC
					@printf "\n\033[0;32mfdf: DONE\033[0m\n"

$(OBJDIR)%.o:		src/%.c $(HEADER)
					@gcc $(CFLAGS) $(HEADERS) -c $< -o $@
					@printf "."

objdir:
					@mkdir -p $(OBJDIR)

clean:
					@make --directory=./libft clean
					@rm -rf $(OBJDIR)
					@printf "\033[0;32mfdf objects: removed\033[0m\n"

fclean:
					@make --directory=./libft fclean
					@rm -rf $(OBJDIR)
					@rm -f $(NAME)
					@printf "\033[0;32mfdf objects: removed\033[0m\n"
					@printf "\033[0;32mfdf: removed\033[0m\n"

re:					fclean all
