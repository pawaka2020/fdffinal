/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:00:00 by riramli            #+#    #+#            */
/*   Updated: 2021/04/26 00:00:00 by riramli            ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_skip(char *file)
{
	int	i;

	i = 0;
	while (file[i] != 0 && file[i] != '\n' && file[i] != ' ')
		i++;
	i--;
	return (i);
}

void	ft_checkcolumn(int *col, int *col2, int *cmp)
{
	if (*cmp == 0)
	{
		*col2 = *col;
		*cmp = 1;
		*col = 0;
	}
	else if (*cmp != 0 && *col != *col2)
	{	
		ft_printf("Error: not a rectangular matrix\n");
		exit (0);
	}
	else if (*cmp != 0 && *col == *col2)
		*col = 0;
}

void	ft_addcolumn(int *col, char **file)
{
	*col = *col + 1;
	*file = *file + ft_skip(*file);
}

//file must have rectangular matrix
int	ft_content(char *file)
{
	int	col;
	int	col2;
	int	cmp;
	int	len;

	col = 0;
	col2 = -1;
	cmp = 0;
	len = ft_strlen(file) + 0;
	if (len > 50000)
		len = len / 100;
	while (*file)
	{
		if (*file == '\n')
			ft_checkcolumn(&col, &col2, &cmp);
		else if (*file != ' ')
			ft_addcolumn(&col, &file);
		file++;
		len--;
	}
	return (1);
}
/*
int	main(void)
{
	char	*file;

	file = "1 2 3\n4 5 6\n7 8 9";
	validcontent(file);
}
*/
