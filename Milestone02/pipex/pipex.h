/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:19:17 by sde-pra           #+#    #+#             */
/*   Updated: 2025/02/06 23:08:09 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct pipefd
{
	int read_fd;
	int	write_fd;
}					t_pipefd;

void		redirect_dup(int fd_in, int fd_out);
t_pipefd	to_pipe();
int			open_files(char *argv[], int *file1, int *file2);

# endif
