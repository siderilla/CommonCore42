/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:37:56 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/01 17:09:44 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_array(char **array, size_t i)
{
	while (i > 0)
		free(array[--i]);
	free(array);
}

static char	*ft_copy_word(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	result = malloc ((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			result[i] = ft_copy_word(s, c);
			if (!result[i])
				return (ft_free_array(result, i), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
    	char	**result = ft_split("  hello world  42 is   awesome  ", ' ');

	if (!result)
	{
		printf("Memory allocation failed!\n");
		return (1);
	}
	for (size_t i = 0; result[i]; i++)
	{
		printf("Word %zu: %s\n", i, result[i]);
		free(result[i]);
	}
	free(result);
	return (0);
}*/
