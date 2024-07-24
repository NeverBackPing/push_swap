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

t_data	*small_value(t_data *stack)
{
	long	small;
	t_data	*small_value;

	small = 0;
	if (!stack)
		return (NULL);
	small = LONG_MAX;
	while (stack != NULL)
	{
		if (small > stack->content)
		{
			small = stack->content;
			small_value = stack;
		}
		stack = stack->next;
	}
	return (small_value);
}

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

int	init_sort(t_data **stack_a, t_data **stack_b)
{
	int		len_stack;

	if (init_index(stack_a))
		return (1);
	len_stack = lenstruct(stack_a);
	if (len_stack == 2)
		sa(stack_a);
	else if (len_stack == 3)
		short_values(stack_a);
	else if (len_stack == 5)
		five_guys(stack_a, stack_b);
	/*else
		start(stack_a, stack_b);*/
	return (0);
}
