/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawimage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/01/01 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printrows2(t_mapdata mp, t_imgdata id)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mp.meta.size -1)
	{
		ft_drawlineimg(id, mp.points[i], mp.points[i + 1]);
		i++;
		j++;
		if (j == mp.meta.columns - 1)
		{
			i++;
			j = 0;
		}
	}
}

void	printcolumns2(t_mapdata mp, t_imgdata id)
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
			ft_drawlineimg(id, mp.points[i], mp.points[i + mp.meta.columns]);
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
/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}
*/
//draws image
void	ft_drawimage(t_mapdata mp, void *mlx, void *win)
{
	t_imgdata	id;

	id.img = mlx_new_image(mlx, 2560, 1600);
	id.addr = mlx_get_data_addr(id.img, &id.bpp, &id.len, &id.endi);
	printrows2(mp, id);
	printcolumns2(mp, id);
	mlx_put_image_to_window(mlx, win, id.img, 0, 0);
	mlx_destroy_image(mlx, id.img);
}
