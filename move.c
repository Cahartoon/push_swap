/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 00:23:35 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/21 11:02:56 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		add_move(t_list *move, char *cmd)
{
	t_list		*tmp;
	char		*last;

	tmp = move;
	while (tmp->next)
		tmp = tmp->next;
	last = tmp->content;
	if (last[0] == cmd[0] &&
			ft_strlen(cmd) == ft_strlen(last) &&
			(ft_strcmp(cmd, last) == -1 ||
			ft_strcmp(cmd, last) == 1) &&
			cmd[0] != 'p')
	{
		if (cmd[0] == 's')
			last[ft_strlen(cmd) - 1] = 's';
		else
			last[ft_strlen(cmd) - 1] = 'r';
	}
	else
		ft_lstappend(move, ft_lstnew(cmd, ft_strlen(cmd)));
	ft_strdel(&cmd);
}
