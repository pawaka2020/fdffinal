/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmeta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:00:00 by kolim             #+#    #+#             */
/*   Updated: 2021/04/26 00:00:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//rows = number of nl or EOF
int	getrows(char *str)
{
	int		i;
	int		rows;

	i = -1;
	rows = 0;
	while (i++, str[i])
		if (str[i] == '\n' || str[i] == 0)
			rows++;
	ft_printf("rows = %d\n", rows);
	return (rows);
}

//columns = number of non ' ' strings before the first newline.
int	getcolumns(char *str)
{
	int	i;
	int	columns;

	i = 0;
	columns = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ')
		{
			if (i == 0)
				columns++;
			else if (i != 0 && str[i - 1] == ' ')
				columns++;
		}
		i++;
	}
	ft_printf("columns = %d\n", columns);
	return (columns);
}

//length: distance between points
//try to fit in the largest diameter of map against horizontal
//screen length.
//hard mininum of 2 because 1 creates problems
int	getlength(t_pointmeta meta)
{
	int	length;

	if (meta.columns > meta.rows)
		length = 800 / meta.columns;
	else
		length = 800 / meta.rows;
	if (length < 2)
		length = 2;
	ft_printf("length = %d\n", length);
	return (length);
}

//obtain x, y coordinates for the first point of the map.
//important for plotting out the rest of the other points later.
void	getorigin(t_pointmeta	*meta)
{
	int		centerx;
	int		centery;
	double	shapex;
	double	shapey;

	centerx = 1440 / 2;
	centery = 900 / 2;
	shapex = ((meta -> columns - 1) / 2.0) * meta->length;
	shapey = ((meta -> rows - 1) / 2.0) * meta->length;
	meta->originx = meta->originx + (centerx - shapex);
	meta->originy = meta->originy + (centery - shapey);
}

//get metadata (rows, columns, size, length) of a map
t_pointmeta	ft_getmeta(char *str)
{
	t_pointmeta	meta;

	meta.rows = getrows(str);
	meta.columns = getcolumns(str);
	meta.size = meta.rows * meta.columns;
	meta.length = getlength(meta);
	meta.originx = 0 - meta.length;
	meta.originy = 0;
	getorigin(&meta);
	ft_printf("size = %d\n", meta.size);
	return (meta);
}
