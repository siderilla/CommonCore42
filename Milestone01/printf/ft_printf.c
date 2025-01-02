#include "ft_printf.h"

// static void	ft_handle_format(const char *format, va_list args)
// {

// }

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	count;
	void	*ptr;

	count = 0;
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
			{
				ptr = va_arg(args, void *);
				ft_putptr(ptr, 0);
			}
			else if (*format == 'd' || *format == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (*format == 'u')
				ft_putunbr_fd(va_arg(args, unsigned int), 1);
			else if (*format == 'x' || *format == 'X')
				ft_puthex(va_arg(args, unsigned int), (*format == 'X') ? 1 : 0);
			else if (*format == '%')
				ft_putchar_fd('%', 1);
			count++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return(count);
}

#include "ft_printf.h"

int	main(void)
{
	// Test %c - Stampa un singolo carattere
	ft_printf("Test: %c\n", 'A');
	ft_printf("Expected output: A\n\n");

	// Test %s - Stampa una stringa
	ft_printf("Test: %s\n", "Hello, world!");
	ft_printf("Expected output: Hello, world!\n\n");

	// Test %p - Stampa un puntatore (in esadecimale)
	int x = 42;
	ft_printf("Test: %p\n", &x);
	ft_printf("Expected output: Address of x (in hexadecimal)\n\n");

	// Test %d - Stampa un numero intero
	ft_printf("Test: %d\n", -123);
	ft_printf("Expected output: -123\n\n");

	// Test %i - Stampa un intero (comportamento simile a %d)
	ft_printf("Test: %i\n", 456);
	ft_printf("Expected output: 456\n\n");

	// Test %u - Stampa un numero intero senza segno
	ft_printf("Test: %u\n", 12345);
	ft_printf("Expected output: 12345\n\n");

	// Test %x - Stampa un numero in esadecimale minuscolo
	ft_printf("Test: %x\n", 255);
	ft_printf("Expected output: ff\n\n");

	// Test %X - Stampa un numero in esadecimale maiuscolo
	ft_printf("Test: %X\n", 255);
	ft_printf("Expected output: FF\n\n");

	// Test %% - Stampa il simbolo %
	ft_printf("Test: %%\n");
	ft_printf("Expected output: %%\n\n");

	// Test %p con NULL - Puntatore nullo
	ft_printf("Test: %p (NULL)\n");
	printf("Expected output: %p (nil)\n\n");

	// Test numeri estremi per %d e %u
	ft_printf("Test: %d (INT_MIN)\n");
	ft_printf("Expected output: -2147483648\n\n");
	ft_printf("Test: %d (INT_MAX)\n");
	ft_printf("Expected output: 2147483647\n\n");

	// Test numeri molto grandi per %x e %X
	ft_printf("Test: %x (ULONG_MAX)\n");
	ft_printf("Expected output: ffffffffffffffff\n\n");
	ft_printf("Test: %X (ULONG_MAX)\n");
	ft_printf("Expected output: FFFFFFFFFFFFFFFF\n\n");

	// Test stringa NULL con %s
	ft_printf("Test: %s (NULL string)\n");
	ft_printf("Expected output: (null)\n\n");

	// Test con variabili un po' più complesse
	ft_printf("Test: %d + %x\n");
	ft_printf("Expected output: 1234 + 4d2\n");
	ft_printf("%d + %x\n", 1234, 1234); // Stampa il numero decimale e il suo equivalente esadecimale

	return (0);
}





