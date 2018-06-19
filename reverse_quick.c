/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_quick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:11:31 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/09 01:52:55 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		reverse_quick_med(t_pile *a, t_pile *b, int size, t_list *move)
{
	int			pivot;
	int			i;
	size_t		c;

	c = 0;
	i = 0;
	if (b->size)
	{
		pivot = get_median(b, size);
		while (i <= size && check_median(b, pivot, size))
		{
			if (b->head->value < pivot && c++)
				rotate(b, move);
			else if (b->head->value >= pivot)
				push(b, a, move);
			i++;
		}
		if (c != b->size)
			while (c > 1 && b->size > 1)
			{
				reverse(b, move);
				c--;
			}
	}
}

void			rv_quick(t_pile *a, t_pile *b, int size, t_list *move)
{
	if (size <= 2)
	{
		if (size == 2 && b->head->value < b->head->next->value)
			swap(b, move);
		while (b->size && size-- != 0)
			push(b, a, move);
		return ;
	}
	else if (size)
	{
		reverse_quick_med(a, b, size, move);
		quick(a, b, size / 2 + size % 2, move);
		rv_quick(a, b, size / 2, move);
	}
	return ;
}
