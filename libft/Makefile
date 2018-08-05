# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 21:14:14 by astrielov         #+#    #+#              #
#    Updated: 2018/08/05 16:43:10 by null             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_d_bblsort.c \
		ft_d_minind.c \
		ft_d_sqrt.c \
		ft_errmsg.c \
		ft_gnl.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lf_pow.c \
		ft_ll_fact.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putnstr.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strpbrk.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtolow.c \
		ft_strtoupp.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_printf/src/ft_printf.c \
        ft_printf/src/parse/flags.c \
        ft_printf/src/parse/parse.c \
        ft_printf/src/parse/width.c \
        ft_printf/src/parse/precision.c \
        ft_printf/src/parse/length.c \
        ft_printf/src/handle/handle.c \
        ft_printf/src/handle/number.c \
        ft_printf/src/handle/char.c \
        ft_printf/src/handle/wchar.c \
        ft_printf/src/handle/string.c \
        ft_printf/src/handle/pointer.c \
        ft_printf/src/handle/wstring.c \
        ft_printf/src/handle/invalid_specifier.c \
        ft_printf/src/handle/integer/integer.c \
        ft_printf/src/handle/integer/octal.c \
        ft_printf/src/handle/integer/decimal.c \
        ft_printf/src/handle/integer/hexademical.c \
        ft_printf/src/handle/integer/tmp.c \
        ft_printf/src/helpers/buffer.c \
        ft_printf/src/helpers/push_chars.c

CFLAGS = -Wall -Werror -Wextra

OBJS = $(patsubst %.c, $(OBJDIR)%.o, $(SRCS))

OBJDIR = obj/

HEADER = ./libft.h ./ft_printf/includes/ft_printf.h

HEADERS = -I ./ -I ./ft_printf/includes

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "\n\033[0;32mlibft.a: DONE\033[0m\n"

$(OBJS): | objdir

objdir:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/ft_printf/src/libft
	@mkdir -p $(OBJDIR)/ft_printf/src/parse
	@mkdir -p $(OBJDIR)/ft_printf/src/handle/integer
	@mkdir -p $(OBJDIR)/ft_printf/src/helpers

$(OBJDIR)%.o: %.c $(HEADER)
	@gcc $(CFLAGS) $(HEADERS) -c $< -o $@
	@printf "."

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
	@printf "\033[0;32mlibft objects: removed\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[0;32mlibft.a: removed\033[0m\n"

re: fclean all

.PHONY: clean fclean re all

.NOTPARALLEL: clean fclean re all
