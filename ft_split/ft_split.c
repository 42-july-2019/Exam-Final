/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:56:27 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 12:20:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_separator(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int		get_nb_words(char *str)
{
	int		result;

	result = 0;
	while (*str)
	{
		if (!is_separator(*str))
			result++;
		while (*str && !is_separator(*str))
			str++;
		while (*str && is_separator(*str))
			str++;
	}
	return (result);
}

int		write_result(char **result, char *str)
{
	int		i;
	int		nb_word;
	int		length;
	
	nb_word = 0;
	while (*str)
	{
		while (is_separator(*str))
			str++;	
		length = 0;
		while (str[length] && !is_separator(str[length]))
			length++;
		if (length != 0)
		{
			nb_word++;
			if(!(result[nb_word - 1] =
						(char *)malloc(sizeof(char) * (length + 1))))
				return (0);
			i = 0;
			result[nb_word - 1][length] = '\0';
			while (str[i] && !is_separator(str[i]))
			{
				result[nb_word - 1][i] = str[i];
				i++;
			}
			str = str + i;
		}
		while (*str && is_separator(*str))
			str++;	
	}
	return (1);
}

char    **ft_split(char *str)
{
	int		nb_words;
	char	**result;

	nb_words = get_nb_words(str);
	if (!(result = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return NULL;
	result[nb_words] = NULL;
	if (!write_result(result, str))
		return NULL;
	return (result);
}
