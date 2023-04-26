#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_arg{
	char	**path;
	char	**cmd1;
	char	**cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
	int		infile_fd;
	int		outfile_fd;
} t_arg;

char	**get_cmd(char *cmd);
char	*get_cmd_path(t_arg arg, int n);
char	**get_path(char **envp);

void	do_cmd1(t_arg arg);
void	do_cmd2(t_arg arg);
//void	do_pipe(int temp_fd, char *cmd2, char *outfile);

//utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcon(char *s1, char *s2);
int		ft_strlen(char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif