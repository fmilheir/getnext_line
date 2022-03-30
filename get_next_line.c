/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:00:35 by marvin            #+#    #+#             */
/*   Updated: 2022/03/30 13:15:30 by fmilheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*next_line(char *buf)
{
	int	a;
	int	b;
	char	*line;

	a = 0;
	while(buf[a] && buf[a] != '\n')
		a++;
	if (!buf[a])
	{
		free (buf);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buf) - a + 1), sizeof(char));
	a++;
	b = 0;
	while (buf[a])
		line[b++] = buf[a++];
	free (buf);
	return (line);
}

char	*take_line(char *buff)
{
	char	*line;
	int		a;

	a = 0;
	if (!buff[a])
		return (NULL);
	
	while (buff[a] != '\n' && buff[a])
		a++;

	line = ft_calloc(a + 2, sizeof(char));
	a = 0;
	
	while (buff[a] && buff[a] != '\n')
	{
		line[a] = buff[a];
		a++;
	}
	if (buff[a] && buff[a] == '\n')
		line[a++] = '\n';
	return (line);
}

char	*free_my_buff(char *buf, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(buf, buffer);
	free(buf);
	return (temp);
}


char	*read_my_file(int fd, char *buf)
{
	char	*buffer;
	int		n;

	if (!buf)
		buf = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[n] = 0;
		buf = free_my_buff(buf, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;

	}
	free(buffer);
	return(buf);
}
char	*get_next_line(int fd)
{
	static char *buf;
	char 		*line;

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
			return(NULL);
	buf = read_my_file(fd, buf);
	if (!buf)
		return (NULL);
	
	line = take_line(buf);
	buf = next_line(buf);
	return (line);
}	
