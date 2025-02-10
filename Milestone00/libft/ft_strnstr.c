/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:19:49 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/02 15:39:43 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_little;

	l_little = ft_strlen(little);
	if (l_little == 0)
	{
		return ((char *)big);
	}
	while (*big != '\0' && len > 0)
	{
		if (ft_strncmp(big, little, l_little) == 0 && len >= l_little)
		{
			return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main()
{
	char little[] = "foa";
	char big[] = "Ciaoaoa foa";
	char *result = ft_strnstr(big, little, 8);
	if (result)
		printf("Occurance is: %s\n", result);
	else
		printf("Nada\n");
	return (0);
}*/
