#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_putchar_fd((char)va_arg(args, int), 1);
			else if (*format == 's')
				ft_putstr_fd(va_arg(args, char*), 1);
			else if (*format == 'p')
				ft_putptr(va_arg(args, void *), 0);
			else if (*format == 'd' || *format == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (*format == 'u')
				ft_putunbr_fd(va_arg(args, unsigned int), 1);
			else if (*format == 'x')
				ft_puthex(va_arg(args, unsigned long), 0);
			else if (*format == 'X')
				ft_puthex(va_arg(args, unsigned long), 1);
			else if (*format == '%')
				ft_putchar_fd('%', 1);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return(0);
}
int	main()
{
	int	x = 42;
	int	*ptr = &x;
	ft_printf("These are chars: %c and %c\n", '0', 65);
	ft_printf("This is a string: %s and %s and %s\n", "Bla bla bla!", "", NULL);
	ft_printf("Number %d and %d and %d\n", 42, -42, 0);
	ft_printf("Float %f and %f and %f\n", 3.14, -3.14, 0.0);
	ft_printf("Hexadecimal %x and %X and %x\n", 255, 255, -255);
	ft_printf("Pointer %p and %p\n", ptr, NULL);
	ft_printf("u int %u and %u\n", 42, -42);
	ft_printf("long int %ld and long hex %lx\n", 123456789L, 123456789L);
	ft_printf("percent %%\n");
	ft_printf("not supported: %z\n\n");

	printf("VERO PRINTF:\n");
	printf("These are chars: %c and %c\n", '0', 65);
	printf("This is a string: %s and %s and %s\n", "Bla bla bla!", "", NULL);
	printf("Number %d and %d and %d\n", 42, -42, 0);
	printf("Float %f and %f and %f\n", 3.14, -3.14, 0.0);
	printf("Hexadecimal %x and %X and %x\n", 255, 255, -255);
	printf("Pointer %p and %p\n", ptr, NULL);
	printf("u int %u and %u\n", 42, -42);
	printf("long int %ld and long hex %lx\n", 123456789L, 123456789L);
	printf("percent %%\n");
	printf("not supported: %z\n");
}