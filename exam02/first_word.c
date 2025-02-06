#include <unistd.h>

char	first_word(char *str)
{
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\t')
			str++;
		while (*str != ' ' && *str != '\t' && *str != '\0')
		{
			write (1, str, 1);
			str++;
			if (*str == ' ' || *str == '\t')
				*str = '\0';
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	first_word(av[1]);
	return (0);
}

// int	ft_strlen(char *str)
// {
// 	int	count;

// 	count = 1;
// 	while (str)
// 	{
// 		str++;
// 		count++;
// 	}
// 	return (count);
// }

// char	first_word(char	*str)
// {
// 	char	*word;
// 	char	*copy;

// 	if (!str)
// 		write (1, "\n", 1);
// 	*word = *copy;
// 	while (str && str != "\t" && str != " ") // se c'è spazio salta, se c'è altro copia e restituisce
// 	{
// 		*copy = *str;
// 		copy++;
// 		str++;
// 	}
// 	return (word);
// }
// bisogna usare per forza putchar stampando un carattere alla volta o è possibile restituire direttamente la stringa copiata? //
// potendo usare solo write in effetti putchar è inevitabile (forse) //
// int	main(int ac, char *av)
// {
// 	char	*word;
	
// 	if (ac != 2)
// 		return (1);
// 	word = first_word(av[1]);
// 	write(1, word, ft_strlen(word)); //DEVO SCRIVERLA//
// 	return (0);
// }

// char	first_word(char	*str)
// {
// 	if (!str)
// 		write (1, "\n", 1);
// 	while (*str != '\0')
// 	{
// 		if (*str == ' ' && *str == '\t')
// 			str++;
// 		if (*str >= 65 && *str <= 90)
// 		{
// 			write (1, str, 1);
// 			str++;
// 		}
// 		str++;
// 	}
// 	return (*str);
// }

// int	main(int ac, char *av[])
// {
// 	if (ac != 2)
// 		return (1);
// 	first_word(av[1]);
// 	return (0);
// }

