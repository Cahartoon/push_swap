/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:16:50 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/09 01:28:22 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		quick_med(t_pile *a, t_pile *b, int size, t_list *move)
{
	int			pivot;
	int			i;
	size_t		c;

	c = 0;
	i = 0;
	if (a->size)
	{
		pivot = get_median(a, size);
		while (i <= size && check_median(a, pivot, size))
		{
			if (a->head->value >= pivot && c++)
				rotate(a, move);
			else if (a->head->value < pivot)
				push(a, b, move);
			i++;
		}
		if (c != a->size)
			while (c > 1 && a->size > 1)
			{
				reverse(a, move);
				c--;
			}
	}
}

void			quick(t_pile *a, t_pile *b, int size, t_list *move)
{
	if (size <= 2)
	{
		if (size == 2 && a->head->value > a->head->next->value)
			swap(a, move);
		return ;
	}
	else if (size)
	{
		quick_med(a, b, size, move);
		quick(a, b, size / 2 + size % 2, move);
		rv_quick(a, b, size / 2, move);
	}
	return ;
}
