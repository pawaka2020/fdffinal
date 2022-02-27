/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawpoints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2021/04/26 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printrows(void *mlx, void *win, t_mapdata mp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mp.meta.size -1)
	{
		ft_drawline(mp.points[i], mp.points[i + 1], mlx, win);
		i++;
		j++;
		if (j == mp.meta.columns - 1)
		{
			i++;
			j = 0;
		}
	}
}

void	printcolumns(void *mlx, void *win, t_mapdata mp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < mp.meta.columns)
	{
		while (j < mp.meta.rows - 1)
		{
			ft_drawline(mp.points[i], mp.points[i + mp.meta.columns], mlx, win);
			i = i + mp.meta.columns;
			j++;
		}
		j = 0;
		k++;
		i = k;
	}
}

/*
drawing a map simply involves connecting columns and rows together
while other fdf uses a two dimentional char array to denote columns and rows,
I simply make use of a map's metadata instead.
drawing dots isn't necessary because dots will be overlapped.
*/
void	ft_drawpoints(t_mapdata mp, void *mlx, void *win)
{
	printrows(mlx, win, mp);
	printcolumns(mlx, win, mp);
}
