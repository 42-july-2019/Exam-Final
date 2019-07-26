/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 14:23:19 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 15:48:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

void	sort_array(char **result)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (result[i])
	{
		j = i + 1;
		while (result[j])
		{
			if (ft_strcmp_low(result[i], result[j]) > 0)
			{
				temp = result[j];
				result[j] = result[i];
				result[i] = temp;
			}
			j++;
		}
		i++;
	}
}

void	write_str(char **result, char *str, int curr_size)
{
	int i;
	int j;
	int curr_length;
	int curr_count;
	int	total_length;
	int total_count;

	i = 0;
	total_length = 0;
	total_count = 0;
	while (str[i])
	{
		curr_length = 0;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
		{
			curr_length++;
			i++;
		}
		total_length += curr_length == curr_size ? curr_length : 0;
		total_count += curr_length == curr_size ? 1 : 0;
	}
	j = 0;
	curr_count = 0;
	while (*str)
	{
		curr_length = 0;
		while (*str && (*str == ' ' || *str == '\t'))
			str++;
		i = 0;
		while (str[i] && !(str[i] == ' ' || str[i] == '\t'))
		{
			curr_length++;
			i++;
		}
		if (curr_length == curr_size)
		{
			i = 0;
			curr_count++;
			result[curr_count - 1] =
				(char *)malloc(sizeof(char) * curr_length + 1);
			result[curr_count - 1][curr_length] = '\0';
			while (i < curr_length && curr_count <= total_count)
			{
				result[curr_count - 1][i] = str[i];
				i++;
			}
		}
		str = str + curr_length;
	}
}
