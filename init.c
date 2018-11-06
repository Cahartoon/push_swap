/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 02:53:01 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/17 21:58:50 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_value		*new_value(char *s)
{
	t_value			*new;
	int				value;

	if (s && ft_isnumber(s))
	{
		value = ft_atoi(s);
		if (ft_strlen(s) == ft_intsize(value) ||
				(ft_strlen(s) - 1 == ft_intsize(value) && s[0] == '+'))
		{
			if (!(new = (t_value*)malloc(sizeof(t_value))))
				return (NULL);
			new->value = value;
			new->next = NULL;
			return (new);
		}
	}
	return (NULL);
}

static int			add_value(t_value *lst, t_value *new)
{
	t_value		*tmp;

	tmp = lst;
	if (!new)
		return (0);
	while (tmp->next)
	{
		if (tmp->value != new->value)
			tmp = tmp->next;
		else
			break ;
	}
	if (tmp->value != new->value)
		tmp->next = new;
	else
	{
		free_value(&new);
		return (0);
	}
	return (1);
}

static t_value		*init_value(char **tab)
{
	t_value		*new;

	if (!(new = new_value(*tab)))
		return (NULL);
	tab++;
	while (*tab)
		if (!add_value(new, new_value(*tab++)))
		{
			free_value(&new);
			return (NULL);
		}
	return (new);
}

static t_pile		*init_pile(t_value *list, char c)
{
	t_pile		*pile;

	if (!(pile = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	if (list)
	{
		pile->size = 0;
		pile->head = list;
		while (list)
		{
			pile->size++;
			list = list->next;
		}
		pile->name = c;
	}
	else
	{
		pile->head = NULL;
		pile->size = 0;
		pile->name = c;
	}
	return (pile);
}

t_pile				*init(int ac, char **av, char name)
{
	t_pile		*a;
	char		**tab;

	if (ac <= 1)
		return (NULL);
	if (ac == 2)
	{
		tab = ft_strsplit(av[1], 32);
		a = init_pile(init_value(tab), name);
		free_tab(tab);
	}
	else
	{
		av++;
		a = init_pile(init_value(av), name);
	}
	return (a);
}
