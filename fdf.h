/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/01/01 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
//for exit(0) allowing termination of program
# include <stdlib.h>
/*for write()*/
# include <unistd.h>
/*for O_RDLY to be used together with write()*/
# include <fcntl.h>
/*for malloc() and free()*/
# include <stdlib.h>
/*for trigonometry calculations*/
# include <math.h>
/*other required functions*/
# include "mylibft/mylibft.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;
typedef struct s_pointmeta
{
	int	size;
	int	rows;
	int	columns;
	int	length;
	int	originx;
	int	originy;
}	t_pointmeta;
typedef struct s_mapdata
{
	t_point		*points;
	t_pointmeta	meta;
}	t_mapdata;
typedef struct s_delta
{
	double	deltax;
	double	deltay;
	double	deltacolor;
	double	x;
	double	y;
	double	c;
	int		pixels;
}	t_delta;
typedef struct s_trans
{
	int		centerx;
	int		centery;
	float	deltax;
	float	deltay;
	float	rad;
	float	tan;
}	t_trans;
//for creating images because fdf doesn't allow pixel drawing.
//image, address, bits per pixel, length, endian.
typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endi;
}	t_imgdata;
int			ft_startfdf(char *map);
int			ft_closefdf(int keycode, t_vars *vars);
t_mapdata	ft_drawmap(char *map);
t_mapdata	ft_getpoints(char *map);
char		*ft_getstring(char *map);
t_mapdata	ft_transform(t_mapdata mapdata, float rad1, float rad2);
void		ft_drawimage(t_mapdata mapdata, void *mlx, void *win);
int			ft_atoi_hexa(char *str);
t_pointmeta	ft_getmeta(char *str);
void		ft_plotpoints(int *x, int *y, t_mapdata *mapdata, char *str);
int			getzlength(char *str);
int			ft_valid(int argc, char **argv);
int			ft_content(char *file);
int			ft_value(char *file);
void		ft_drawlineimg(t_imgdata id, t_point point1, t_point point2);

#endif
