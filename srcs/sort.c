/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/28 15:19:23 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

int	check_cost(t_data **stack, t_data **another)
{
	t_data	*tmp;
	t_data	*tmp2;
	int		check;
	t_data	*end;

	check = 0;
	end = 0;
	tmp = *stack;
	tmp2 = *another;
	end = last(tmp);
	if (tmp->content > tmp2->content)
	{
		printf("bonjour\n");
		printf("----------\n");

		printf("\nnext->content: %d\n", tmp2->next->content );
		printf("\ncontent: %d\n", tmp2->content );
		check++;
		if (tmp2->content > tmp2->next->content)
			check++;
		else
		{
			printf("bonjour\n");
			check++;
			check++;
		}
	}
	else
	{
		printf("hello\n");
		printf("----------\n");
		printf("\nnext->content: %d\n", tmp->next->content );
		printf("\ncontent: %d\n", tmp->content );
		check++;
		printf("\ncontent LAST: %d\n", end->content );
		if (tmp->content > end->content)
			check++;
		else
		{
			if (tmp->content < tmp2->next->content)
				check++;
			check++;
			check++;
		}
	}
	printf("cost: %d\n", check);
	return (check);
}

void	start(t_data **stack_a, t_data **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
}

void	init_sort(t_data **stack_a, t_data **stack_b)
{
	int		cost;

	start(stack_a, stack_b);
	cost = 0;

	cost = check_cost(stack_a, stack_b);
	if ((*stack_a)->content > (*stack_b)->content && cost == 2)
		pb(stack_a, stack_b);
	cost = check_cost(stack_a, stack_b);
	if ((*stack_a)->content < (*stack_b)->content && cost == 2)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	cost = check_cost(stack_a, stack_b);
	if ((*stack_a)->content > (*stack_b)->content && cost == 4)
	{
		ra(stack_a);
	}
	cost = check_cost(stack_a, stack_b);
	if ((*stack_a)->content < (*stack_b)->content && cost == 4)
	{
		pb(stack_a, stack_b);
		sb(stack_b);
		pa(stack_b, stack_a);
		sb(stack_b);
		pb(stack_a, stack_b);
	}

	/*while (stack_b)
	{

	}*/
}
