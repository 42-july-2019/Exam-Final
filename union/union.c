/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:10:22 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 11:37:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include <unistd.h>

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		write(1, &s1[0], 1);
		i = 1;
		while(s1[i])
		{
			j = 0;
			while(s1[j] != s1[i])
				j++;
			if (i == j)
				write(1, &s1[i], 1);
			i++;
		}
		i = 0;
		while(s2[i])
		{
			j = 0;
			while(s1[j] && s1[j] != s2[i])
				j++;
			if (!s1[j])
			{
				if (i == 0)
					write(1, &s2[i], 1);
				else
				{
					j = 0;
				while (s2[j] != s2[i])
					j++;
				if (j == i)
					write(1, &s2[i], 1);
				}
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
