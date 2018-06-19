/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 00:18:26 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/14 01:05:42 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list			*init_move(void)
{
	char		*start;
	t_list		*move;

	start = ft_strdup("START");
	move = ft_lstnew(start, 5);
	ft_strdel(&start);
	return (move);
}

t_pile			*init_b(char c)
{
	t_pile		*pile;

	if (!(pile = (t_pile*)malloc(sizeof(t_pile))))
		return (NULL);
	pile->head = NULL;
	pile->size = 0;
	pile->name = c;
	return (pile);
}

void			free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
