/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/28 15:20:55 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

int	sb(t_data **stack_b)
{
	t_data	*first;
	t_data	*second;

	first = *stack_b;
	if (first == NULL || first->next == NULL)
		return (1);
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	*stack_b = second;
	ft_printf("sa\n");
	return (0);
}

void	rb(t_data **stack_b)
{
	t_data	*first;
	t_data	*lst;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	lst = *stack_b;
	while (lst->next != NULL)
		lst = lst->next;
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	lst->next = first;
	first->prev = lst;
	first->next = NULL;
	ft_printf("rb\n");
}

void	pa(t_data **stack_b, t_data **stack_a)
{
	t_data	**b;

	if (!stack_b || !(*stack_b))
		return ;
	b = stack_b;
	push(stack_a, b);
	ft_printf("pa\n");
}

void	rrb(t_data **stack_b)
{
	t_data	*last;
	t_data	*second_last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last = *stack_b;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack_b;
	(*stack_b)->prev = last;
	*stack_b = last;
	ft_printf("rrb\n");
}
