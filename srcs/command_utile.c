/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/28 15:20:55 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	pop(t_data **stack)
{
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
}

void	push(t_data **stack, t_data **head)
{
	t_data	*tmp;

	tmp = (*head);
	pop(head);
	tmp->next = *stack;
	if (*stack)
		(*stack)->prev = tmp;
	*stack = tmp;
	(*stack)->prev = NULL;
}

void	ss(t_data **stack_a, t_data **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	rr(t_data **stack_a, t_data **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rrr(t_data **stack_a, t_data **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
