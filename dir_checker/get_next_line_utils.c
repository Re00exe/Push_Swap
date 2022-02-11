/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midfath <midfath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:51:15 by midfath           #+#    #+#             */
/*   Updated: 2021/11/26 12:01:07 by midfath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen (s))
	{
		p = (char *)malloc(sizeof(char) * 1);
		*p = '\0';
		return (p);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	while (s[start] && i < len)
	{
		p[i] = ((char *)s)[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	size_t	k;
	char	*nstr;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	k = 0;
	nstr = (char *)malloc(s1len + s2len + 1);
	if (!nstr)
		return (NULL);
	while (s1[k])
		nstr[i++] = s1[k++];
	k = 0;
	while (s2[k])
		nstr[i++] = s2[k++];
	nstr[i] = '\0';
	free (s1);
	return (nstr);
}
