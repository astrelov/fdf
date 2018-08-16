/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:11:44 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/16 10:56:41 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *str, char delimiter)
{
	int			words;

	words = (*str == delimiter || !*str) ? 0 : 1;
	while (*str)
	{
		if (*str == delimiter && (*(str + 1) != delimiter && *(str + 1)))
			words++;
		str++;
	}
	return (words);
}

static size_t	count_word_len(const char *str, char delimiter)
{
	size_t		word_len;
	char		*next_delimiter_ptr;

	next_delimiter_ptr = ft_strchr(str, delimiter);
	if (next_delimiter_ptr)
		word_len = next_delimiter_ptr - str;
	else
		word_len = ft_strlen(str);
	return (word_len);
}

static char		**fill_split(char **split, const char *str, char delimiter)
{
	int			i;
	int			word_ind;
	size_t		word_len;

	word_ind = -1;
	while (*str)
	{
		if (*str != delimiter && *str)
		{
			word_len = count_word_len(str, delimiter);
			if (!(split[++word_ind] = (char *)ft_memalloc(word_len + 1)))
				return (ft_strsplit_del(&split));
			i = 0;
			while (*str != delimiter && *str)
				split[word_ind][i++] = *str++;
		}
		else
			str++;
	}
	return (split);
}

char			**ft_strsplit(char const *str, char delimiter)
{
	char		**split;
	int			words;

	if (!str)
		return (NULL);
	words = count_words(str, delimiter);
	if (!(split = (char **)ft_memalloc(sizeof(char *) * (words + 1))))
		return (NULL);
	return (fill_split(split, str, delimiter));
}
