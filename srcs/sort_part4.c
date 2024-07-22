/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:38:27 by sjossain          #+#    #+#             */
/*   Updated: 2024/07/21 22:07:21 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

static void set_objective_b(t_data *stack_a, t_data *stack_b)
{
	t_data	*tmp_a;
	t_data	*target_node;
	long	index;

	while(stack_b)
	{
		index = LONG_MIN;
		tmp_a = stack_a;
		while (tmp_a)
		{
			if (tmp_a->content > stack_a->content
				&& tmp_a->content < index)
			{
				index = tmp_a->content;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (index == LONG_MAX)
			stack_b->rule = small_value(&stack_a);
		else
			stack_b->rule = target_node;
		stack_b = stack_b->next;
	}
}

t_data	*small_value(t_data **stack)
{
	int		small;
	t_data	*tmp;
	t_data	*small_value;

	small = 0;
	tmp = *stack;
	small_value = tmp;
	if (tmp)
		small = tmp->content;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (small > tmp->content && tmp != NULL)
		{
			small = tmp->content;
			small_value = tmp;
		}
		tmp = tmp->next;
	}
	return (small_value);
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

t_data	*blow(t_data **stack)
{
	int i;

	i = 0;
	if (!stack || !*stack)
		return (NULL);
	while (*stack)
	{
		i = (*stack)->content;
		if((*stack)->blow)
			return (*stack);
		*stack = (*stack)->next;
	}
	printf("%i", i);
	return (NULL);
}

void	set_node_b(t_data *stack_a, t_data *stack_b)
{
	current_index(stack_a);
	current_index(stack_a);
	set_objective_b(stack_a, stack_b);
}