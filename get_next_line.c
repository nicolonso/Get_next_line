/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalfonso <nalfonso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:19:28 by nalfonso          #+#    #+#             */
/*   Updated: 2025/05/28 22:31:43 by nalfonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"

static char *extract_line(char *buffer)
{
	int i;
	int j;
	char *line;
	
	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\0')
		i++;
	line = malloc(i + (buffer[i] == '\n' ? 2 : 1));
	if (!line)
		return (NULL);
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char *buffer_rest(char *buffer)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
	{
		buffer[j++] == buffer[i++];
		if (buffer[j] == '\n')
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)   
{
	static char *buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_check_nl(buffer, '\n'))
	{
		if (*buffer == '\0')
			bytes = read(fd, buffer, BUFFER_SIZE);
		printf("Tempory : %s\n",buffer);
		if (bytes == -1)
			return (free(line), NULL);
		buffer[bytes] = '\0';
	}
	line = extract_line(buffer);
	buffer_rest(buffer);
	return (line);
}

int main(void)
{
    int fd;
    char *next_line;
    int count = 0;

    fd = open("newfile.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return (1);
    }
    // while ((next_line = get_next_line(fd)) != NULL)
    // {
    //     count++;
    //     printf("[%d]:%s", count, next_line); 
	// 	free(next_line);
    // }
	while ((next_line = get_next_line(fd)) != NULL)
	{
		count++;
    	printf("[%d]:%s", count, next_line);
    	free(next_line);
	}
    close(fd);
    return 0;
}