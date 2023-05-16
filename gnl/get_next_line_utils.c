/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:55:39 by ldrieske          #+#    #+#             */
/*   Updated: 2023/05/16 15:46:53 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * strchr
 *
 * Returns a pointer to the first occurence of the character c in
 *      the s String
*/
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

/*
 * ft_strlen
 *
 * Returns the length of the char
*/
size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

/*
 * ft_strdup
 *
 * Allocates sufficient memory (malloc) for a copy of s1
 * Returns a pointer of the copy
*/
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

/*
 * ft_substr
 * 
 * char const *s : initial String
 * unsigned int start : index of start
 * size_t len : length of the new String
 * 
 * Allocates and returns a substring from the string s beginning 
 * at index start and of maximum size len
*/
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

/*
 * ft_strjoin
 *
 * Returns a new String, result of the concatenation between s1 and s2
*/
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
