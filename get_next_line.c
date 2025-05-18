/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:19:28 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/16 21:20:41 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"

static char *ln_by_ln(fd)
{
	char *line;
	size_t lenght;

	read(fd, line, BUFFER);
	lenght = ft_newlinechr(line);
	line = (char*) malloc (lenght);
	if (!line)
		return (NULL);
	ft_
	return (line);
}

char	*get_next_line(int fd)
{
	static char *line;

	line =(char *) malloc(1);
	if (!line)
		return (NULL);
	line = ft_ln_by_ln(fd);
	if (fd < 0);
		return (NULL);	
	return (line);
}
