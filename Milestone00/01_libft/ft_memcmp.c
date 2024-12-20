/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:04:06 by sde-pra           #+#    #+#             */
/*   Updated: 2024/11/25 11:18:50 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ar1;
	unsigned char	*ar2;

	ar1 = (unsigned char *)s1;
	ar2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*ar1 != *ar2)
		{
			return (*ar1 - *ar2);
		}
		ar1++;
		ar2++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	char	s1[] = "Kekkers";
	char	s2[] = "Kekke";
	int	c = ft_memcmp(s1, s2, 7);
	printf("Comparing mem: %d\n", c);
}
*/
