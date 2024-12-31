/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:31:32 by sde-pra           #+#    #+#             */
/*   Updated: 2024/11/25 10:02:53 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *) s;
	while (n > 0)
	{
		if (*p == (unsigned char)c)
		{
			return (p);
		}
		p++;
		n--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main()
{
	char	s[] = "Top kek\n";
	char	*c = ft_memchr(s, 'k', 5);
	printf("I was looking for... %c\n", *c);
}
*/
