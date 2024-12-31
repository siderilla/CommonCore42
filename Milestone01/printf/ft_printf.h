#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h> // write
#include <stdio.h> // eventuale uso printf vero per comparazione
#include <stdarg.h> // macro e typedef va_ ...

int	ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
void	ft_putunbr_fd(unsigned int n, int fd);
void	ft_puthex(unsigned long n, int upper);
void	ft_putptr(void *ptr, int upper);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif