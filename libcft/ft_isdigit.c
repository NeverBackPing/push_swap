/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:46:36 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/25 02:42:58 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isdigit(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = -1;
	while (str[i] != '\0')
	{
		if ((str[i] == 32) || ((str[i] >= 48 && str[i]<= 57) ) || ft_signe(str) == 0)
		{
			check++;
		}
		i++;
	}
	return (check);
}
/*int	main(void)
{
	printf("%d\n", ft_isdigit('6'));
}*/