// int	main()
// {
// 	ft_printf(" %x ", 0);
// 	ft_printf("\n");
// 	ft_printf(" %x ", -1);
// 	ft_printf("\n");
// 	ft_printf(" %x ", 1);
// 	ft_printf("\n");
// 	ft_printf(" %x ", 9);
// 	ft_printf("\n");
// 	ft_printf(" %x ", 10);
// 	ft_printf("\n");
// 	ft_printf(" %x ", 11);
// 	ft_printf("\n");
// 	ft_printf(" %x ", 15);
// 	ft_printf("\n");
// 	ft_printf(" %x ", 16);
// 	ft_printf("\n");
// 	ft_printf(" %x ", 17);
// 	ft_printf("\n");
// 	ft_printf(" %x ", 99);
// 	ft_printf("\n");
// 	ft_printf(" %x ", 100);
// 	ft_printf("\n");
// 	ft_printf(" %x ", 101);
// 	ft_printf("\n");
// 	ft_printf(" %x ", -9);
// 	ft_printf("\n");
// 	ft_printf(" %x ", -10);
// 	ft_printf("\n");
// 	ft_printf(" %x ", -11);
// 	ft_printf("\n");
// 	ft_printf(" %x ", -14);
// 	ft_printf("\n");
// 	ft_printf(" %x ", -15);
// 	ft_printf("\n");
// 	ft_printf(" %x ", -16);
// 	ft_printf("\n");
// 	ft_printf(" %x ", -99);
// 	ft_printf("\n");
// 	ft_printf(" %x ", -100);
// 	ft_printf("\n");
// 	ft_printf(" %x ", -101);
// 	ft_printf("\n");
// 	ft_printf(" %x ", INT_MAX);
// 	ft_printf("\n");
// 	ft_printf(" %x ", INT_MIN);
// 	ft_printf("\n");
// 	ft_printf(" %x ", LONG_MAX);
// 	ft_printf("\n");
// 	ft_printf(" %x ", LONG_MIN);
// 	ft_printf("\n");
// 	ft_printf(" %x ", UINT_MAX);
// 	ft_printf("\n");
// 	ft_printf(" %x ", ULONG_MAX);
// 	ft_printf("\n");
// 	ft_printf(" %x ", 9223372036854775807LL);
// 	ft_printf("\n");
// 	ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	ft_printf("\n");
// 	ft_printf(" %x ", 42);
// 	ft_printf("\n");
// 	ft_printf(" %x ", -42);
// 	ft_printf("\n\n\n");
// 	printf(" %x ", 0);
// 	printf("\n");
// 	printf(" %x ", -1);
// 	printf("\n");
// 	printf(" %x ", 1);
// 	printf("\n");
// 	printf(" %x ", 9);
// 	printf("\n");
// 	printf(" %x ", 10);
// 	printf("\n");
// 	printf(" %x ", 11);
// 	printf("\n");
// 	printf(" %x ", 15);
// 	printf("\n");
// 	printf(" %x ", 16);
// 	printf("\n");
// 	printf(" %x ", 17);
// 	printf("\n");
// 	printf(" %x ", 99);
// 	printf("\n");
// 	printf(" %x ", 100);
// 	printf("\n");
// 	printf(" %x ", 101);
// 	printf("\n");
// 	printf(" %x ", -9);
// 	printf("\n");
// 	printf(" %x ", -10);
// 	printf("\n");
// 	printf(" %x ", -11);
// 	printf("\n");
// 	printf(" %x ", -14);
// 	printf("\n");
// 	printf(" %x ", -15);
// 	printf("\n");
// 	printf(" %x ", -16);
// 	printf("\n");
// 	printf(" %x ", -99);
// 	printf("\n");
// 	printf(" %x ", -100);
// 	printf("\n");
// 	printf(" %x ", -101);
// 	printf("\n");
// 	printf(" %x ", INT_MAX);
// 	printf("\n");
// 	printf(" %x ", INT_MIN);
// 	printf("\n");
// 	printf(" %x ", LONG_MAX);
// 	printf("\n");
// 	printf(" %x ", LONG_MIN);
// 	printf("\n");
// 	printf(" %x ", UINT_MAX);
// 	printf("\n");
// 	printf(" %x ", ULONG_MAX);
// 	printf("\n");
// 	printf(" %x ", 9223372036854775807LL);
// 	printf("\n");
// 	printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	printf("\n");
// 	printf(" %x ", 42);
// 	printf("\n");
// 	printf(" %x ", -42);
// 	printf("\n");
// }
// int	main()
// {
// 	printf("printf output: [%s]\n[%s]\n[%p]\n", "Ciao 1 -3 &!", "");
// 	ft_printf("ft_printf output: [%s]\n[%s]\n[%p]\n", "Ciao 1 -3 &!", "");
// }
// int	main()
// {
// 	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
// 	printf("MIO PRINTF:\n");
// 	ft_printf("%s", "");
// 			printf("\n");
// 	ft_printf(" %s", "");
// 			printf("\n");
// 	ft_printf("%s ", "");
// 			printf("\n");
// 	ft_printf(" %s ", "");
// 			printf("\n");
// 	ft_printf(" %s %s ", "", "-");
// 			printf("\n");
// 	ft_printf(" %s %s ", " - ", "");
// 			printf("\n");
// 	ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
// 			printf("\n");
// 	ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
// 			printf("\n");
// 	ft_printf(" NULL %s NULL ", NULL);
// 	printf("\n\nVERO PRINTF:\n");
// 	printf("%s", "");
// 			printf("\n");
// 	printf(" %s", "");
// 			printf("\n");
// 	printf("%s ", "");
// 			printf("\n");
// 	printf(" %s ", "");
// 			printf("\n");
// 	printf(" %s %s ", "", "-");
// 			printf("\n");
// 	printf(" %s %s ", " - ", "");
// 			printf("\n");
// 	printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
// 			printf("\n");
// 	printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
// 			printf("\n");
// 	printf(" NULL %s NULL ", NULL);
// 			printf("\n");
// }
// int	main()
// {
// 	ft_printf(" %p ", -1);
// 		printf("\n");
// 	ft_printf(" %p ", 1);
// 		printf("\n");
// 	ft_printf(" %p ", 15);
// 		printf("\n");
// 	ft_printf(" %p ", 16);
// 		printf("\n");
// 	ft_printf(" %p ", 17);
// 		printf("\n");
// 	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
// 		printf("\n");
// 	ft_printf(" %p %p ", INT_MIN, INT_MAX);
// 		printf("\n");
// 	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// 		printf("\n");
// 	ft_printf(" %p %p ", 0, 0);
// 		printf("\n");
// 		printf("\n");

