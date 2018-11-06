/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:17:52 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/21 10:34:39 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_pile *p1, t_pile *p2, t_list *move)
{
	t_value		*tmp;

	if (p1->head == NULL)
		return ;
	tmp = p1->head;
	p1->head = p1->head->next;
	tmp->next = p2->head;
	p2->head = tmp;
	p1->size--;
	p2->size++;
	if (p2->name == 'b')
		add_move(move, ft_strdup("pb"));
	else
		add_move(move, ft_strdup("pa"));
}

void		swap(t_pile *pile, t_list *move)
{
	int			tmp;

	if (pile->size < 2)
		return ;
	tmp = pile->head->value;
	pile->head->value = pile->head->next->value;
	pile->head->next->value = tmp;
	if (pile->name == 'a')
		add_move(move, ft_strdup("sa"));
	else
		add_move(move, ft_strdup("sb"));
}

void		rotate(t_pile *pile, t_list *move)
{
	t_value		*tmp;
	t_value		*new_head;

	if (pile->size > 1)
	{
		tmp = pile->head;
		new_head = pile->head->next;
		while (pile->head->next)
			pile->head = pile->head->next;
		tmp->next = NULL;
		pile->head->next = tmp;
		pile->head = new_head;
		if (pile->name == 'a')
			add_move(move, ft_strdup("ra"));
		else
			add_move(move, ft_strdup("rb"));
	}
}

void		reverse(t_pile *pile, t_list *move)
{
	t_value		*new_head;
	t_value		*new_feet;
	t_value		*tmp;

	if (pile->size < 2)
		return ;
	tmp = pile->head;
	while (tmp->next)
	{
		new_feet = tmp;
		tmp = tmp->next;
	}
	new_head = tmp;
	new_feet->next = NULL;
	new_head->next = pile->head;
	pile->head = new_head;
	if (pile->name == 'a')
		add_move(move, ft_strdup("rra"));
	else
		add_move(move, ft_strdup("rrb"));
}
