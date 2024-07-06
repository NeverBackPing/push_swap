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
	printf(" -------------");
	printf("\nInit a and b\n");
	printf(" -------------\n");
	while (head  != NULL)
	{
		printf("  %d	\n", head->content);
		head  = head->next;
	}

	if (head == NULL)
	{
		printf(" -------------\n");
		printf("stack A  stack B\n");
		printf(" -------------\n\n");
	}
}

void	view_data2(t_data *stack_a, t_data *stack_b)
{
	t_data	*head;
	t_data	*head2;
	int		i;

	i = 0;
	head = stack_a;
	head2 = stack_b;
	printf("\n-------------\n");
	printf(" short stack\n");
	printf("-------------\n");
	printf("Stack A: ");
	while (head)
	{
		i =  head->content;
		printf(" %d ", i);
		head = head->next;
	}
	i = 0;
	printf("\nStack B: ");
	while (head2)
	{
		i =  head2->content;
		printf(" %d ", i);
		head2 = head2->next;
	}
	printf("\n---------------------\n");
}

void	clear_stack(t_data **stack_a, t_data **stack_b)
{
	if (stack_a)
		data_clear(stack_a);
	if (stack_b)
		data_clear(stack_b);
	printf("\nClear\n\n");
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
			return (clear_stack(&stack_a, &stack_b), 0);
		view_data(stack_a);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pa(&stack_, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		view_data2(stack_a, stack_b);
		clear_stack(&stack_a, &stack_b);
	}
	return (0);
}

