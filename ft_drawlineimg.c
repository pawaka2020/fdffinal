/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawlineimg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:00:00 by riramli            #+#    #+#            */
/*   Updated: 2021/04/26 00:00:00 by riramli            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	getpixels2(t_point point1, t_point point2)
{
	double	deltax;
	double	deltay;
	int		pixels;

	deltax = point2.x - point1.x;
	deltay = point2.y - point1.y;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	return (pixels);
}

void	ft_piximg(t_imgdata *id, int x, int y, int color)
{
	int		pixelpos;
	char	*addr2;

	pixelpos = (x * (id->bpp / 8)) + (y * id->len);
	addr2 = id->addr + pixelpos;
	*(unsigned int *)addr2 = color;
}

void	ft_drawlineimg(t_imgdata id, t_point point1, t_point point2)
{
	t_delta		d;
	t_imgdata	id2;

	id2 = id;
	d.deltax = point2.x - point1.x;
	d.deltay = point2.y - point1.y;
	d.pixels = getpixels2(point1, point2);
	d.deltax /= d.pixels;
	d.deltay /= d.pixels;
	d.x = point1.x;
	d.y = point1.y;
	d.c = point1.color;
	d.deltacolor = point2.color - point1.color;
	d.deltacolor /= d.pixels;
	while (d.pixels)
	{
		ft_piximg(&id2, d.x, d.y, d.c);
		d.x += d.deltax;
		d.y += d.deltay;
		d.c += d.deltacolor;
		d.pixels--;
	}
}
