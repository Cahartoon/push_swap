/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 23:11:57 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/21 11:08:16 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_value(t_value **value)
{
	t_value		*tmp;

	if (!value)
		return ;
	while (*value)
	{
		tmp = (*value)->next;
		free(*value);
		*value = tmp;
	}
	*value = NULL;
}

void		free_pile(t_pile **p)
{
	if (!p)
		return ;
	free_value(&((*p)->head));
	free(*p);
}

void		free_move(t_list **move)
{
	t_list		*tmp;

	while (*move)
	{
		tmp = (*move)->next;
		free((*move)->content);
		free(*move);
		*move = tmp;
	}
	*move = NULL;
}

void		print_move(t_list *move)
{
	t_list		*tmp;
	char		*test;

	if (!move)
		return ;
	tmp = move;
	tmp = tmp->next;
	while (tmp)
	{
		if (ft_strlen(tmp->content) == 3)
			if (ft_strcmp(tmp->content, "rrr") != 0)
				if (ft_strcmp(tmp->content, "rra") != 0)
					if (ft_strcmp(tmp->content, "rrb") != 0)
					{
						test = tmp->content;
						ft_putchar(test[0]);
						ft_putchar(test[1]);
						ft_putchar('\n');
						tmp = tmp->next;
					}
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
}

void		free_all(t_pile **a, t_pile **b, t_list **move)
{
	free_pile(a);
	free_pile(b);
	free_move(move);
}
