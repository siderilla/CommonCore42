#include <unistd.h>

void	putnbr(int n)
{
	char c;

	if (n >= 10)
		putnbr(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
}

void	fizzbuzz(void)
{
	int n = 1;
	while (n <= 100)
	{
		if (n % 3 == 0 && n % 5 == 0)
			write (1, "fizzbuzz\n", 9);
		else if (n % 3 == 0)
			write (1, "fizz\n", 5);
		else if (n % 5 == 0)
			write (1, "buzz\n", 5);
		else
		{
			putnbr(n);
			write (1, "\n", 1);
		}
		n++;
	}
}

int	main()
{
	fizzbuzz();
	return (0);
}