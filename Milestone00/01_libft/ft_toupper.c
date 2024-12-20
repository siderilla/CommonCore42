/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:57:44 by sde-pra           #+#    #+#             */
/*   Updated: 2024/11/24 13:19:54 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	u;

	u = c;
	if ((c >= 97 && c <= 122))
	{
		u = u - 32;
		return (u);
	}
	else
	{
		return (c);
	}
}
/*
#include <stdio.h>

int	main()
{
	int	c = 'a';
	c = ft_toupper(c);
	printf("The uppercase is %d\n", c);
}
*/
