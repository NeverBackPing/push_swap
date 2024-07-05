/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   command.c	  :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: sjossain <sjossain@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2024/06/17 17:59:01 by sjossain	  #+#	#+#	 */
/*   Updated: 2024/06/28 15:20:55 by sjossain	 ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../includes/swap.h"

int	lenstruct(t_data **stack)
{
	int		len;
	t_data	*head;

	len = 0;
	head = *stack;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

int	sa(t_data **stack_a)
{
	t_data	*first;
	int		tmp;

	tmp = 0;
	first = *stack_a;
	if (first == NULL || first->next == NULL)
		return (1);
	tmp = first->content;
	first->content = first->next->content;
	first->next->content = tmp;
	ft_printf("sa\n");
	return (0);
}

void	ra(t_data **stack_a)
{
	int		tmp;
	int		lst;
	t_data	*current;

	current = *stack_a;
	if (current == NULL || current->next == NULL)
		return;
	lst = current->content;
	while (current->next != NULL)
	{
		tmp = current->next->content;
		current->content = tmp;
		current = current->next;
	}
	current->content = lst;
	ft_printf("ra\n");
}


void push(t_data **stack, t_data *stack_a)
{

	(*stack) = stack_a;
}

t_data	*pop(t_data **stack_a)
{
	t_data	*tmp;

	if (*stack_a == NULL)
		return (0);
	tmp = *stack_a;
	(*stack_a) = tmp->next;
	return ((*stack_a));
}

void	pb(t_data **stack_a, t_data **stack_b)
{
	t_data	*a;

	a = *stack_a;
	if (a == NULL)
		return;
	push(stack_b, a->content);
	(*stack_a) = pop(stack_a);
	ft_printf("pb\n");
}

void	rra(t_data **stack_a)
{
	int		tmp;
	int		lst;
	t_data	*current;
	t_data	*head;

	head = *stack_a;
	current = *stack_a;
	if (current == NULL || current->next == NULL)
		return;
	tmp = current->content;
	head = last(head);
	lst = head->content;
	current->content = lst;
	current = current->next;
	while (current != NULL)
	{
		lst = tmp;
		tmp = current->content;
		current->content = lst;
		current = current->next;
	}
	ft_printf("rra\n");
}
