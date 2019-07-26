/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 13:44:07 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 15:53:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

char	to_lowercase(char c)
{
		return (c >= 'a' && c <= 'z' ? c : c + 'a' - 'A');
}

int		ft_strcmp_low(char *s1, char *s2)
{
	while (*s1 && *s2 && to_lowercase(*s1) == to_lowercase(*s2))
	{
		s1++;
		s2++;
	}
	return (to_lowercase(*s1) - to_lowercase(*s2));
}

int		get_max_size(char *str)
{
	int result;
	int	curr_size;

	result = 0;
	while (*str)
	{
		curr_size = 0;
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		while (*str && !(*str == ' ' || *str == '\t'))
		{
			curr_size++;
			str++;
		}
		result = curr_size > result ? curr_size : result;
	}
	return (result);
}

int		allocate_memory(char ***result, char *str, int curr_size)
{
	int	curr_length;
	int	count;

	count = 0;
	while (*str)
	{
		curr_length = 0;
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		while (*str && !(*str == ' ' || *str == '\t'))
		{
			curr_length++;
			str++;
		}
		count += curr_length == curr_size ? 1 : 0; 
	}
	if (!(result[curr_size - 1] =
				(char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	result[curr_size - 1][count] = NULL;
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		curr_size;
	int		max_size;
	char	*first_str;
	char	*cpy_str;
	char	*str;
	char	***result_array;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = argv[1];
	max_size = get_max_size(str);
	if (!(result_array = (char ***)malloc(sizeof(char **) * max_size)))
		return (0);
	curr_size = 1;
	while (curr_size <= max_size)
	{
		if (!allocate_memory(result_array, str, curr_size))
			return (0);
		curr_size++;
	}
	curr_size = 1;
	while (curr_size <= max_size)
	{
		write_str(result_array[curr_size - 1], str, curr_size);
		curr_size++;
	}
	curr_size = 1;
	while (curr_size <= max_size)
	{
		sort_array(result_array[curr_size - 1]);
		curr_size++;
	}
	curr_size = 1;
	while (curr_size <= max_size)
	{
		first_str = *result_array[curr_size - 1];
		while (*result_array[curr_size - 1])
		{
			cpy_str = *result_array[curr_size - 1];
			i = 0;
			while (cpy_str[i])
			{
				write(1, &cpy_str[i], 1);
				i++;
			}
			result_array[curr_size - 1]++;
			if (*result_array[curr_size - 1])
				write(1, " ", 1);
		}
		curr_size++;
		if (first_str)
			write(1, "\n", 1);
	}
	curr_size = 1;
/*	while (curr_size <= max_size)
	{
		free(result_array[curr_size - 1]);
		curr_size++;
	}
	free(result_array);
*/	
}
