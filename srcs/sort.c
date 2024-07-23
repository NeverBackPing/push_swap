/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/28 15:19:23 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	current_index(t_data *stack)
{
	int	i;
	int	median;
	int	length;

	i = 0;
	if (!stack)
		return;
	length = lenstruct(&stack);
	median = length / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= median)
			stack->up_med = true;
		else
			stack->up_med = false;
		stack = stack->next;
		++i;
	}
}

void	short_values(t_data **stack_a)
{
	int	great;

	great = great_value(stack_a);
	if ((*stack_a)->content == great)
		ra(stack_a);
	else if ((*stack_a)->next->content == great)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void	init_sort(t_data **stack_a, t_data **stack_b)
{
	int		len_stack;

	len_stack = lenstruct(stack_a);
	if (len_stack == 2)
		sa(stack_a);
	else if (len_stack == 3)
		short_values(stack_a);
	else
		start(stack_a, stack_b);
}
