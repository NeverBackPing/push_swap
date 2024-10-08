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

void	five_guys(t_data **stack_a, t_data **stack_b)
{
	int	len;
	int	tmp;
	int	great;
	int	small;

	len = lenstruct(stack_a);
	while (len-- > 3)
		pb(stack_a, stack_b);
	short_values(stack_a);
	great = great_value(stack_a);
	small = small_value(stack_a);
	while (*stack_b)
	{
		tmp = (*stack_b)->content;
		if (tmp < small)
			small = insert_smallest(stack_a, stack_b, small);
		else if (tmp > great)
			great = insert_greatest(stack_a, stack_b, great);
		else if (tmp < (*stack_a)->next->content)
			william(stack_a, stack_b);
		else if ((tmp < (*stack_a)->next->next->content) && tmp < great)
			insert_middle(stack_a, stack_b);
		else if (tmp < great && (tmp > (*stack_a)->next->next->content))
			insert_before_greatest(stack_a, stack_b);
	}
}
