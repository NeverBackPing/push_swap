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
	t_data	*first;
	int		tmp;

	tmp = 0;
	first = *stack_a;
	if (first == NULL || first->next == NULL)
		return (1);
	tmp = first->content;
	first->content = first->next->content;
	first->next->content = tmp;
	return (0);
}

int	rra(t_data **stack_a)
{
	t_data	*head;
	t_data	*last;
	int		tmp;
	int		first;

	tmp = 0;
	first = 0;
	head = *stack_a;
	last = *stack_a;

	if (head == NULL || head->next == NULL)
		return (1);
	while (last->next != NULL)
	{

	}
	return (0);
}