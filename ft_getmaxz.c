/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmaxz                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/01/01 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//this is for calculating the max
//value of z (height of map)
//to help in calculating distance
//between points(and hence map size)
int	getzlength(char *str)
{
	int	maxz;
	int	z;

	maxz = 0;
	z = 0;
	while (str && *str)
	{
		if (*str != ' ' && *str != '\n')
		{
			z = abs(atoi(str));
			if (z > maxz)
				maxz = z;
			while (*str && *str != ' ' && *str != '\n')
				str++;
		}	
		str++;
	}
	ft_printf("max height %d\n", maxz);
	return (maxz);
}
