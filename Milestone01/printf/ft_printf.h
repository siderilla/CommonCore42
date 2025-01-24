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