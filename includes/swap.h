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

typedef struct data_struct
{
	int					content;
	struct data_struct	*next;
}	data_s;
//Checker
int		check_data(char *data);
void	error_init(data_s **lst);
int		check_init(char *data, data_s **stack_a);
int		check_overflow(char *data);
int		check_space(char *data, data_s **stack_a);
//Data structure
data_s	*mew_data(int content);
void	add_data(data_s **lst, data_s *new);
void	data_clear(data_s **lst);
void	data_delone(data_s *lst);
void	merge(data_s *stack_a, data_s *stack_b);
//Parsing
int		init_stack(char **str, data_s **stack_a);
int		pars_array(char **str);
int		ft_digit_array(char *str);
#endif
