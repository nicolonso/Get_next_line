/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:19:24 by nalfonso          #+#    #+#             */
/*   Updated: 2025/06/03 21:37:01 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *ptr;
	size_t i;
	size_t j;
	size_t l1;
	size_t l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = malloc (l1 + l2 + 1);
	//ptr = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	if (s1)
		while (i < l1)
		{
			ptr[i] = s1[i];
			i++;
		}
	j = 0;
	if (s2)
		while (j < l2)
		{
			ptr[i + j] = s2[j];
			j++;
		}
	ptr[i + j] = '\0';
	free(s1);
	return (ptr);	
}

char	*ft_check_nl(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	if ((char) c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
