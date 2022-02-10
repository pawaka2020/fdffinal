/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2021/04/26 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
calculates how many pixels are needed to draw from point1 to point2
*/
int	getpixels(t_point point1, t_point point2)
{
	double	deltax;
	double	deltay;
	int		pixels;

	deltax = point2.x - point1.x;
	deltay = point2.y - point1.y;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	return (pixels);
}

/*
draws a line between point 1 and point 2
had to use a struct because there are too many variables to declare
*/
void	ft_drawline(t_point point1, t_point point2, void *mlx, void *win)
{
	t_delta	d;

	d.deltax = point2.x - point1.x;
	d.deltay = point2.y - point1.y;
	d.pixels = getpixels(point1, point2);
	d.deltax /= d.pixels;
	d.deltay /= d.pixels;
	d.x = point1.x;
	d.y = point1.y;
	d.c = point1.color;
	d.deltacolor = point2.color - point1.color;
	d.deltacolor /= d.pixels;
	while (d.pixels)
	{
		mlx_pixel_put(mlx, win, d.x, d.y, d.c);
		d.x += d.deltax;
		d.y += d.deltay;
		d.c += d.deltacolor;
		d.pixels--;
	}
}
