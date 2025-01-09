/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:26:06 by sde-pra           #+#    #+#             */
/*   Updated: 2024/12/18 14:59:26 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		else if (nbytes == 0)
			return (1);
		else
			return (-1);
	}
	return (1);
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
	static char	*stock[FD_MAX];
	char		*residue;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock[fd] = prepare_stock(fd, &stock[fd]);
	if (!stock[fd])
		return (NULL);
	if (ft_strchr(stock[fd], '\n'))
		return (when_newline(&stock[fd]));
	if (*stock[fd])
	{
		residue = ft_strdup(stock[fd]);
		return (free(stock[fd]), stock[fd] = NULL, residue);
	}
	return (free(stock[fd]), stock[fd] = NULL, NULL);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int		fd1 = open("file1.txt", O_RDONLY);
// 	int		fd2 = open("file2.txt", O_RDONLY);
// 	char	*line;

// 	if (fd1 < 0 || fd2 < 0)
// 		return (perror("Error opening file"), 1);

// 	printf("=== File 1 ===\n");
// 	while ((line = get_next_line(fd1)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}

// 	printf("=== File 2 ===\n");
// 	while ((line = get_next_line(fd2)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}

// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
