/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:31:12 by sjossain          #+#    #+#             */
/*   Updated: 2024/07/22 05:15:43 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

static void	check_cost(t_data *stack, t_data *another)
{
	int	len_stack;
	int	len_another;

	len_stack = lenstruct(&stack);
	len_another = lenstruct(&another);
	while (stack)
	{
		stack->cost = stack->position;
		if (!(stack->up_med))
			stack->cost = len_stack - (stack->position);
		if (stack->rule->up_med)
			stack->cost += stack->rule->position;
		else
			stack->cost += len_another - (stack->rule->position);
		stack = stack->next;
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
			if (tmp_b->content < stack_a->content && tmp_b->content > index)
			{
				index = tmp_b->content;
				target_node = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (index == LONG_MAX)
			stack_a->rule = small_value(&stack_b);
		else
			stack_a->rule = target_node;
		stack_a = stack_a->next;
	}
}

void	init_for_push(t_data **stack, t_data *head, char keys)
{
	while (*stack != head)
	{
		if (keys == 'A')
		{
			if ((*stack)->up_med)
				ra(stack);
			else
				rra(stack);
		}
		else if (keys == 'B')
		{
			if ((*stack)->up_med)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	set_blow(t_data *stack)
{
	long	blow_value;
	t_data	*blow_struct;

	if (!(stack))
		return;
	blow_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < blow_value)
		{
			blow_value = stack->cost;
			blow_struct = stack;
		}
		stack = stack->next;
	}
	blow_struct->blow = true;
}

void	set_node_a(t_data *stack_a, t_data *stack_b)
{
	current_index(stack_a);
	current_index(stack_a);
	set_objective(stack_a, stack_b);
	check_cost(stack_a, stack_b);
	set_blow(stack_a);
}


