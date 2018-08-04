/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:32:38 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/20 15:18:00 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_NEW_FT_PRINTF_H
# define FT_PRINTF_NEW_FT_PRINTF_H

# include "../../libft.h"
# include <inttypes.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

# define BASE_STRING		"0123456789abcdef"
# define FLAG_ZERO			(1 << 0)
# define FLAG_MINUS			(1 << 1)
# define FLAG_PLUS			(1 << 2)
# define FLAG_SPACE			(1 << 3)
# define FLAG_HASH			(1 << 4)
# define FLAG_UPPERCASE		(1 << 5)
# define FLAG_GOT_PRECISION	(1 << 6)
# define LENGTH_SHORT_SHORT	(1 << 0)
# define LENGTH_SHORT		(1 << 1)
# define LENGTH_LONG		(1 << 2)
# define LENGTH_LONG_LONG	(1 << 3)
# define LENGTH_INTMAX		(1 << 4)
# define LENGTH_SIZE_T		(1 << 5)

typedef struct				s_pf
{
	unsigned int			flags;
	unsigned int			width;
	unsigned int			precision;
	unsigned int			length;
	unsigned int			base;
	unsigned int			nbr_is_negative;
	char					specifier;
}							t_pf;

typedef struct				s_buff
{
	char					*buff;
	size_t					index;
	size_t					size;
}							t_buff;

int							ft_printf(const char *format, ...);

unsigned int				parse_atoi(char **format);
void						parse(char **format, va_list va, t_pf **arg);
int							parse_flags(char **format, t_pf *arg);
int							parse_width(char **format, va_list va, t_pf *arg);
int							parse_precision(char **format,
											va_list va, t_pf *arg);
int							parse_length(char **format, t_pf *arg);

t_buff						*handle_argument(va_list va, t_pf *pf);
void						handle_number(t_pf *arg, t_buff *arg_buff,
											uintmax_t nbr);
void						handle_char(t_pf *arg, t_buff *arg_buff,
											wchar_t chr);
void						handle_string(t_pf *arg, t_buff *arg_buff,
											wchar_t *str);
void						handle_pointer(t_pf *arg, t_buff *arg_buff,
											size_t nbr);
void						invalid_specifier(t_pf *arg, t_buff *arg_buff);

void						buff_realloc(t_buff *buff);
void						concat_buffs(t_buff *buff, t_buff **arg_buff);
void						push_chars(t_buff *buff, char c, size_t amount);

size_t						wide_char_bytes(wchar_t chr);
void						one_byte(t_buff *arg_buff, unsigned int chr);
void						two_bytes(t_buff *arg_buff, unsigned int chr);
void						three_bytes(t_buff *arg_buff, unsigned int chr);
void						four_bytes(t_buff *arg_buff, unsigned int chr);

void						prepare_string_arg(t_pf *arg);
size_t						wstr_bytes_to_print(t_pf *arg, wchar_t *str);
void						fill_wide_str(t_pf *arg, t_buff *arg_buff,
										wchar_t *str, size_t str_bytes);

char						*stringify_nbr(t_pf *arg, uintmax_t nbr);
void						octal(t_pf *arg, t_buff *arg_buff,
											char *nbr_str, size_t nbr_len);
void						decimal(t_pf *arg, t_buff *arg_buff,
											char *nbr_str, size_t nbr_len);
void						hexademical(t_pf *arg, t_buff *arg_buff,
											char *nbr_str, size_t nbr_len);
void						decimal_pre_padding_helper(t_pf *arg,
						size_t nbr_len, t_buff *arg_buff, char char_to_fill);
#endif
