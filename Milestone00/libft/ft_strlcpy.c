/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:47:13 by sde-pra           #+#    #+#             */
/*   Updated: 2024/11/24 11:04:01 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
	{
		return (src_len);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char src[] = "Ciao Vegeta";	
	char	dst[13];
	size_t	len;
	len = ft_strlcpy(dst, src, sizeof(dst));
	printf("Src len : %zu\n", len);
	printf("Dest: %s\n", dst);	
}
*/
