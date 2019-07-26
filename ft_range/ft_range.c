/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:40:53 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 11:53:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int		i;
	int		length;
	int		diff_to_add;
	int		*array;

	length = end >= start ? end - start : start - end;	
	diff_to_add = end >= start ? 1 : -1;
	if (!(array = (int *)malloc(sizeof(int) * (length + 1))))
		return (0);
	array[0] = start;
	i = 1;
	while (i <= length)
	{
		array[i] = array[i - 1] + diff_to_add;
		i++;
	}
	return (array);
}
