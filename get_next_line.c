/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:19:28 by nalfonso          #+#    #+#             */
/*   Updated: 2025/06/02 22:29:19 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static char *buffer_rest(char *buffer)
// {
// 	char *rest_lines;
// 	int i;
	
// 	if (!buffer)
// 		return (NULL);
// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	if (!buffer[i])
// 		return (free(buffer), NULL);
// 	rest_lines = ft_strdup(buffer + i + 1);
// 	free(buffer);
// 	return (rest_lines);
// }

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

char	*get_next_line(int fd)   
{
	static char *buffer;
	char	*line;
	// char tempory[BUFFER_SIZE + 1];
	char *tempory;
	ssize_t bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tempory = malloc(BUFFER_SIZE + 1);
	if (!tempory)
		return (NULL);
	while (!ft_check_nl(buffer, '\n'))
	{
		bytes = read (fd, tempory, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
        	buffer = NULL;
			free(tempory);
            return (NULL);
		}
		if (bytes == 0)
        break;
		tempory[bytes] = '\0';
		buffer = ft_strjoin(buffer, tempory);
	}
	free(tempory);	
	if (!buffer || buffer[0] == '\0')
	{	
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(buffer);
	buffer = buffer_rest(buffer);
	return (line);
}

// int main(void)
// {
//     int fd;
//     char *next_line;
//     int count = 0;

// 	//fd = open("", O_RDONLY);
// 	//fd = open("fucku.txt", O_RDONLY);
//     fd = open("Poem.txt", O_RDONLY);
// 	//fd = open("newfile.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         printf("Error opening file\n");
//         return (1);
//     }
// 	//next_line = get_next_line(fd);
// 	// count++;
// 	// printf("[%d]:%s",count,next_line);
// 	while ((next_line = get_next_line(fd)) != NULL)
// 	{
// 		count++;
//     	printf("[%d]:%s", count, next_line);
// 		//printf("%s",next_line);
//     	free(next_line);
// 	}
//     close(fd);
//     return 0;
// }
