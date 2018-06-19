/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_pile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:20:12 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/09 01:30:58 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t		maxsize(t_pile a, t_pile b)
{
	if (a.size >= b.size)
		return (a.size);
	else
		return (b.size);
}

void				display_pile(t_pile a, t_pile b)
{
	size_t		size;

	size = maxsize(a, b);
	while (size)
	{
		if (a.size >= size && b.size >= size)
		{
			ft_printf("	%d	|	%d\n", a.head->value, b.head->value);
			a.head = a.head->next;
			b.head = b.head->next;
		}
		else if (a.size >= size && b.size < size)
		{
			ft_printf("	%d	|\n", a.head->value);
			a.head = a.head->next;
		}
		else if (a.size < size && b.size >= size)
		{
			ft_printf("		|	%d\n", b.head->value);
			b.head = b.head->next;
		}
		size--;
	}
	ft_printf("---------------------------------\n	%c	|	%c\n",
			a.name, b.name);
}
