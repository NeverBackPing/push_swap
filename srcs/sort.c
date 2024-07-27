/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   sort.c	 :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: sjossain <sjossain@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2024/06/17 17:59:01 by sjossain	  #+#	#+#	 */
/*   Updated: 2024/06/28 15:19:23 by sjossain	 ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../includes/swap.h"

bool	is_sorted(t_data *stack_a, int i, const int max)
{
	if (i > max)
		return (false);
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

int	get_max_bits(t_data *stack)
{
	int	max;
	int	bits;

	max = 0;
	bits = 0;
	while (stack)
	{
		if (stack->position > max)
			max = stack->position;
		stack = stack->next;
	}
	while (max > 0)
	{
		bits++;
		max >>= 1;
	}
	return (bits);
}

void	start(t_data **stack_a, t_data **stack_b)
{
	int				i;
	int				j;
	t_data			*top;
	const int		max_bits = get_max_bits(*stack_a);
	const int		size = stack_size(*stack_a);

	i = 0;
	while (!is_sorted(*stack_a, i, max_bits))
	{
		j = 0;
		while (j++ < size)
		{
			top = *stack_a;
			if (top)
			{
				if ((top->position >> i) & 1)
					ra(stack_a);
				else
					pb(stack_a, stack_b);
			}
		}
		while (*stack_b)
			pa(stack_b, stack_a);
		i++;
	}
}

int	init_sort(t_data **stack_a, t_data **stack_b)
{
	int	len_stack;

	if (init_index(stack_a))
		return (1);
	len_stack = lenstruct(stack_a);
	if (len_stack == 2)
		sa(stack_a);
	else if (len_stack == 3)
		short_values(stack_a);
	else if (len_stack <= 5)
		five_guys(stack_a, stack_b);
	else
		start(stack_a, stack_b);
	return (0);
}
