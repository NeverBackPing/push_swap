/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/28 15:19:23 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	view_data(t_data *stack_a)
{
	t_data	*head;

	head = stack_a;
	ft_printf("Init a and b\n");
	while (head  != NULL)
	{
		ft_printf("  %d	\n", head->content);
		head  = head->next;
	}

	if (head == NULL)
	{
		ft_printf(" -------------\n");
		ft_printf("stack A  stack B\n");
	}
}

void	view_data2(t_data *stack_a, t_data *stack_b)
{
	t_data	*head;
	t_data	*head2;

	head = stack_a;
	head2 = stack_b;
	ft_printf("Init a and b\n");
	while (head  != NULL || head2 != NULL)
	{
		ft_printf("  %d	", head->content);
		ft_printf("  %d	\n", head2->content);
		head  = head->next;
		if (head != NULL)
			head2 = head2->next;
	}
	if (head == NULL)
	{
		ft_printf(" -------------\n");
		ft_printf("stack A  stack B\n");
	}
}

void	clear_stack(t_data **stack_a)
{
	data_clear(stack_a);
	ft_printf("Clear\n");
}

int	stack_sort(t_data **stack_a)
{
	t_data	*head;
	t_data	*step;
	t_data	*check;
	int		count;

	count = 0;
	head = *stack_a;
	if (head == NULL || head->next == NULL)
		return (1);
	check = *stack_a;
	step = *stack_a;
	step = step->next;
	while (step)
	{
		if ((int)head->content < (int)step->content)
			count++;
		head = head->next;
		step = step->next;
	}
	if (count == lenstruct(&check) - 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*stack_a;
	t_data	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		write(2, "Error\n", 6);
	else
	{
		if (init_stack(argv, &stack_a))
			return (2);
		if(stack_sort(&stack_a))
			return (clear_stack(&stack_a), 0);
		//tmp = stack_a;
		printf("Stack\n");
		view_data(stack_a);
		pb(&stack_a, &stack_b);
		view_data2(stack_a, stack_b);
		clear_stack(&stack_a);
	}
	return (0);
}

