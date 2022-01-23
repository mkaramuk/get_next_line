/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devman <devman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:49:27 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/01/23 15:09:54 by devman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_move_str(char **str, size_t n)
{
	char	*old;
	size_t	len;

	old = *str;
	len = ft_strlen(*str) - n;
	if (len == 0)
		*str = NULL;
	else
		*str = ft_substr(old, n, len);
	free(old);
	return (*str);
}

void	ft_strappend(char **data, char *buffer)
{
	char	*old;

	old = *data;
	*data = ft_strjoin(old, buffer);
	if (old)
		free(old);
}

void	get_data(int fd, char **backup)
{
	char	buffer[BUFFER_SIZE + 1];
	int		readed;

	readed = 1;
	if (!buffer)
		return ;
	while (!ft_strchr(*backup, '\n') && readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
			break ;
		buffer[readed] = 0;
		ft_strappend(backup, buffer);
	}
}

char	*get_line(char **backup)
{
	char	*line;
	size_t	nl_len;

	if (ft_strchr(*backup, '\n'))
	{
		nl_len = ft_strchr(*backup, '\n') - (*backup);
		line = ft_substr(*backup, 0, nl_len);
		ft_move_str(backup, nl_len);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	char		*ret;

	get_data(fd, &buffer);
	line = get_line(&buffer);
	if (!line)
	{
		ret = ft_strdup(buffer);
		free(buffer);
		buffer = NULL;
		return (ret);
	}
	return (line);
}
