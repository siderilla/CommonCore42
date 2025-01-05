#include "ft_printf.h"

static int	ft_handle_format(const char *format, va_list args)
{
	int		count;
	void	*ptr;

	count = 0;
	if (*format == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
	{
		ptr = va_arg(args, void *);
		count += ft_putptr(ptr, 0);
	}
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count += ft_putunbr(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (*format == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		total;
	int		count;
	va_list	args;

	total = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count = ft_handle_format(format, args);
			total += count;
		}
		else
			total += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (total);
}

// #include <stdio.h>
// int	main()
// {
// 	int		x = 42;
// 	int		*ptr = &x;
// 	char	*str = "Hello, world!";

// 	ft_printf("Test for characters:\n");
// 	ft_printf("Char: %c and %c\n", 'A', 'B');
// 	ft_printf("String: %s\n", str);
// 	ft_printf("Pointer: %p\n", ptr);
// 	ft_printf("Integer: %d, %i, %d\n", 42, -42, 0);
// 	ft_printf("Unsigned int: %u\n", 42);
// 	ft_printf("Hexadecimal (lowercase): %x\n", 255);
// 	ft_printf("Hexadecimal (uppercase): %X\n", 255);
// 	ft_printf("Percentage: %%\n");

// 	ft_printf("\nTest for null pointer:\n");
// 	ft_printf("Null pointer: %p\n", NULL);

// 	ft_printf("\nTest for null string:\n");

// 	ft_printf("\nTest for extreme values:\n");
// 	ft_printf("Max int: %d\n", 2147483647);
// 	ft_printf("Max unsigned int: %u\n", 4294967295U);
// 	ft_printf("\nTest for negative numbers with unsigned:\n");
// 	ft_printf("Negative unsigned number: %u\n", -42);

// 	ft_printf("\nTest for zero values:\n");
// 	ft_printf("Zero integer: %d\n", 0);
// 	ft_printf("Zero unsigned int: %u\n", 0);
// 	ft_printf("Zero hex: %x\n", 0);
// 	ft_printf("Empty string: %s\n", "");
// 	ft_printf("\nTest for percentage:\n");
// 	ft_printf("Percentage: %%\n");

// 	ft_printf("\nCombined test:\n");
// 	ft_printf("Characters and strings: %c and %s\n", 'X', "Test");
// 	ft_printf("Hexadecimal and pointer: %x and %p\n", 1234, ptr);

// 	printf("\n\nVERO PRINTF:\n");
// 	printf("Test for characters:\n");
// 	printf("Char: %c and %c\n", 'A', 'B');
// 	printf("String: %s\n", str);
// 	printf("Pointer: %p\n", ptr);
// 	printf("Integer: %d, %i, %d\n", 42, -42, 0);
// 	printf("Unsigned int: %u\n", 42);
// 	printf("Hexadecimal (lowercase): %x\n", 255);
// 	printf("Hexadecimal (uppercase): %X\n", 255);
// 	printf("Percentage: %%\n");

// 	printf("\nTest for null pointer:\n");
// 	printf("Null pointer: %p\n", NULL);

// 	printf("\nTest for extreme values:\n");
// 	printf("Max int: %d\n", 2147483647);
// 	printf("Max unsigned int: %u\n", 4294967295U);

// 	printf("\nTest for negative numbers with unsigned:\n");
// 	printf("Negative unsigned number: %u\n", -42);

// 	printf("\nTest for zero values:\n");
// 	printf("Zero integer: %d\n", 0);
// 	printf("Zero unsigned int: %u\n", 0);
// 	printf("Zero hex: %x\n", 0);
// 	printf("Empty string: %s\n", "");

// 	printf("\nTest for percentage:\n");
// 	printf("Percentage: %%\n");

// 	printf("\nCombined test:\n");
// 	printf("Characters and strings: %c and %s\n", 'X', "Test");
// 	printf("Hexadecimal and pointer: %x and %p\n", 1234, ptr);
// }