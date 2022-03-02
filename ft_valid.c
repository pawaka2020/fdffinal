/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/01/01 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_oneparam(int argc)
{
	if (argc == 2)
		return (1);
	else
		ft_printf("Error: must have one param\n");
	return (0);
}

int	ft_exist(char *file)
{
	int		fd;
	int		result;
	char	c;

	fd = open(file, O_RDONLY);
	result = read(fd, &c, 1);
	if (result == -1)
	{
		ft_printf("Error: file not found\n");
		exit (0);
		return (0);
	}
	else
		return (1);
}

int	ft_validext(char *file)
{
	int	len;

	if (ft_exist(file))
	{
		len = ft_strlen(file);
		while (*file)
		{
			if (ft_strncmp(file, ".fdf", len) == 0)
				return (1);
			file++;
			len--;
		}
	}
	ft_printf("Error: invalid file name\n");
	return (0);
}	

int	ft_valid(int argc, char **argv)
{
	int		result;
	char	*file;

	ft_printf("Validating map. Please wait...\n");
	result = 0;
	if (ft_oneparam(argc))
	{
		if (ft_validext(argv[1]))
		{
			file = ft_getstring(argv[1]);
			result = ft_value(file);
		}
	}
	free(file);
	return (result);
}
