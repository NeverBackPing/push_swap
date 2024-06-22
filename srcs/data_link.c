/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/22 16:40:14 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/swap.h"

data_s	*mew_data(int content)
{
	data_s	*node;

	node = malloc(sizeof(data_s));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	add_data(data_s **lst, data_s *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	data_delone(data_s *lst)
{
	if (lst == NULL)
		return ;
	free (lst);
}

void	merge(data_s *stack_a, data_s *stack_b)
{
	data_s *a_head = stack_a;
	data_s *b_head = stack_b;
	data_s *a_next;
	data_s *b_next;

	a_head = stack_a;
	b_head = stack_b;
	// While there are available positions in p
	while (a_head != NULL && b_head != NULL)
	{
		// Save next pointers
		a_next = a_head->next;
		b_next = b_head->next;

		// Make b_head as next of a_head
		b_head->next = a_next;  // Change next pointer of b_head
		a_head->next = b_head;  // Change next pointer of a_head

		// Update current pointers for next iteration
		a_head = a_next;
		b_head = b_next;
	}
	stack_b = b_head; // Update head pointer of second list
}

void	data_clear(data_s **lst)
{
	data_s	*tmp;
	data_s	*tmp2;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		data_delone(tmp);
		tmp = tmp2;
	}

	*lst = NULL;
}