// 	printf(" %p ", -1);
// 		printf("\n");
// 	printf(" %p ", 1);
// 		printf("\n");
// 	printf(" %p ", 15);
// 		printf("\n");
// 	printf(" %p ", 16);
// 		printf("\n");
// 	printf(" %p ", 17);
// 		printf("\n");
// 	printf(" %p %p ", LONG_MIN, LONG_MAX);
// 		printf("\n");
// 	printf(" %p %p ", INT_MIN, INT_MAX);
// 		printf("\n");
// 	printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// 		printf("\n");
// 	printf(" %p %p ", 0, 0);
// 		printf("\n");
// }
// int	main()
// {
// 	int	x = 42;
// 	int	*ptr = &x;
// 	ft_printf("These are chars: %c and %c\n", '0', 65);
// 	ft_printf("This is a string: %s and %s and %s\n", "Bla bla bla!", "", NULL);
// 	ft_printf("Number %d and %d and %d\n", 42, -42, 0);
// 	ft_printf("Float %f and %f and %f\n", 3.14, -3.14, 0.0);
// 	ft_printf("Hexadecimal %x and %X and %x\n", 255, 255, -255);
// 	ft_printf("Pointer %p and %p\n", ptr, NULL);
// 	ft_printf("u int %u and %u\n", 42, -42);
// 	ft_printf("long int %ld and long hex %lx\n", 123456789L, 123456789L);
// 	ft_printf("percent %%\n");
// 	ft_printf("not supported: %z\n\n");

// 	printf("VERO PRINTF:\n");
// 	printf("These are chars: %c and %c\n", '0', 65);
// 	printf("This is a string: %s and %s and %s\n", "Bla bla bla!", "", NULL);
// 	printf("Number %d and %d and %d\n", 42, -42, 0);
// 	printf("Float %f and %f and %f\n", 3.14, -3.14, 0.0);
// 	printf("Hexadecimal %x and %X and %x\n", 255, 255, -255);
// 	printf("Pointer %p and %p\n", ptr, NULL);
// 	printf("u int %u and %u\n", 42, -42);
// 	printf("long int %ld and long hex %lx\n", 123456789L, 123456789L);
// 	printf("percent %%\n");
// 	printf("not supported: %z\n");
// }