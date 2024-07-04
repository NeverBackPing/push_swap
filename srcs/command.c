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
	ft_printf("sa\n");
	return (0);
}

int	rra(t_data **stack_a)
{
	int		tmp; //prev
	int		lst; //next
	t_data	*current;
	t_data	*head;

	tmp = 0;
	lst = 0;
	head = *stack_a;
	current = *stack_a;
	if (current == NULL || current->next == NULL)
		return (1);
	tmp = current->content;
	while (head)
	{
		if (head->next == NULL)
			break ;
		head = head->next;
	}
	lst = head->content;
	current->content = lst;
	current = current->next;
	printf("content: %d\n", current->content);
	while (current != NULL)
	{
		lst = current->content;
		current->next->content = tmp;
		current->content = lst;
		current = current->next;
	}
	return (0);
}