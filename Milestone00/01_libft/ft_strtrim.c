/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:10:14 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/01 17:16:59 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = s1 + ft_strlen(s1) - 1;
	while (end > s1 && ft_strchr(set, *end))
		end--;
	return (ft_substr(s1, 0, end - s1 + 1));
}
/*
#include <stdio.h>
int main()
{
	char	s1[] = "     ciao ";
	char	set[] = " ";
	char	*result = ft_strtrim(s1, set);
	printf("Polished string: %s\n", result);
	free(result);
}*/
