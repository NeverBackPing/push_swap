/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:38:27 by sjossain          #+#    #+#             */
/*   Updated: 2024/07/23 20:05:15 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	short_values(t_data **stack_a)
{
	int	great;

	great = great_value(stack_a);
	if ((*stack_a)->content == great)
		ra(stack_a);
	else if ((*stack_a)->next->content == great)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

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
	int		i;

	i = 2;
	five_guys_part2(stack_a, stack_b, i);
	i = 2;
	short_values(stack_a);
	while (i--)
		pa(stack_b, stack_a);
}
