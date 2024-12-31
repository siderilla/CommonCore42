/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:57:18 by sde-pra           #+#    #+#             */
/*   Updated: 2024/11/23 17:52:28 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	return (0);
}
/*
int	main()
{
	printf("%d is an alnum!\n", ft_isalnum('a'));
	printf("%d is an alnum!\n", ft_isalnum('7'));
	printf("%d is not alnum!\n", ft_isalnum('*'));
}*/
