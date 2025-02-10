/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:11:44 by sde-pra           #+#    #+#             */
/*   Updated: 2024/11/23 17:20:48 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
	{
		return (1);
	}
	return (0);
}
/*
 * #include <stdio.h>
int	main()
{
	printf("%d is a digit!\n", ft_isdigit('1'));
	printf("%d is not digit\n", ft_isdigit('k'));
	printf("%d is a digit!\n", isdigit('1'));
	printf("%d is not digit\n", isdigit('k'));
}
*/
