/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:19:24 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/28 20:21:49 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *ptr;
	int lenght_1;
	int lenght_2;
	int i;
	int j;

	lenght_1 = ft_strlen(s1);
	lenght_2 = ft_strlen(s2);
	ptr = malloc (lenght_1 + lenght_2 + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < lenght_1)
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < lenght_2)
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	free(s1);
	return (ptr);	
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		dest_len;
	int		index;

	index = 0;
	dest_len = 0;
	dest_len = (ft_strlen(s) + 1);
	dest = (char *) malloc(sizeof(char) * dest_len);
	if (!dest)
		return (NULL);
	dest[0] = '\0';
	while (s[index])
	{
		dest[index] = s[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
char	*ft_check_nl(const char *s, int c)
{
	int	i;

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
