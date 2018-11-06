/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:25:25 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/21 11:03:08 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					main(int ac, char **av)
{
	t_pile		*a;
	t_pile		*b;
	t_list		*move;

	a = init(ac, av, 'a');
	b = init_b('b');
	move = init_move();
	if (!a || !a->head)
	{
		free_all(&a, &b, &move);
		ft_printf("Error\n");
		return (0);
	}
	if (!issort(*a, a->size))
	{
		if (a->size <= 5)
			sort_small(a, b, move);
		else
			quick(a, b, a->size, move);
	}
	print_move(move);
	free_all(&a, &b, &move);
	return (0);
}
