/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/25 14:49:00 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "Error\n", 6);
	}
	else
	{
		data_s	*stack_a;
		//data_s	*stack_b;
		//data_s	*data_a;
		data_s	*a_head;
		//data_s	*a_head_second;
		//data_s	*b_head;

		stack_a = NULL;
		//data_a = NULL;
		//stack_b = NULL;
		//ft_printf("Init a and b\n");
		//ft_printf("-------------\n");
		if (init_stack(argv, &stack_a))
				return (-1);
		a_head = stack_a;
		//a_head_second = a_head ;
		while (stack_a != NULL /*|| stack_b != NULL*/)
		{
			ft_printf("  %d                     \n", stack_a->content);
			stack_a = stack_a->next;
		}
		if (stack_a == NULL)
		{
			ft_printf(" -------------\n");
			ft_printf("stack A  stack B\n");
		}
		/*ft_printf(" -------------\n");

		merge(a_head, stack_b);

		b_head = stack_b;

		while (a_head_second != NULL || stack_b != NULL)
		{
			ft_printf("|  %d  |  %d  |\n", a_head_second->content, stack_b->content);
			a_head_second = a_head_second->next;
			stack_b = stack_b->next;
		}
		ft_printf(" -------------\n");
		ft_printf("stack A  stack B\n");*/
		data_clear(&a_head);
		//data_clear(&b_head);
		if (a_head == NULL /*&& b_head == NULL*/)
			ft_printf("Clear\n");
	}
	return (0);
}