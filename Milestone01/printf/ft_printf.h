/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:47:59 by sde-pra           #+#    #+#             */
/*   Updated: 2025/01/08 15:48:04 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
ssize_t	ft_putunbr(unsigned int n);
ssize_t	ft_puthex(unsigned long n, int upper);
ssize_t	ft_putptr(void *ptr, int upper);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putstr(char *s);
ssize_t	ft_putchar(char c);

#endif
