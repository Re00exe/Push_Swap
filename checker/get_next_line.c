/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:07:56 by midfath           #+#    #+#             */
/*   Updated: 2021/11/26 11:08:49 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	f_leak(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

ssize_t	ft_find_newline(char *str)
{
	ssize_t	cnt;

	cnt = 0;
	while (str != NULL && str[cnt] != '\0')
	{
		if (str[cnt] == '\n')
			return (cnt);
		cnt++;
	}
	return (-1);
}

void	ft_backup(char **loader)
{
	char	*rest;
	ssize_t	l;

	l = ft_find_newline(*loader);
	if (l == -1)
		rest = ft_strdup("");
	else
		rest = ft_strdup(*loader + l + 1);
	f_leak(loader);
	*loader = rest;
}

char	*get_line(int fd, char *buff, char **loader)
{
	ssize_t	ind;

	ind = 1;
	if (!(*loader))
		*loader = ft_strdup("");
	while (ind != 0 && ft_find_newline(*loader) == -1)
	{
		ind = read(fd, buff, BUFFER_SIZE);
		buff[ind] = '\0';
		*loader = ft_strjoin(*loader, buff);
	}
	f_leak(&buff);
	buff = NULL;
	if (ind == 0)
		return (ft_strdup(*loader));
	else
		return (ft_substr(*loader, 0, ft_find_newline(*loader) + 1));
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*loader;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) == -1)
	{
		f_leak(&buffer);
		return (NULL);
	}
	line = get_line(fd, buffer, &loader);
	ft_backup(&loader);
	if (!(*line))
	{
		f_leak(&line);
		if (loader)
			f_leak(&loader);
		return (NULL);
	}
	return (line);
}
