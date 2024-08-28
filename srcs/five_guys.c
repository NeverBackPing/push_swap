/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_guys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:27:50 by sjossain          #+#    #+#             */
/*   Updated: 2024/08/28 18:25:19 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/swap.h"

void	five_guys_part2(t_data **stack_a, t_data **stack_b, int i)
{
	t_data	*prev;
	t_data	*next;
	t_data	*small;

	while (i--)
	{
		small = small_index(*stack_a);
		if (*stack_a == small)
			pb(stack_a, stack_b);
		else
		{
			prev = small->prev;
			next = small->next;
			if (prev)
				prev->next = next;
			if (next)
				next->prev = prev;
			small->next = *stack_a;
			small->prev = NULL;
			if (*stack_a)
				(*stack_a)->prev = small;
			*stack_a = small;
			pb(stack_a, stack_b);
		}
	}
}

void	five_guys(t_data **stack_a, t_data **stack_b)
{
	int		len;
	t_data	tmp;

	len = lenstruct(stack_a);
	while (len > 3)
	{
		pb(stack_a, stack_b);
		len = lenstruct(stack_a);
	}
	short_values(stack_a);
	while (stack_b)
	{
		tmp = stack_a
		while (tmp)
		{
			if (stack_b->content < tmp->content)
				pa(stack_b, stack_a);
			tmp = stack_a->next;
			if (stack_b->content < tmp->content)
			{
				ra(stack_a);
				pa(stack_b, stack_a);
			}
			tmp = tmp->next
		}
	}
}
