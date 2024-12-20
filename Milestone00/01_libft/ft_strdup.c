/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:21:59 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/01 17:26:01 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include <stdio.h>
int main()
{
	const char	*str = "ciaone";
	char	*dupl = ft_strdup(str);
	printf("Original: %s\nDuplicate: %s\n", str, dupl);
	free(dupl);
	return (0);
}*/
