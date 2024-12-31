/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:46:20 by sde-pra           #+#    #+#             */
/*   Updated: 2024/11/23 18:06:37 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *) s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}
/*
 * #include <stddef.h>
#include <stdio.h>

int	main()
{
	char	str[15] = "Forse ho capito";
	printf("Before: %s\n", str);
	ft_memset(str, 'A', 5);
	printf("After: %s\n", str); }
*/
