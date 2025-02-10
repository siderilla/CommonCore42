/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:43:22 by sde-pra           #+#    #+#             */
/*   Updated: 2024/11/23 18:08:47 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while ((s[len] != '\0'))
	{
		len++;
	}
	return (len);
}
/*#include <stddef.h> 
#include <stdio.h> 
int	main()
{
	printf("String lenght is: %zu\n", ft_strlen("Ciao"));
}*/
