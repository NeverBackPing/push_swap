/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:10:42 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/25 18:02:37 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	check_num(char *str)
{
	int		i;

	i = 0;
	while ((str[i] != '\0') && (str[i] >= 48 && str[i] <= 57))
	{
		i++;
	}
	return (i);
}

int		ft_signe(char *str)
{
	int		i;
	int		check_signe;

	i = 0;
	check_signe = 0;
	while (str[i] != '\0')
	{
		if ( str[i]== 45 || str[i] == 43)
		{
			check_signe++;
			i++;
			if (str[i] >= 48 && str[i] <= 57)
				i = i + check_num((str + i));
			if ( str[i]== '-' || str[i] == 43)
				check_signe++;
		}
		if (check_signe > 1)
			return (1);
		check_signe = 0;
		i++;
	}
	return (0);
}
/*int	main(void)
{
	printf("%d\n", ft_signe('+'));
}*/