/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndabbous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:51:45 by ndabbous          #+#    #+#             */
/*   Updated: 2024/12/16 14:38:03 by ndabbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (storage)
		{
			free(storage);
			storage = NULL;
		}
		return (NULL);
	}
	storage = read_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = return_line(storage);
	storage = new_storage(storage);
	return (line);
}

char	*read_storage(int fd, char *storage)
{
	int		bytes_returned;
	char	*buffer;

	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_returned = 1;
	while (ft_strchr(buffer, '\n') == 0 && bytes_returned != 0)
	{
		bytes_returned = read(fd, buffer, BUFFER_SIZE);
		if (bytes_returned < 0)
		{
			if (buffer)
				free(buffer);
			if (storage)
				free(storage);
			return (NULL);
		}
		buffer[bytes_returned] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*return_line(char	*buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n' && buffer[i])
		i++;
	line = ft_calloc(sizeof(char), i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = buffer[i];
	line[i + 1] = '\0';
	return (line);
}

char	*new_storage(char *storage)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	j = 0;
	while (storage[i] != '\n' && storage[i])
		i++;
	if (storage[i] == '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (storage = NULL, NULL);
	}
	copy = ft_calloc(sizeof(char), ft_strlen(storage) - i + 1);
	if (!copy)
		return (NULL);
	while (storage && storage[i])
		copy[j++] = storage[i++];
	copy[j] = '\0';
	free(storage);
	return (copy);
}

/* 
#include <stdio.h>
#include <fcntl.h>

int  main(int ac, char **av)
{
	int     fd;
//	int		i = 0;
	char    *line;

	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (0);
	int a = 2;
	while (a)
	{
		line = get_next_line(fd);
		write(1, line, ft_strlen(line));
//		printf("%s", line); 
		free(line);
		a--;
	}
	close(fd);
	line = get_next_line(fd);
	write(1, line, ft_strlen(line));
	fd = open(av[1], O_RDONLY);
	a = 4;
	while (a)
	{
		line = get_next_line(fd);
		write(1, line, ft_strlen(line));
//		printf("%s", line); 
		free(line);
		a--;
	}
	close(fd);
	return (0);
}
// create a new function to free_tab
//warning : when '\n' i stop when i find empty lines
 */