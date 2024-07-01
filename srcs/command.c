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

	t_data	*head;
	t_data	*last;
	int		tmp;

	head = *stack_a;
	last = NULL;
	tmp = 0;
	if (head == NULL || head->next == NULL)
		return (0);
	while (head->next != NULL)
	{
		last = head;
		head = head->next;
	}
	last->next = NULL;
	head->next = *stack_a;
	*stack_a = head;
	return (1);
}

int	rra(t_data **stack_a)
{

	t_data	*head;
	t_data	*last;

	head = NULL;
	head = *stack_a;
	last = NULL;
	if (head == NULL || head->next == NULL)
		return (0);
	while (head->next != NULL)
	{
		last = head;
		head = head->next;
	}
	last->next = NULL;
	head->next = *stack_a;
	*stack_a = head;
	return (1);
}