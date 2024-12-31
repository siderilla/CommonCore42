#include <stdio.h>

int	main()
{
	int	a = 10;
	int	*p = &a;

	printf("Memory address is %p\n", (void *)p);
}