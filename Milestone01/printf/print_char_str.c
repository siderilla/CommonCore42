#include "ft_printf.h"

ssize_t	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	else
		return (write(1, s, ft_strlen(s)));
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

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
