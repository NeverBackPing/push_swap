/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:49:00 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/17 17:49:00 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H

# include <stdio.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct t_datatruct
{
	int					content;
	struct t_datatruct	*next;
	struct t_datatruct	*prev;
}	t_data;
//Sort
int		check_cost(t_data **stack, t_data **another);
int		great_value(t_data **stack);
void	init_sort(t_data **stack_a, t_data **stack_b);
int		small_value(t_data **stack);
void	start(t_data **stack_a, t_data **stack_b);
//Checker
int		check_data(char *data);
int		check_init(char *data, t_data **stack_a);
int		check_overflow(char *data);
int		check_space(char *data, t_data **stack_a);
int		check_format(char *str, int content, t_data **stack);
//Command
int		lenstruct(t_data **stack);
void	pb(t_data **stack_a, t_data **stack_b);
int		sa(t_data **stack_a);
void	ra(t_data **stack_a);
void	rra(t_data **stack_a);
//Command part2
void	pa(t_data **stack_b, t_data **stack_a);
void	rb(t_data **stack_b);
int		sb(t_data **stack_b);
void	rrb(t_data **stack_b);
//Command utile
void	pop(t_data **stack);
void	push(t_data **stack, t_data **head);
void	ss(t_data **stack_a, t_data **stack_b);
void	rr(t_data **stack_a, t_data **stack_b);
void	rrr(t_data **stack_a, t_data **stack_b);
//Road
void	road(t_data **stack_a, t_data *satck_b, char *str);
void	sort(t_data **stack_a);
//Data structure
t_data	*mew_data(int content);
void	add_data(t_data **lst, t_data *new);
void	data_clear(t_data **lst);
void	data_delone(t_data *lst);
t_data	*last(t_data *lst);
//Parsing
void	error_init(t_data **lst);
int		init_stack(char **str, t_data **stack_a);
int		pars_array(char *str);
int		ft_digit_array(char *str);
int		check_pars(char *str, int check, t_data **stack_a);
//Single Data
int		single_data(char *data);
int		doublon(t_data **s, int c);
int		array_data(t_data **stack_a);
//Swap
void	clear_stack(t_data **stack_a, t_data **stack_b);
int		stack_sort(t_data **stack_a);
#endif
