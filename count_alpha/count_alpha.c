/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:49:22 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 13:29:46 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	to_lowercase(char c)
{
	return (c >= 'a' && c <= 'z' ? c : c + 'a' - 'A');
}

int		main(int argc, char **argv)
{
	int		is_first;
	int		count;
	int		i;
	int		j;
	char	c;
	char	*str;

	if (argc == 2)
	{
		is_first = 1;
		str = argv[1];
		i = 0;
		while (str[i])
		{
			if ((str[i] >= 'a' && str[i] <= 'z') || 
					(str[i] >= 'A' && str[i] <= 'Z'))
			{
				c = to_lowercase(str[i]);
				j = 0;
				while (to_lowercase(str[j]) != c)
					j++;
				if (j == i)
				{
					count = 1;
					j = i + 1;
					while (str[j])
					{
						if (to_lowercase(str[j]) == c)
							count++;
						j++;
					}
					if (is_first)
						printf("%d%c", count, c);
					else
						printf(", %d%c", count, c);
					is_first = 0;
				}
			}
			i++;
		}
		printf("\n");
	}
	else
		write(1, "\n", 1);
}
