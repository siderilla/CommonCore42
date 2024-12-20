/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:28:18 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/18 14:58:42 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while ((unsigned char)*s != (unsigned char)c && (unsigned char)*s != '\0')
		s++;
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;	
	char	*join;
	char	*start;

	if (s1)
		s1_len = ft_strlen(s1);
	else
		s1_len = 0;
	if (s2)
		s2_len = ft_strlen(s2);
	else
		s2_len = 0;
	join = malloc(s1_len + s2_len +1);
	if (!join)
		return (NULL);
	start = join;
	while (s1 && *s1)
		*join++ = *s1++;
	while (s2 && *s2)
		*join++ = *s2++;
	*join = '\0';
	return (start);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while ((s[len] != '\0'))
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*ptr;

	dup = malloc((ft_strlen(s) + 1) * sizeof(char));
	ptr = dup;
	if (dup == NULL)
	{
		return (NULL);
	}
	while (*s != '\0')
	{
		*ptr = *s;
		ptr++;
		s++;
	}
	*ptr = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*start_sub;
	size_t	strlen;

	strlen = ft_strlen(s);
	if (!s || start >= strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		len = strlen - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	start_sub = sub;
	while (len--)
		*sub++ = s[start++];
	*sub = '\0';
	return (start_sub);
}
