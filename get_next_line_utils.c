/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:19:24 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/16 21:10:23 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"

size_t ft_newlinechr(const void *s)
{
	char n;
	size_t position;
	
	n = s;
	position = 0;
	while (n != '\n')
		position++;
	return (position);	
}

char *strdup(char *s, int true)
{
	
}
