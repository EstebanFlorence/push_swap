/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:22:40 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/29 19:19:26 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_freegnl(char **stat)
{
	free (*stat);
	*stat = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*stat;
	char			*buffer;
	char			*line;

	if (fd == -42)
		return (ft_freegnl(&stat));
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stat)
		stat = ft_calloc(sizeof(char), 1);
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = zeline(fd, &stat, buffer);
	if (line == NULL)
	{
		free (stat);
		stat = NULL;
	}
	free (buffer);
	return (line);
}

char	*zeline(int fd, char **stat, char *buffer)
{
	int		bytesread;
	char	*tmpstat;
	char	*line;

	bytesread = 1;
	while (bytesread)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
			return (NULL);
		tmpstat = *stat;
		*stat = ft_strjoin(tmpstat, buffer);
		free (tmpstat);
		if (endornewline(*stat, bytesread) > 0)
		{
			line = ft_substr(*stat, 0, endornewline(*stat, bytesread));
			tmpstat = *stat;
			*stat = ft_substr(tmpstat, (int)endornewline(tmpstat, bytesread),
					(ft_strlen(tmpstat) - endornewline(tmpstat, bytesread)));
			free (tmpstat);
			return (line);
		}
	}
	return (0);
}

size_t	endornewline(char *buffer, int bytesread)
{
	int		i;

	if (buffer == NULL)
		return (0);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	if (bytesread == 0 && buffer[0] != '\0')
		return (ft_strlen(buffer));
	return (0);
}
