/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:30:21 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/09 01:52:51 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_two(t_pile *p, t_list *move)
{
	if (p->name == 'a' && p->head->value > p->head->next->value)
		swap(p, move);
	else if (p->name == 'b' && p->head->value < p->head->next->value)
		swap(p, move);
}

static void		nikbienlanorme(t_pile *p, t_list *mv)
{
	int		md;
	int		mn;
	int		mx;

	md = get_median(p, p->size);
	mn = get_min(*p);
	mx = get_max(*p);
	if (p->head->value == mn && p->head->next->value == mx)
	{
		reverse(p, mv);
		swap(p, mv);
	}
	else if (p->head->value == md && p->head->next->value == mn)
		swap(p, mv);
	else if (p->head->value == md && p->head->next->value == mx)
		reverse(p, mv);
	else if (p->head->value == mx && p->head->next->value == mn)
		rotate(p, mv);
	else if (p->head->value == mx && p->head->next->value == md)
	{
		rotate(p, mv);
		swap(p, mv);
	}
}

static void		sort_three(t_pile *p, t_list *move)
{
	if (p->size == 2)
		sort_two(p, move);
	else
		nikbienlanorme(p, move);
}

static void		niklanorme(t_pile *a, t_pile *b, t_list *move)
{
	reverse(a, move);
	push(a, b, move);
}

void			sort_small(t_pile *a, t_pile *b, t_list *move)
{
	int		med;

	med = get_median(a, a->size);
	if (a->size > 3)
	{
		while (check_median(a, med, a->size))
		{
			if (a->head->value < med)
				push(a, b, move);
			else if (get_last(*a) < med)
				niklanorme(a, b, move);
			else if (a->head->value >= med)
				rotate(a, move);
			else if (a->head->value >= med)
				reverse(a, move);
		}
		sort_three(a, move);
		sort_three(b, move);
		while (b->size)
			push(b, a, move);
	}
	else
		sort_three(a, move);
}
