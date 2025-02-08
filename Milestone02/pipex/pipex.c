/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-pra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:19:10 by sde-pra           #+#    #+#             */
/*   Updated: 2025/02/08 16:37:15 by sde-pra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute(char *argv[], char *envp[])
{
	// split di cmd
	// split di path 
	// CHE POI SAREBBERO UN'EMULAZIONE DI GETENV E/O EXECVP (forbidden functions)
	// access di path
	// execve 
}

// redirect degli fd stdin stdout su file1 e file2 //
void	redirect_dup(int fd_in, int fd_out)
{
	if (dup2(fd_in, STDIN_FILENO) == -1)
	{
		perror("stdin fail");
		exit(1);
	}
	if (dup2(fd_out, STDOUT_FILENO) == -1)
	{
		perror("stdout fail");
		exit(1);
	}
	close(fd_in);
	close(fd_out);
}

// creazione pipe assegnazione fd //
t_pipefd	to_pipe()
{
	t_pipefd	pfd;
	int			pipefd[2];

	pipe(pipefd);
	pfd.read_fd = pipefd[0];
	pfd.write_fd = pipefd[1];

	return (pfd);
}

// int	open_files(char *argv[], int *file1, int *file2)
// {
// 	*file1 = open(argv[1], O_RDONLY);
// 	if (*file1 == -1)
// 	{
// 		perorr("No such file");
// 		exit(1);
// 	}
// 	*file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | 0644);
// 	if (*file2 == -1)
// 	{
// 		perorr("No such file");
// 		exit(1);
// 	}
// }

void	child2(char *argv[], t_pipefd pfd, char *envp[])
{
	int	file2;
	
	file2 = open(argv[4], O_RDONLY);
	if (file2 == -1)
	{
		perorr("No such file");
		exit(1);
	}
	redirect_dup(pfd.write_fd, file2);
	execute(argv[3], envp);
}

void	child1(char *argv[], t_pipefd pfd, char *envp[])
{
	int	file1;
	
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		perorr("No such file");
		exit(1);
	}
	redirect_dup(pfd.read_fd, file1);
	execute(argv[2], envp);
}

void	parent(bohvediamo);

int	main(int argc, char *argv[], char **envp)
{
	t_pipefd	pfd;
	pid_t		pid1;
	pid_t		pid2;
	
	if (argc != 5)
	{
		perror("The num of args should be five");
		exit(1);
	}
	pfd = to_pipe();
	pid1 = fork();
	pid2 = fork();
	
	// // int			file1;
	// // int			file2;
	// // if (pid == -1)
	// // 	exit(-1);
	// // if (!pid)
	// // 	child(argv, pfd, envp);
	// // parent(argv, pfd, envp);
	// // open_files(argv, &file1, &file2);
}

	// in_file = open(argv[1], O_RDONLY); // cosa? il file1 - argv[1]
	// 	fork(argv[2]); // cosa? cmd1 NON FUNZIONA COSI LEGGI MANUALE
	// 	dup2(); // reindirizzare output cmd1 su pipe
	// 	pipe(); // per concatenare con cmd2
