/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 10:53:57 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 11:01:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strrev(char *str)
{
	int		i;
	int		length;
	char	temp;

	length = 0;
	while (str[length])
		length++;
	i = 0;
	while (i < length / 2)
	{
		temp = str[length - 1 - i];
		str[length - 1 - i] = str[i];
		str[i] = temp;
		i++;
	}
	return (str);
}
