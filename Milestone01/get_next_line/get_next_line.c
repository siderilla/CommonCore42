/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:26:06 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/18 14:58:27 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_and_update_stock(int fd, char *read_buffer, char **stock)
{
	char	*newline_ptr;
	char	*temp_stock;
	ssize_t	nbytes;

	newline_ptr = NULL;
	nbytes = 1;
	while (!newline_ptr && nbytes > 0)
	{
		nbytes = read(fd, read_buffer, BUFFER_SIZE);
		if (nbytes > 0)
		{
			read_buffer[nbytes] = '\0';
			temp_stock = ft_strjoin(*stock, read_buffer);
			if (!temp_stock)
				return (free(*stock), *stock = NULL, -1);
			free(*stock);
			*stock = temp_stock;
			newline_ptr = ft_strchr(*stock, '\n');
		}
		else if (nbytes == 0) // una toppa 
			return (1);
		else
			return (-1);
	}
	return (nbytes);
}

static char	*prepare_stock(int fd, char **stock)
{
	char	*read_buffer;

	if (!*stock)
		*stock = ft_strdup("");
	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (free(*stock), *stock = NULL, NULL);
	if (!read_and_update_stock(fd, read_buffer, stock))
	{
		free(read_buffer);
		return (free(*stock), *stock = NULL, NULL);
	}
	free(read_buffer);
	return (*stock);
}

static char	*when_newline(char **stock)
{
	char	*newline_ptr;
	char	*residue;
	char	*new_stock;

	newline_ptr = ft_strchr(*stock, '\n');
	if (newline_ptr)
	{
		residue = ft_substr(*stock, 0, newline_ptr - *stock + 1);
		if (!residue)
			return (free(*stock), *stock = NULL, NULL);
		new_stock = ft_strdup(newline_ptr + 1);
		if (!new_stock)
		{
			return (free(residue), free(*stock), *stock = NULL, NULL);
		}
		free(*stock);
		*stock = new_stock;
		return (residue);
	}
	residue = ft_strdup(*stock);
	return (free(*stock), *stock = NULL, residue);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*residue;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = prepare_stock(fd, &stock);
	if (!stock)
		return (NULL);
	if (ft_strchr(stock, '\n'))
		return (when_newline(&stock));
	if (*stock)
	{
		residue = ft_strdup(stock);
		return (free(stock), stock = NULL, residue);
	}
	return (free(stock), stock = NULL, NULL);
}

// #include <stdio.h>
// int	main()
// {
// 	int	fd = open("binary_file", O_RDONLY);
// 	// int	fd = 5;
// 	char	*line;
// 	if (fd < 0)
// 	{
// 		perror("");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

// #include <stdio.h>
// int	main()
// {
// 	int	fd = open("read_error.txt", O_RDONLY);
// 	int i = 0;
// 	// int	fd = 5;
// 	char	*line;
// 	if (fd < 0)
// 	{
// 		perror("");
// 		return (1);
// 	}
// 	while (i < 6)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }

#include <stdio.h>
int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	// HOW TO SEE ALL REACHABLE - troncando all'improvviso la funzione //
	char	*line;
	if (fd < 0)
	{
		perror("");
		return (1);
	}
	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	close(fd);
	line = get_next_line(fd); 

	// possibile workaround per all reacheble (riavviare gnl dopo la chiusura di fd)
	return (0);
}
