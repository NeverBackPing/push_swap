/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:38:27 by sjossain          #+#    #+#             */
/*   Updated: 2024/07/22 05:11:55 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

static void	rotate(t_data **stack_a, t_data **stack_b, t_data *blow_node)
{
	while ((*stack_b) != blow_node->rule && (*stack_a) != blow_node)
		rr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	rev_rotate(t_data **stack_a, t_data **stack_b, t_data *blow_node)
{
	while ((*stack_b) != blow_node->rule && (*stack_a) != blow_node)
			rrr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

static void	push_a(t_data **stack_a, t_data **stack_b)
{
	init_for_push(stack_a, (*stack_b)->rule, 'A');
	pa(stack_b, stack_a);
}

static void	push_b(t_data **stack_a, t_data **stack_b)
{
	t_data	*blow_node;

	blow_node = blow(stack_a);
	if (blow_node->up_med && blow_node->rule->up_med)
		rotate(stack_a, stack_b, blow_node);
	else if (!(blow_node->up_med) && !(blow_node->rule->up_med))
		rev_rotate(stack_a, stack_b, blow_node);
	init_for_push(stack_a, blow_node, 'A');
	init_for_push(stack_b, blow_node->rule, 'B');
	pb(stack_a, stack_b);
}

void	start(t_data **stack_a, t_data **stack_b)
{
	int		len_stack;

	pb(stack_a, stack_b);
	if (stack_sort(stack_a) == 0)
		pb(stack_a, stack_b);
	len_stack = lenstruct(stack_a);
	while (len_stack-- > 3 && stack_sort(stack_a) == 0)
	{
		set_node_a((*stack_a), (*stack_b));
		push_b(stack_a, stack_b);
	}
	short_values(stack_a);
	while (*stack_b)
	{
		set_node_b((*stack_b), (*stack_a));
		push_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	small_on_top(stack_a);
}
