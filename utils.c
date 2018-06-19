/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 22:22:13 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/09 01:25:57 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_median(t_pile *p, int size)
{
	int		med;
	int		i;
	int		j;
	t_value	*tmp1;
	t_value	*tmp2;

	tmp1 = p->head;
	i = 0;
	while (tmp1 && i < size)
	{
		med = 0;
		j = 0;
		tmp2 = p->head;
		while (tmp2 && j++ < size)
		{
			if (tmp1->value != tmp2->value)
				tmp2->value > tmp1->value ? med++ : med--;
			tmp2 = tmp2->next;
		}
		if (med == 0 || med == -1)
			return (tmp1->value);
		tmp1 = tmp1->next;
		i++;
	}
	return (0);
}

int			check_median(t_pile *p, int med, int size)
{
	t_value		*tmp;

	tmp = p->head;
	while (tmp && size)
	{
		if (tmp->value < med && p->name == 'a')
			return (1);
		if (tmp->value >= med && p->name == 'b')
			return (1);
		tmp = tmp->next;
		size--;
	}
	return (0);
}

int			get_last(t_pile p)
{
	while (p.head->next)
		p.head = p.head->next;
	return (p.head->value);
}

int			get_max(t_pile p)
{
	int		max;

	max = INT_MIN;
	while (p.head)
	{
		if (p.head->value > max)
			max = p.head->value;
		p.head = p.head->next;
	}
	return (max);
}

int			get_min(t_pile p)
{
	int		min;

	min = INT_MAX;
	while (p.head)
	{
		if (p.head->value < min)
			min = p.head->value;
		p.head = p.head->next;
	}
	return (min);
}
