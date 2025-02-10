/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:20:56 by sde-pra           #+#    #+#             */
/*   Updated: 2024/11/23 17:19:43 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d is an alpha!\n", ft_isalpha('a'));
	printf("%d is an alpha!\n", isalpha('a'));
	printf("%d is not alpha!\n", ft_isalpha('7'));
        printf("%d is not alpha!\n", isalpha('5'));
}*/