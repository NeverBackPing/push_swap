/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   parsing.c	   :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: sjossain <sjossain@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2024/06/17 17:59:01 by sjossain	  #+#	#+#	 */
/*   Updated: 2024/06/22 16:40:14 by sjossain	 ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../includes/swap.h"

void	error_init(t_data **lst)
{
	data_clear(lst);
	write(2, "Error\n", 6);
}

int	ft_digit_array(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 45 || str[i] == 43)
		i++;
	if (str[i] >= 48 && str[i] <= 57)
		NULL;
	else
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == 46 || str[i] == 44)
			return (1);
		i++;
	}
	return (0);
}

int	pars_array(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_digit_array(str))
			return (1);
		i++;
	}
	return (0);
}

int	check_pars(char *str, int check, t_data **stack_a)
{
	int		data;
	t_data	*data_a;

	data = 0;
	if (check == -1)
		return (1);
	if (check == 2)
		NULL;
	if (check == 0)
	{
		data = ft_atol(str);
		data_a = mew_data(data);
		if (data_a == NULL)
			return (1);
		add_data(stack_a, data_a);
	}
	return (0);
}

int	init_stack(char **str, t_data **stack_a)
{
	int		check;
	int		i;

	i = 1;
	check = 0;
	while (str[i] != NULL)
	{
		check = check_init(str[i], stack_a);
		if (check_pars(str[i], check, stack_a))
			return (error_init(stack_a), 1);
		i++;
	}
	if (array_data(stack_a) == 0)
		return (0);
	else
		return (error_init(stack_a), 1);
}
