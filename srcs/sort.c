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

int	small_value(t_data **stack)
{
	int		small;
	t_data	*tmp;

	small = 0;
	tmp = *stack;
	if (tmp)
		small = tmp->content;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (small > tmp->content && tmp != NULL)
			small = tmp->content;
		tmp = tmp->next;
	}
	return (small);
}

int	great_value(t_data **stack)
{
	int		great;
	t_data	*tmp;

	great = 0;
	tmp = *stack;
	if (tmp)
		great = tmp->content;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (great < tmp->content && tmp != NULL)
			great = tmp->content;
		tmp = tmp->next;
	}
	return (great);
}


int	check_cost(t_data *stack, t_data *another)
{
	int	len_stack;
	int	len_another;

	len_stack = lenstruct(stack);
	len_another = lenstruct(another);
	while (stack)
	{
		stack->cost = index;
		if (!(stack->up_med))
			stack->cost = len_stack - (stack->position);
		if (stack->rule->up_med)
			stack->cost += stack->rule->position;
		else
			stack->cost += len_another - (stack->rule->position);
		stack = stack->next;
	}
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
		pb(stack_a, stack_b);
	}
	short_values(stack_a);
	while (len_stack-- > 3 && stack_sort(stack_a) == 0)
	{
		set_node_b((*stack_b), (*stack_a));
		pa(stack_a, stack_b);
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
	int		cost;
	int		len_stack;

	cost = 0;
	len_stack = lenstruct(stack_a);
	if (len_stack == 2)
		sa(stack_a);
	else if (len_stack == 3)
		short_values(stack_a);
	else
		start(stack_a, stack_b);
}
