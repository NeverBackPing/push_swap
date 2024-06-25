/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:10:42 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/25 01:05:54 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_signe(char *str)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (str[i] != '\0')
	{
		if ( str[i]== 45 || str[i] == 43)
		{
			check++;
		}
		if (check > 1)
			return (1);
		i++;
	}

	return (0);
}
/*int	main(void)
{
	printf("%d\n", ft_signe('+'));
}*/