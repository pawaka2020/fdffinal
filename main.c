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
Closes program when Esc key is pressed.
*/
int	ft_closefdf(int keycode, t_vars *vars)
{
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		ft_printf("Esc pressed. Exiting program\n");
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

	mapdata = ft_drawmap(map);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 2560, 1600, "fdf");
	ft_drawimage(mapdata, vars.mlx, vars.win);
	mlx_hook(vars.win, 2, 1L << 0, ft_closefdf, &vars);
	mlx_loop(vars.mlx);
	return (1);
}

/*
Validates the file first
If file is validated, then fdf program is started.
*/
int	main(int argc, char **argv)
{
	if (ft_valid(argc, argv))
		ft_startfdf(argv[1]);
}
