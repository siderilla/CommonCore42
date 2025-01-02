#include <stdio.h>

int	main()
{
	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	printf("%s", "");
		printf("\n");
	printf(" %s", "");
		printf("\n");
	printf("%s ", "");
		printf("\n");
	printf(" %s ", "");
		printf("\n");
	printf(" %s %s ", "", "-");
		printf("\n");
	printf(" %s %s ", " - ", "");
		printf("\n");
	printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
		printf("\n");
	printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
		printf("\n");
	printf(" NULL %s NULL ", NULL);
		printf("\n");
}