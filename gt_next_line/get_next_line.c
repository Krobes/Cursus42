/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbonilla <rbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:41:12 by rbonilla          #+#    #+#             */
/*   Updated: 2022/10/20 14:15:19 by rbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;
	
	if (!buffer || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_readbuffer(fd, buffer, BUFFER_SIZE);
	res = ft_res(buffer);
	buffer = updatebuffer(buffer);	
}

char	*ft_readbuffer(int fd, char *buffer, int BUFFER_SIZE)
{
	int		readbuffer;
	char	*str;

	readbuffer = 1;
	str = (char *)malloc(BUFFER_SIZE + 1 * (char));
	if (!str)
		return (NULL);
	while (readbuffer > 0)
	{
		readbuffer = read(fd, buffer, BUFFER_SIZE);
		if (readbuffer == -1)
		{
			free (str);
			return (NULL);
		}
		str[readbuffer] = '\0';
		buffer = ft_strjoin(buffer, str);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free (str);
	return (buffer);
}
