/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/22 17:44:52 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

int	main(int argc, char **argv)
{
	(void)argc;
	data_s	*stack_a;
	data_s	*stack_b;
	data_s	*data_a;
	data_s	*a_head;
	data_s	*a_head_second;
	data_s	*b_head;
	int		i;
	int		data;

	i = 1;
	data = 0;
	stack_a = NULL;
	data_a = NULL;
	stack_b = NULL;
	ft_printf("Init a and b\n");
	ft_printf("-------------\n");
	while (argv[i] != NULL)
	{
		data = ft_atoi(argv[i]);
		data_a = mew_data(data);
		add_data(&stack_a, data_a);
		i++;
	}
	a_head = stack_a;
	a_head_second = stack_a;
	while (stack_a != NULL || stack_b != NULL)
	{
		ft_printf("|  %d  |  %d  |\n", stack_a->content);
		stack_a = stack_a->next;
	}

	ft_printf(" -------------\n");
	ft_printf("stack A  stack B\n");
	ft_printf(" -------------\n");

	merge(a_head, stack_b);

	b_head = stack_b;

	while (a_head_second != NULL || stack_b != NULL)
	{
		ft_printf("|  %d  |  %d  |\n", a_head_second->content, stack_b->content);
		a_head_second = a_head_second->next;
	}
	ft_printf(" -------------\n");
	ft_printf("stack A  stack B\n");
	data_clear(&a_head);
	data_clear(&b_head);
	if (a_head == NULL && b_head == NULL)
		ft_printf("Clear\n");
	return (0);
}