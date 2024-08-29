/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dalton_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:27:50 by sjossain          #+#    #+#             */
/*   Updated: 2024/08/28 18:25:19 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

int	insert_smallest(t_data **stack_a, t_data **stack_b, int small)
{
	pa(stack_b, stack_a);
	small = small_value(stack_a);
	return (small);
}

void	insert_middle(t_data **stack_a, t_data **stack_b)
{
	ra(stack_a);
	pa(stack_b, stack_a);
	sa(stack_a);
	rra(stack_a);
}

void	insert_before_greatest(t_data **stack_a, t_data **stack_b)
{
	rra(stack_a);
	pa(stack_b, stack_a);
	ra(stack_a);
	ra(stack_a);
}

int	insert_greatest(t_data **stack_a, t_data **stack_b, int great)
{
	pa(stack_b, stack_a);
	ra(stack_a);
	great = great_value(stack_a);
	return (great);
}

void	william(t_data **stack_a, t_data **stack_b)
{
	ra(stack_a);
	pa(stack_b, stack_a);
	rra(stack_a);
}
