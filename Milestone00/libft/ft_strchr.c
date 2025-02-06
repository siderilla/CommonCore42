/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:28:34 by sde-pra           #+#    #+#             */
/*   Updated: 2025/02/06 22:13:31 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((unsigned char)*s != (unsigned char)c && (unsigned char)*s != '\0')
	{
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
	{
		return ((char *)s);
	}>
	else
	{
		return (NULL);
	}
}
/*
#include <stdio.h>
int	main()
{
	char	str[] = "Ciapapapapapaoooo";
	int	ch = 'o';
	char	*result = ft_strchr(str, ch);
	printf("Found: %c\n", *result);
}*/
