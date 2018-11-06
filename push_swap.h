/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:55:49 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/14 01:05:30 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <limits.h>

typedef struct			s_value
{
	int					value;
	struct s_value		*next;
}						t_value;

typedef struct			s_pile
{
	t_value				*head;
	t_value				*min;
	int					pos;
	size_t				size;
	char				name;
}						t_pile;

t_pile					*init(int ac, char **av, char name);
t_pile					*init_b(char c);
t_list					*init_move(void);
void					push(t_pile *p1, t_pile *p2, t_list *move);
void					swap(t_pile *pile, t_list *move);
void					rotate(t_pile *pile, t_list *move);
void					reverse(t_pile *pile, t_list *move);
int						get_median(t_pile *p, int size);
int						check_median(t_pile *p, int med, int size);
void					display_pile(t_pile a, t_pile b);
void					quick(t_pile *a, t_pile *b, int size, t_list *move);
void					rv_quick(t_pile *a, t_pile *b, int size, t_list *mv);
void					sort_small(t_pile *a, t_pile *b, t_list *move);
void					add_move(t_list *move, char *cmd);
int						issort(t_pile p, int size);
int						get_min(t_pile p);
int						get_max(t_pile p);
int						get_last(t_pile p);
void					free_tab(char **tab);
void					free_pile(t_pile **p);
void					free_value(t_value **value);
void					free_move(t_list **move);
void					free_all(t_pile **a, t_pile **b, t_list **move);
void					print_move(t_list *move);

#endif
