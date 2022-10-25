/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:41:12 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/25 14:15:08 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_readbuffer(int fd, char *buffer);
static char	*ft_res(char *buffer);
static char	*ft_updatebuffer(char *buffer);
static char	*ft_newbuffer(char *buffer, char *str);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;

	if (!buffer)
		buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_readbuffer(fd, buffer);
	if (!buffer)
		return (0);
	res = ft_res(buffer);
	buffer = ft_updatebuffer(buffer);
	return (res);
}

static char	*ft_readbuffer(int fd, char *buffer)
{
	ssize_t	readbuffer;
	char	*str;

	str = (char *)ft_calloc((BUFFER_SIZE + 1),  sizeof(char));
	if (!str)
		return (NULL);
	readbuffer = 1;
	while (readbuffer > 0)
	{
		readbuffer = read(fd, str, BUFFER_SIZE);
		if (readbuffer == -1)
		{
			free (str);
			free (buffer);
			return (NULL);
		}
		str[readbuffer] = '\0';
		buffer = ft_newbuffer(buffer, str);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free (str);
	return (buffer);
}

static char	*ft_res(char *buffer)
{
	int		i;
	char	*res;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	res = (char *)ft_calloc(i + 2, sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		res[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		res[i] = '\n';
	return (res);
}

static char	*ft_updatebuffer(char *buffer)
{
	int		i;
	int		j;
	char	*updatebuffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (0);
	}
	updatebuffer = (char *)ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!updatebuffer)
		return (0);
	j = 0;
	i++;
	while (buffer[i])
		updatebuffer[j++] = buffer[i++];
	free (buffer);
	return (updatebuffer);
}

static char	*ft_newbuffer(char *buffer, char *str)
{
	char	*s3;
	
	s3 = ft_strjoin(buffer, str);
	free (buffer);
	return (s3);
}
