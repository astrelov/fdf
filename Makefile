# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/01 16:22:59 by astrelov          #+#    #+#              #
#    Updated: 2018/08/04 15:11:06 by astrelov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =          	fdf

SRC =           	src/main.c

OBJS =         		$(patsubst src/%.c, $(OBJDIR)%.o, $(SRC))

OBJDIR =        	obj/

HEADERS =			-I ./includes -I /usr/local/include

LIBFTFLAG =			-L ./libft -lft

MLXFLAG =			-lmlx -framework OpenGL -framework AppKit

all:				objdir $(NAME)

$(NAME):        	$(OBJS)
					gcc -o $(NAME) $(OBJS) $(LIBFTFLAG) $(MLXFLAG)

$(OBJDIR)%.o:		src/%.c
					gcc $(CFLAGS) $(HEADERS) -c $< -o $@

objdir:
					mkdir -p $(OBJDIR)

clean:
					rm -rf $(OBJDIR)

fclean:
					rm -rf $(OBJDIR)
					rm -f $(NAME)

re:					fclean all
