/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:01:32 by edinguim          #+#    #+#             */
/*   Updated: 2018/03/20 15:33:12 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		issort(t_pile p, int size)
{
	if (p.head && p.name == 'a' && p.size >= 2)
		while (p.head->next && size--)
		{
			if (p.head->value > p.head->next->value)
				return (0);
			p.head = p.head->next;
		}
	else if (p.head && p.name == 'b' && p.size >= 2)
		while (p.head->next && size--)
		{
			if (p.head->value < p.head->next->value)
				return (0);
			p.head = p.head->next;
		}
	return (1);
}
