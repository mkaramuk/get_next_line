/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:32:15 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/01/20 19:37:49 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && *s++)
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	size_t	size;
	size_t	i;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + 1;
	new_str = (char *)malloc(sizeof(char) * size);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < size)
		new_str[i++] = *s1++;
	new_str[i] = 0;
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	s1len;
	size_t	s2len;
	size_t	i;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	ret = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ret)
		return (NULL);
	while (s1 && *s1)
		ret[i++] = *s1++;
	while (s2 && *s2)
		ret[i++] = *s2++;
	ret[i] = 0;
	return (ret);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*start_ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	start_ptr = (char *)s + start;
	i = 0;
	while (i < len && *start_ptr)
	{
		ret[i] = *start_ptr;
		start_ptr++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	while (s && *s)
		if (*s++ == (char)c)
			return ((char *)s);
	return (NULL);
}
