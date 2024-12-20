/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:17:30 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/01 17:21:24 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_allocate(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = malloc(s1_len + s2_len + 1);
	if (join == NULL)
		return (NULL);
	return (join);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*start_join;

	join = ft_allocate(s1, s2);
	if (join == NULL)
		return (NULL);
	start_join = join;
	while (*s1 != '\0')
	{
		*join = *s1;
		s1++;
		join++;
	}
	while (*s2 != '\0')
	{
		*join = *s2;
		s2++;
		join++;
	}
	*join = '\0';
	return (start_join);
}
