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

void	view_data(data_s *stack_a)
{
	while (stack_a != NULL)
	{
		ft_printf("  %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	if (stack_a == NULL)
	{
		ft_printf(" -------------\n");
		ft_printf("stack A  stack B\n");
	}
}

void	clear_stack(data_s **stack_a)
{
	data_clear(stack_a);
	if (stack_a == NULL)
		ft_printf("Clear\n");
}

int	main(int argc, char **argv)
{
	data_s	*stack_a;
	data_s	*a_head;

	if (argc == 1)
		write(2, "Error\n", 6);
	else
	{
		stack_a = NULL;
		ft_printf("Init a and b\n");
		if (init_stack(argv, &stack_a))
			return (2);
		a_head = stack_a;
		view_data(stack_a);
		clear_stack(&a_head);
	}
	return (0);
}
