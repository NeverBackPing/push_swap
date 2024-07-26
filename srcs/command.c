/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/28 15:20:55 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

int	lenstruct(t_data **stack)
{
	int		len;
	t_data	*head;

	len = 0;
	if (!stack)
		return (0);
	head = *stack;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}


int	sa(t_data **stack_a)
{
	t_data *first;
	t_data *second;

	first = *stack_a;
	if (first == NULL || first->next == NULL)
		return (1);
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	*stack_a = second;
	ft_printf("sa\n");
	return (0);
}

void	ra(t_data **stack_a)
{
	t_data *first;
	t_data *lst;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	first = *stack_a;
	lst = *stack_a;
	while (lst->next != NULL)
		lst = lst->next;
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	lst->next = first;
	first->prev = lst;
	first->next = NULL;
	ft_printf("ra\n");
}

void	pb(t_data **stack_a, t_data **stack_b)
{
	t_data	**a;

	if (!stack_a || !(*stack_a))
		return ;
	a = stack_a;
	push(stack_b, a);
	ft_printf("pb\n");
}

void	rra(t_data **stack_a)
{
	t_data *last;
	t_data *second_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	last = *stack_a;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack_a;
	(*stack_a)->prev = last;
	*stack_a = last;
	ft_printf("rra\n");
}
