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
	int		tmp;

	tmp = 0;
	first = *stack_b;
	if (first == NULL || first->next == NULL)
		return (1);
	tmp = first->content;
	first->content = first->next->content;
	first->next->content = tmp;
	ft_printf("sb\n");
	return (0);
}

void	rb(t_data **stack_b)
{
	int		tmp;
	int		lst;
	t_data	*current;

	current = *stack_b;
	if (current == NULL || current->next == NULL)
		return ;
	lst = current->content;
	while (current->next != NULL)
	{
		tmp = current->next->content;
		current->content = tmp;
		current = current->next;
	}
	current->content = lst;
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
	int		tmp;
	int		lst;
	t_data	*current;
	t_data	*head;

	head = *stack_b;
	current = *stack_b;
	if (current == NULL || current->next == NULL)
		return ;
	tmp = current->content;
	head = last(head);
	lst = head->content;
	current->content = lst;
	current = current->next;
	while (current != NULL)
	{
		lst = tmp;
		tmp = current->content;
		current->content = lst;
		current = current->next;
	}
	ft_printf("rrb\n");
}
