/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:13:26 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/01 19:14:35 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	d = (char *) dest;
	s = (const char *) src;
	if (!dest && !src)
		return (NULL);
	if (d < s)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		d = d + (n - 1);
		s = s + (n - 1);
		while (n--)
		{
			*d-- = *s--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
int	main()
{
	char	src[0] = "Ciao Mariooiwfq";
	char	dest[0] = "Palumbobobiuytqfqfqfqqfqffq";
	printf("Before: %s\n", src); 
	ft_memmove(dest, src + 4, 10);
	printf("After: %s\n", dest);
}*/
