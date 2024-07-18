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

int	small_value(t_data **stack)
{
	int		small;
	t_data	*tmp;

	small = 0;
	tmp = *stack;
	if (tmp)
		small = tmp->content;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (small > tmp->content && tmp != NULL)
			small = tmp->content;
		tmp = tmp->next;
	}
	return (small);
}

int	great_value(t_data **stack)
{
	int		great;
	t_data	*tmp;

	great = 0;
	tmp = *stack;
	if (tmp)
		great = tmp->content;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (great < tmp->content && tmp != NULL)
			great = tmp->content;
		tmp = tmp->next;
	}
	return (great);
}


int	check_cost(t_data **stack, t_data **another)
{
	t_data	*tmp;
	t_data	*tmp2;
	int		check;
	//t_data	*end;

	check = 0;
	//end = 0;
	tmp = *stack;
	tmp2 = *another;
	//end = last(tmp);
	if (tmp->content > great_value(another))
	{
		check++;
		if (tmp2->content != great_value(another) && tmp->content != small_value(stack))
			check++;
	}
	else
	{
		check++;
		if (tmp->content < small_value(another))
			check++;
		else
		{
			check++;
			//if (tmp->content)
		}
	}
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

	cost = 0;
	start(stack_a, stack_b);
	cost = check_cost(stack_a, stack_b);
	printf("\ncost: %d\n", cost);
	if ((*stack_a)->content > (*stack_b)->content && cost == 2)
	{
		rb(stack_b);
		pb(stack_a, stack_b);
	}
	cost = check_cost(stack_a, stack_b);
	printf("\ncost 2: %d\n", cost);
	if ((*stack_a)->content < small_value(stack_b) && cost == 2)
	{
		pb(stack_a, stack_b);
		if ((*stack_a)->content == great_value(stack_a))
			rr(stack_a, stack_b);
		else
			rb(stack_b);

	}
	cost = check_cost(stack_a, stack_b);
	printf("\ncost 3: %d\n", cost);
	if ((*stack_a)->content < small_value(stack_b) && cost == 2)
	{
		pb(stack_a, stack_b);
		if ((*stack_a)->content == great_value(stack_a))
			rr(stack_a, stack_b);
		else
			rb(stack_b);

	}
	/*while (stack_b)
	{

	}*/
}
