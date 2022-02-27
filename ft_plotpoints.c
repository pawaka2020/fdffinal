/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plotpoints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2021/04/26 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
gets length of a number.
ie if number is -3 the length is 2.
*/
int	ft_getnbrlen(int i)
{
	int	len;

	len = 0;
	if (i < 0)
	{
		i = i * -1;
		len++;
	}
	else if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	return (len);
}

//fills in points
//skips the map string depending on number + color length
//color goes to violet a higher z values, but capped at white at 0.
void	ft_setpoint(char **str, t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
	point->z = ft_atoi(*str);
	if (point->z <= 0)
		point->color = 0xFFFFFF;
	else
		point->color = (0xFFFFFF) - (838848 * point->z);
	*str = *str + ft_getnbrlen(point->z);
}

void	ft_setcolor(char **str, t_point *point)
{
	*str = *str + 3;
	point->color = ft_atoi_hexa(*str);
	while (**str != ' ' && **str != 0 && **str != '\n')
		*str = *str + 1;
}

void	ft_plotpoints(int *x, int *y, t_mapdata *mapdata, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '-' || (*str >= '0' && *str <= '9'))
		{
			*x = *x + mapdata->meta.length;
			ft_setpoint(&str, &mapdata->points[i], *x, *y);
			i++;
		}
		else if (*str == ',')
			ft_setcolor(&str, &mapdata->points[i - 1]);
		else if (*str == '\n')
		{
			*x = mapdata->meta.originx;
			*y = *y + mapdata->meta.length;
			str++;
		}
		else if (*str == ' ')
			str++;
	}
}
