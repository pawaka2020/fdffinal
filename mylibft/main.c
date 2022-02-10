/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/01/01 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
test with 'gcc main.c *.a'
remember to create 'text' first.
*/
#include "mylibft.h"

int	main(void)
{
	int		fd;
	int		read;
	char	*line;
	char	*str;

	fd = open("text", O_RDONLY);
	read = 0;
	line = 0;
	str = 0;
	while (read == 0)
	{
		line = get_next_line(fd);
		if (!line)
			read = 1;
		else
			str = ft_strjoin(str, line);
	}
	ft_printf("%s", str);
	free(line);
	free(str);
}
