/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:20:30 by sde-pra           #+#    #+#             */
/*   Updated: 2024/11/24 13:27:48 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	u;

	u = c;
	if ((c >= 65 && c <= 90))
	{
		u = c + 32;
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
	int	c = 'A';
	c = ft_tolower(c);
	printf("The lowercase is %d\n", c);
}
*/
