/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:00:00 by riramli            #+#    #+#            */
/*   Updated: 2021/04/26 00:00:00 by riramli            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_of(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	ft_parsevalues(char **file, int *i, int *res)
{
	while (!ft_of(**file, " \n") && **file)
	{
		if (ft_strncmp(*file, ",0x", 3) == 0)
		{
			*i = 0;
			*file = *file + 3;
			while (!ft_of(**file, " \n") && **file)
			{
				if (!ft_of(**file, "0123456789abcdefABCDEF"))
					*res = *res * 0;
				*file = *file + 1;
			}
		}
		else if (**file == '-')
		{
			if (*i != 0)
					*res = *res * 0;
			else
				*i = 1;
		}
		else if (**file < '0' || **file > '9')
			*res = *res * 0;
		*file = *file + 1;
	}
}

int	ft_value(char *file)
{
	int		res;
	int		i;

	res = 1;
	i = 0;
	while (*file)
	{
		if (*file != ' ' && *file != '\n')
		{
			ft_parsevalues(&file, &i, &res);
		}
		else if (*file == ' ' || *file == '\n')
		{
			i = 0;
			file++;
		}
	}
	if (res == 0)
		ft_printf("Error: file has invalid values\n");
	return (res);
}
