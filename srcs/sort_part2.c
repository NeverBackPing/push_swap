/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:31:12 by sjossain          #+#    #+#             */
/*   Updated: 2024/07/21 16:34:57 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"



void	current_index(t_data *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return;
	median = lenstruct(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= median)
			stack->up_med = true
		else
			stack->up_med = false
		stack = stack->next;
		i++;
	}
}

static void set_objective(t_data *stack_a, t_data *stack_b)
{
	t_data	*tmp_b;
	t_data	*target_node;
	long	index;

	while(stack_a)
	{
		index = LONG_MIN;
		tmp_b = stack_b;
		while (tmp_b)
		{
			if (tmp_b->content < stack_a->content
				&& tmp_b->content > index)
			{
				index = tmp_b->content;
				target_node = tmp_b;
			}
			tmp_b = tmp_b->next
			if (index == LONG_MAX)
				stack_a->rule = great_value(stack_b);
			else
				stack_a->rule = target_node;
			stack_a = stack_a->next;
		}
	}
}

void	set_blow(t_data stack)
{
	long	blow;
	t_data	*blow_struct;

	if (!stack)
		return;
	blow = LONG_MAX;
	while (stack)
	{
		if (stack->cost < blow)
		{
			blow = stack->cost;
			blow_struct = stack;
		}
		stack = stack->next
	}
	blow_struct->blow = true;
}

void	set_node_a(t_data *stack_a, t_data *stack_b)
{
	current_index(stack_a);
	current_index(stack_a);
	set_rule(stack_a, stack_b);
	check_cost(stack_a, stack_b);
	set_blow(stack_a);
}

void	set_node_b(t_data *stack_a, t_data *stack_b)
{
	current_index(stack_a);
	current_index(stack_a);
	set_objective(stack_a, stack_b);
	check_cost(stack_a, stack_b);
	set_blow(stack_a);
}

