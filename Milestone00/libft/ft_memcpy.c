/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:41:51 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/01 18:48:56 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*p;

	p = (char *) dest;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*p = *(char *) src;
		p++;
		src++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
int	main()
{
	char	src[]= "";
	char	dest[]= "";
	printf("Before: %s\n", src);
	ft_memcpy(dest, src, 3);
	printf("After: %s\n", dest);
}*/
