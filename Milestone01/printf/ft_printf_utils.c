#include "ft_printf.h"

void	ft_putptr(void *ptr, int upper)
{
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return ;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_puthex((unsigned long)ptr, upper);
	}
}

void	ft_puthex(unsigned int n, int upper)
{
	char	*base;
	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";

	if (n >= 16)
		ft_puthex(n / 16, upper);
	ft_putchar_fd(base[n % 16], 1);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n > 9)
	{
		ft_putunbr_fd(n / 10, fd);
	}
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		write(fd, "(null)", 6);
	else
		write(fd, s, ft_strlen(s));
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while ((s && s[len] != '\0'))
	{
		len++;
	}
	return (len);
}