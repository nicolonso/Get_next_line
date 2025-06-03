/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:19:28 by nalfonso          #+#    #+#             */
/*   Updated: 2025/06/03 21:55:20 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char *buffer_rest(char *buffer)
{
	int i;
	int j;
	
	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
	if (j == 0)
		return (free(buffer),NULL);
	return (buffer);
}


static char *extract_line(char *buffer)
{
	int i;
	int j;
	char *line;
	
	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
// char *help_get(int fd, char *buffer, ssize_t bytes)
// {
// 	char *tempory;
	
// 	tempory = malloc(BUFFER_SIZE + 1);
// 	if (!tempory)
// 		return (NULL);
// 	while (!ft_check_nl(buffer, '\n'))
// 	{
// 		bytes = read (fd, tempory, BUFFER_SIZE);
// 		if (bytes < 0 )
//             return (free(tempory), NULL);
// 		if (bytes == 0)
//         	break;
// 		tempory[bytes] = '\0';
// 		buffer = ft_strjoin(buffer, tempory);
// 	}
// 	free(tempory);
// 	return (buffer);
// }

// char	*get_next_line(int fd)   
// {
// 	static char *buffer;
// 	char	*line;
// 	char 	*newbuf;
// 	ssize_t bytes;
	
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	bytes = 0;
// 	newbuf = help_get(fd, buffer, bytes);
// 	if (!newbuf)
//     {
//         free(buffer);
//         buffer = NULL;
//         return (NULL);
//     }
//     buffer = newbuf;
// 	if (!buffer || !*buffer)
// 	{
// 		free(buffer);
// 		buffer = NULL;
// 		return (NULL);
// 	}
// 	line = extract_line (buffer);
// 	buffer = buffer_rest (buffer);
// 	if (bytes == 0)
// 		return (line);
// 	return (line);
// }

char *help_get(int fd, char *buffer)
{
    char *tempory;
    ssize_t bytes;

    tempory = malloc(BUFFER_SIZE + 1);
    if (!tempory)
        return (NULL);
    while (!ft_check_nl(buffer, '\n'))
    {
        bytes = read(fd, tempory, BUFFER_SIZE);
        if (bytes < 0)
        {
            free(tempory);
            return (NULL);
        }
        if (bytes == 0)
            break;  // Do not return! Handle after loop.
        tempory[bytes] = '\0';
        buffer = ft_strjoin(buffer, tempory);
        if (!buffer)
        {
            free(tempory);
            return (NULL);
        }
    }
    free(tempory);
    return (buffer);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;
    char *newbuf;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    newbuf = help_get(fd, buffer);
    if (!newbuf)
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    buffer = newbuf;
    if (!buffer || !*buffer)
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    line = extract_line(buffer);
    newbuf = buffer_rest(buffer);
    buffer = newbuf;
    return (line);
}