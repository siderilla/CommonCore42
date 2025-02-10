int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

#include <stdio.h>
int	main()
{
	printf ("%d\n", ft_strlen("pippo"));
}