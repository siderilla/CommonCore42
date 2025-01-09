/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:31:18 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/01 16:37:45 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	num;

	num = n;
	len = ft_nlen(num);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	while (len-- > (n < 0))
	{
		s[len] = (num % 10) + '0';
		num /= 10;
	}
	return (s);
}
/*
#include <stdio.h>
int main()
{
    int num = -1234;
    char *str = ft_itoa(num);
    if (str)
    {
        printf("Your int is %d converted to character %s\n", num, str);
        free(str);
    }
    return (0);
}
*/
/*
///////// FORMA SCOMPATTATA DI while (len-- > (n < 0)) /////////////

    if (n > 0)
    {
        while (len > 1)
            len--;
            s[len] = (num % 10) + '0';
            num /= 10;
    }
    else
    {
        while (len > 0)
            len--;
            s[len] = (num % 10) + '0';
            num /= 10;
    }

///////// BOOOOOOOOOOOOOOOOOOOH ////////////////
*/
