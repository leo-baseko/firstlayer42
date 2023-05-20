/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:55:39 by ldrieske          #+#    #+#             */
/*   Updated: 2023/05/20 14:19:25 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return ((char *) 0);
	}
	return ((char *) &s[i]);
}

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		j;
	int		len;

	j = 0;
	len = ft_strlen((char *)s1);
	a = malloc(sizeof(char) * (len + 1));
	if (!a)
		return (0);
	while (s1[j])
	{
		a[j] = s1[j];
		j++;
	}
	a[j] = '\0';
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0 || ft_strlen(s) == 0)
		return (res = 0);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s) - start;
	while (s[size] && size < len && start < ft_strlen(s))
		size++;
	res = malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	while (size != 0 && s[start])
	{
		res[i] = (char)s[start++];
		size--;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
