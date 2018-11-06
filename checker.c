/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 01:58:07 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/21 10:42:40 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		cmp_move_1(char *line, t_pile *a, t_pile *b, t_list *move)
{
	if (ft_strcmp(line, "pa") == 0)
		push(b, a, move);
	else if (ft_strcmp(line, "pb") == 0)
		push(a, b, move);
	else if (ft_strcmp(line, "sa") == 0)
		swap(a, move);
	else if (ft_strcmp(line, "sb") == 0)
		swap(b, move);
	else if (ft_strcmp(line, "ra") == 0)
		rotate(a, move);
	else if (ft_strcmp(line, "rb") == 0)
		rotate(b, move);
	else if (ft_strcmp(line, "rra") == 0)
		reverse(a, move);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse(b, move);
	else
		return (0);
	return (1);
}

static int		cmp_move_2(char *line, t_pile *a, t_pile *b, t_list *move)
{
	if (ft_strcmp(line, "ss") == 0)
	{
		swap(a, move);
		swap(b, move);
	}
	else if (ft_strcmp(line, "rr") == 0)
	{
		rotate(a, move);
		rotate(b, move);
	}
	else if (ft_strcmp(line, "rrr") == 0)
	{
		reverse(a, move);
		reverse(b, move);
	}
	else
	{
		ft_printf("Error\n%s\n", line);
		return (0);
	}
	return (1);
}

static void		read_move(t_pile *a, t_pile *b, t_list *move, char *line)
{
	while (get_next_line(0, &line))
	{
		if (cmp_move_1(line, a, b, move))
		{
			ft_strdel(&line);
			continue ;
		}
		else if (cmp_move_2(line, a, b, move))
		{
			ft_strdel(&line);
			continue ;
		}
		else
		{
			ft_strdel(&line);
			return ;
		}
	}
	ft_strdel(&line);
}

int				main(int ac, char **av)
{
	t_pile		*a;
	t_pile		*b;
	t_list		*move;
	char		*line;

	line = NULL;
	a = init(ac, av, 'a');
	b = init_b('b');
	move = init_move();
	if (!a || !a->head || !b || !move)
	{
		free_all(&a, &b, &move);
		ft_printf("Error\n");
		return (0);
	}
	read_move(a, b, move, line);
	if (issort(*a, a->size) && b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(&a, &b, &move);
	return (0);
}
