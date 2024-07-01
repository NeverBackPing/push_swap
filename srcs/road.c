/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:59:01 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/28 15:19:23 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/swap.h"

void	sort(t_data **stack_a)
{
	t_data	**head;

	head = stack_a;
	if (lenstruct(head) <= 5)
	{
		/*small_data(&stack_a);*/
	}
	/*else
		big_data(&stack_a);*/

}

void	road(t_data **stack_a/*, t_data *stack_b, char *str*/)
{
	t_data	**head;
	t_data	**head_sec;

	head = stack_a;
	head_sec= stack_a;
	if (sa(head_sec))
	{
		head = head_sec;
		sa(head);
		ft_printf("sa\n");
	}
}