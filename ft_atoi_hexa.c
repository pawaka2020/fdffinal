/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2021/04/26 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
converts a hexa number string (ie 0xFFFFFF) to a decimal int.
though the number will be decimal, it is perfectly usable for functions.
works for both large-cap strings as well as small-cap (ie 0xffffff)
*/
int	getnb(char c)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int	ft_atoi_hexa(char *str)
{
	int		i;
	int		res;
	char	c;

	i = -1;
	res = 0;
	c = 0;
	while (i++, str[i] && str[i] != ' ')
	{
		c = str[i];
		if (c >= 97 && c <= 102)
			c = c - 32;
		res = (res * 16) + getnb(c);
	}
	return (res);
}
/*
int	main(void)
{
	char	*str = "0xFFFFFFFF";
	str = str + 2;
	int	i = ft_atoi_hexa(str);
	printf("i = %d\n", i);
}
*/
