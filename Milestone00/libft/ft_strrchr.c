/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:51:24 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/01 19:24:20 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*origin;

	origin = s;
	while ((unsigned char)*s != '\0')
	{
		s++;
	}
	while ((unsigned char)*s != (unsigned char)c && s != origin)
	{
		s--;
	}
	if ((unsigned char)*s == (unsigned char)c)
	{
		return ((char *)s);
	}
	else
	{
		return (NULL);
	}
}
/*
#include <stdio.h>
int	main()
{
	char	str[] = "Coooaoaoaoadiidao";
	int	ch = 'e';
	char	*result = ft_strrchr(str,ch);

	if (result != NULL)
	{
		printf("Found: %c\n", *result);
	}
	else
	{
		printf("Not found.\n");
	}
}*/
