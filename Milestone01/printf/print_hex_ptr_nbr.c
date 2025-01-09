#include "ft_printf.h"

ssize_t	ft_putptr(void *ptr, int upper)
{
	ssize_t			count;
	unsigned long	ptr_value;

	count = 0;
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	else
	{
		ptr_value = (unsigned long)ptr;
		count = write(1, "0x", 2);
		count += ft_puthex(ptr_value, upper);
	}
	return (count);
}

ssize_t	ft_puthex(unsigned long n, int upper)
{
	char	*base;
	ssize_t	len;

	len = 0;
	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n >= 16)
		len += ft_puthex(n / 16, upper);
	len += ft_putchar(base[n % 16]);
	return (len);
}

ssize_t	ft_putunbr(unsigned int n)
{
	char	c;
	ssize_t	count;

	count = 0;
	if (n > 9)
		count += ft_putunbr(n / 10);
	c = n % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}

ssize_t	ft_putnbr(int n)
{
	char	c;
	ssize_t	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	c = n % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}
