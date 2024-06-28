/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:10:42 by sjossain          #+#    #+#             */
/*   Updated: 2024/06/26 17:10:22 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	just_num(char *str)
{
	int		i;
	int		check;

	i = 0;
	check = 1;
	while ((str[i] >= 48 && str[i] <= 57) || (str[i]== 45 || str[i] == 43))
	{
		if (!(str[i] >= 48 && str[i] <= 57))
		{
			check = 0;
			return (check);
		}
		i++;
	}
	return (check);
}

int		ft_signe(char *str)
{
	int		i;
	int		j;
	int		check_signe;

	i = 0;
	j = 0;
	check_signe = 0;
	if (just_num(str))
			return (0);
	else
	{
		while (str[i] != '\0')
		{
			if ( str[j]== 45 || str[j] == 43 || (str[i] == 32))
			{
				check_signe++;
				j++;
				if ((str[i] == '-' && str[j] == '0'))
					return (1);
				while (str[j] >= 48 && str[j] <= 57)
						j++;
				if ((str[j]== 45 || str[j] == 43) && (str[i] != 32))
					check_signe++;
			}
			if (check_signe > 1)
				return (1);
			check_signe = 0;
			i = j;
		}
	}
	return (0);
}
/*int	main(void)
{
	printf("%d\n", ft_signe('+'));
}*/