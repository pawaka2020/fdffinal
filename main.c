/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kolim <kolim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:00:00 by kolim             #+#    #+#             */
/*   Updated: 2021/04/26 00:00:00 by kolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
FDF in a nutshell:
converts the map into a matrix of x, y, z coordinates with color.
print the coordinates onto screen.
connect the coordinates by column and then by rows.
*/
/*
Closes program when Esc key is pressed.
*/
int	ft_closefdf(int keycode, t_vars *vars)
{
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_printf("Esc pressed. Exiting program ...\n");
		exit (0);
	}
	return (1);
}

/*
Starts fdf program.
*/
int	ft_startfdf(char *map)
{
	t_vars		vars;
	t_mapdata	mapdata;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1440, 900, "fdf");
	mapdata = ft_drawmap(map);
	ft_drawpoints(mapdata, vars.mlx, vars.win);
	mlx_hook(vars.win, 2, 1L << 0, ft_closefdf, &vars);
	mlx_loop(vars.mlx);
	return (1);
}

/*
sets valid if there is only one argument (argc == 2)
*/
int	ft_valid(int argc)
{
	if (argc == 2)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	if (ft_valid(argc))
		ft_startfdf(argv[1]);
	else
		ft_printf("ERROR: invalid parameter\n");
}
