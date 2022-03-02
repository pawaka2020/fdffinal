/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <riramli@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:00:00 by riramli            #+#    #+#            */
/*   Updated: 2021/04/26 00:00:00 by riramli            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
retrieves a matrix of values from a map file, represented as a single string.
some other cadets use a two-dimensional char array, but I just
use a single-dimensional char array instead.
*/
char	*ft_getstring(char *map)
{
	int		fd;
	int		read;
	char	*str;
	char	*str2;
	char	*tmp;

	fd = open(map, O_RDONLY);
	read = 0;
	str = 0;
	str2 = 0;
	while (read == 0)
	{
		str2 = get_next_line(fd);
		if (str2 == 0)
			read = 1;
		else
		{
			tmp = str;
			str = ft_strjoin(tmp, str2);
			free(str2);
			free(tmp);
		}
	}
	close(fd);
	return (str);
}

/*
from the string matrix, convert into an array of points with color.
the mandatory part requires the map to be -07854 rad rotated horizontally,
0.7500 rad rotated vertically.
*/
t_mapdata	ft_convert(char *str, float rad1, float rad2)
{
	int			x;
	int			y;
	t_mapdata	mapdata;

	mapdata.meta = ft_getmeta(str);
	mapdata.points = (t_point *)malloc((mapdata.meta.size) * sizeof(t_point));
	x = mapdata.meta.originx;
	y = mapdata.meta.originy;
	ft_plotpoints(&x, &y, &mapdata, str);
	mapdata = ft_transform(mapdata, rad1, rad2);
	return (mapdata);
}

/*
converts map into matrix,
then converts matrix into point+color array.
*/
t_mapdata	ft_getpoints(char *map)
{
	char		*str;
	t_mapdata	mapdata;

	str = ft_getstring(map);
	mapdata = ft_convert(str, -0.7854, 0.7500);
	free(str);
	return (mapdata);
}

t_mapdata	ft_drawmap(char *map)
{
	t_mapdata	mapdata;

	ft_printf("Processing map. Please wait...\n");
	mapdata = ft_getpoints(map);
	return (mapdata);
}
