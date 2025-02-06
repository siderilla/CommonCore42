/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:19:10 by sde-pra           #+#    #+#             */
/*   Updated: 2025/02/06 22:19:12 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_dup(int fd_in, int fd_out)
{
	if (dup2(fd_in, STDIN_FILENO) == -1)
	{
		perror("stdin fail");
		exit(1);
	}
	if (dup2(fd_out, STDOUT_FILENO) == -1)
	{
		perorr("stdout fail");
		exit(1);
	}
	close(fd_in);
	close(fd_out);

}

t_pipefd	to_pipe()
{
	t_pipefd	pfd;
	int			pipefd[2];

	pipe(pipefd);
	pfd.read_fd = pipefd[0];
	pfd.write_fd = pipefd[1];

	return (pfd);
}

int	open_files(char *argv[], int *file1, int *file2)
{
	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | 0644);
}

int	main(int argc, char *argv[])
{
	if (argc != 5)
	{
		perror("The num of args should be five");
		exit(1);
	}
	int			file1;
	int			file2;
	t_pipefd	pfd;

	pfd = to_pipe();
	open_files(argv, &file1, &file2);
	dup2();
}

	// in_file = open(argv[1], O_RDONLY); // cosa? il file1 - argv[1]
	// 	fork(argv[2]); // cosa? cmd1 NON FUNZIONA COSI LEGGI MANUALE
	// 	dup2(); // reindirizzare output cmd1 su pipe
	// 	pipe(); // per concatenare con cmd2
