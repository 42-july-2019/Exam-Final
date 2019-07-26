/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:23:19 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 12:45:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		temp;
	t_list	*elem1;
	t_list	*elem2;

	elem1 = lst;
	while (elem1)
	{
		elem2 = elem1->next;
		while (elem2)
		{
			if (!(*cmp)(elem1->data, elem2->data))
			{
				temp = elem2->data;
				elem2->data = elem1->data;
				elem1->data = temp;
			}
			elem2 = elem2->next;
		}
		elem1 = elem1->next;
	}
	return (lst);
}
