/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:49:53 by sde-pra           #+#    #+#             */
/*   Updated: 2024/11/24 12:56:03 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	i;

	s = ft_strlen(src);
	d = ft_strlen(dst);
	if (size <= d)
	{
		return (s + size);
	}
	i = 0;
	while (src[i] != '\0' && (d + i) < (size - 1))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + s);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	char dst[14] = "Bulbasaur";
	const char src[] = " is my fav";
	printf("My src string: %s\n and my dst: %s\n", src, dst);
	ft_strlcat(dst, src, sizeof(dst));
	printf("My concat strings: %s\n", dst);
}*/
