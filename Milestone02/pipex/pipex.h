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

int	open_files(char *argv[]);


# endif