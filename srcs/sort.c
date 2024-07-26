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

bool	is_sorted(t_data *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

int compter_bits(int num)
{
	int	count;

	count = 0;
	while (num > 0)
	{
		count += num & 1;
		num >>= 1;
	}
	return (count);
}

t_data	*small_index(t_data *stack)
{
	t_data *small;
	t_data *current;

	small = stack;
	current = stack;
	while (current != NULL)
	{
		if (current->position < small->position)
		small = current;
		current = current->next;
	}
	return (small);
}

/*t_data	*small_value(t_data *stack)
{
	long	small;
	int		bit_count;
	t_data	*small_value;

	small = 0;
	bit_count = 0;
	if (!stack)
		return (NULL);
	small = LONG_MAX;
	while (stack != NULL)
	{
		bit_count =  compter_bits(stack->content);
		if (small > stack->content)
		{
			small = bit_count;
			small_value = stack;
		}
		stack = stack->next;
	}
	return (small_value);
}*/

void print_list(t_data **head)
{
	t_data *current = *head;
	while (current != NULL)
	{
		printf("Content: %d, Position: %d\n", current->content, current->position);
		current = current->next;
	}
}

/*void	start(t_data **stack_a, t_data **stack_b)
{
	int		size;
	int		position;
	int		rotations;
	t_data	*small;
	t_data	*current;

	position = 0;
	rotations = 0;
	size = lenstruct(stack_a);
 	while (size-- > 2)
	{
		printf("\n");
		print_list(stack_a);
		small = small_index(*stack_a);
		if (*stack_a == small)
			pb(stack_a, stack_b);
		else
		{
			current = *stack_a;
			position = 0;
			while (current != small)
			{
			current = current->next;
			position++;
			}
			size = lenstruct(stack_a);
			if (position < (size - position))
			rotations = position;
			else
			rotations = size - position;
			while (rotations--)
			ra(stack_a);
			pb(stack_a, stack_b);
		}
		if (is_sorted((*stack_a)))
			break;
	}
	printf("\n");
	if (*stack_a != NULL && (*stack_a)->next != NULL)
		if ((*stack_a)->position > (*stack_a)->next->position)
			sa(stack_a);
	while (*stack_b != NULL)
		pa(stack_b, stack_a);
}*/
///////////////////////////////////////////////

void	rotate_to_top(t_data **stack_a, t_data *target)
{
	int size;
	int position;
	t_data *current;

	position = 0;
	current = *stack_a;
	size = lenstruct(stack_a);
	while (current != target)
	{
		current = current->next;
		position++;
	}
	if (position < (size - position))
		while (position--)
			ra(stack_a);
	else
		while (size-- > position)
			rra(stack_a);
}

int	loop_b_to_a(t_data *stack_a, t_data *insert)
{
	int		size;
	int		position;
	int		rotations;
	int		min_rotations;
	t_data	*current;

	size = 0;
	position = 0;
	rotations = 0;
	min_rotations = INT_MAX;
	rotations = 0;
	current = stack_a;
	 while (current != NULL)
	{
		if (insert->position < current->position)
		{
			if (position < (size - position))
				rotations = position;
			else
				rotations = size - position;
		}
		else
		{
			if (position < (size - position))
				rotations = size - position;
			else
				rotations = position;
		}
		if (rotations < min_rotations)
			min_rotations = rotations;
		current = current->next;
		position++;
	}
	return (min_rotations);
}


void	push_b_to_a(t_data **stack_a, t_data **stack_b)
{
	int		rotation;
	t_data	*insert;

	rotation = 0;
	while (*stack_b != NULL)
	{
		insert = *stack_b;
		rotation = loop_b_to_a(*stack_a, insert);
		if (rotation < (lenstruct(stack_a) - rotation))
		{
			while (rotation > 0)
			{
				printf("AAAAAAAAA\n");
				ra(stack_a);
				rotation--;
			}
		}
		else
		{
			while (lenstruct(stack_a) - rotation > 0)
			{
				rra(stack_a);
				rotation++;
			}
		}
		pa(stack_b, stack_a);
	}
}
////////////////////////////////////////////////////////////////
void	start(t_data **stack_a, t_data **stack_b)
{
	int		size;
	t_data	*small;

	size = lenstruct(stack_a);
	while (size > 2)
	{
		small = small_index(*stack_a);
		if (*stack_a == small)
			pb(stack_a, stack_b);
		else
		{
			rotate_to_top(stack_a, small);
			pb(stack_a, stack_b);
		}
		size = lenstruct(stack_a);
	}
	if (*stack_a != NULL && (*stack_a)->next != NULL)
		if ((*stack_a)->position > (*stack_a)->next->position)
			sa(stack_a);
	push_b_to_a(stack_a, stack_b);
}
///////////////////////////////////////////////////////////////


int	init_sort(t_data **stack_a, t_data **stack_b)
{
	int		len_stack;

	if (init_index(stack_a))
		return (1);
	print_list(stack_a);
	len_stack = lenstruct(stack_a);
	if (len_stack == 2)
		sa(stack_a);
	else if (len_stack == 3)
		short_values(stack_a);
	else if (len_stack <= 5)
		five_guys(stack_a, stack_b);
	else
		start(stack_a, stack_b);
	print_list(stack_a);
	return (0);
}
