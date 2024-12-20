/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:56:38 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/01 16:29:35 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_elem, size_t size_elem)
{
	size_t	total;
	void	*ptr;

	total = n_elem * size_elem;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}
/*
#include <stdio.h>
int	main()
{
	int *array = (int *) ft_calloc(5, sizeof(int));
	if (array == NULL)
	{
		printf("Error\n");
		return (1);
	}
	int	i = 0;
	while (i < 5)
	{
		printf("array[%d] = %d\n", i, array[i]);
		i++;
	}
	free (array);
	return (0);
}*/
