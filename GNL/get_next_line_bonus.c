/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:35:08 by dberreby          #+#    #+#             */
/*   Updated: 2022/12/13 15:23:23 by dberreby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *full_line)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!full_line)
		return (NULL);
	while (full_line[i] && full_line[i] != '\n')
		i++;
	if (full_line[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = malloc((sizeof(char) * i) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (full_line[i] && full_line[i] != '\n')
		line[j++] = full_line[i++];
	if (full_line[i] == '\n')
		line[j++] = full_line[i++];
	line[j] = '\0';
	return (line);
}

char	*reserve(char *full_line)
{
	char	*reservoir;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_strchr(full_line, '\n'))
	{
		free(full_line);
		return (NULL);
	}
	while (full_line[i] && full_line[i] != '\n')
		i++;
	reservoir = malloc(sizeof(char) * (ft_strlen(full_line) - i + 1));
	if (!reservoir)
		return (NULL);
	i++;
	while (full_line[i] != '\0')
		reservoir[j++] = full_line[i++];
	reservoir[j] = full_line[i];
	free(full_line);
	return (reservoir);
}

char	*get_full_line(int fd, char *full_line)
{
	int		readnb;
	char	*buffer;

	readnb = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (readnb > 0 && !(ft_strchr(full_line, '\n')))
	{
		readnb = read(fd, buffer, BUFFER_SIZE);
		if (readnb == -1)
		{
			free(buffer);
			free(full_line);
			return (NULL);
		}
		buffer[readnb] = '\0';
		full_line = ft_strjoin(full_line, buffer);
	}
	free(buffer);
	return (full_line);
}

char	*get_next_line(int fd)
{
	static char	*full_line[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(full_line[fd]);
		return (NULL);
	}
	if (!full_line[fd])
	{
		full_line[fd] = malloc(1);
		full_line[fd][0] = '\0';
	}
	full_line[fd] = get_full_line(fd, full_line[fd]);
	if (full_line[fd] == NULL)
		return (NULL);
	line = get_line(full_line[fd]);
	full_line[fd] = reserve(full_line[fd]);
	return (line);
}
