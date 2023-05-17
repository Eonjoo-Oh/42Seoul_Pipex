/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:08:03 by eoh               #+#    #+#             */
/*   Updated: 2023/05/10 16:19:15 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_cmd(t_arg arg)
{
	pid_t	pid1;
	pid_t	pid2;
/*
	pid1 = fork();
	if (pid1 == -1)
		print_error("fork error");
	if (pid1 == 0)
	{
		pid2 = fork();
		if (pid2 == -1)
			print_error("fork error");
		if (pid2 == 0)
			do_pid1(arg);
		else
		{
			waitpid(pid2, 0, 0);
			do_pid2(arg);
		}
	}
	else
	{
		waitpid(pid1, 0, 0);
		close(arg.fd[0] == -1);
		close(arg.fd[1] == -1);
	}
}*/
	if (pipe(arg.fd) == -1)
		print_error("pipe error");
	pid1 = fork();
	if (pid1 == -1)
		print_error("fork error");
	if (pid1 == 0)
		do_pid1(arg);
	pid2 = fork();
	if (pid2 == -1)
		print_error("fork error");
	if (pid2 == 0)
		do_pid2(arg);
	if (close(arg.fd[0]) == -1)
		print_error("close error");
	if (close(arg.fd[1]) == -1)
		print_error("close error");
	waitpid(pid1, 0, 0);
	waitpid(pid2, 0, 0);
}
	//갑자기된다? close도 다 제대로 해줘야하는것 같음
//./pipex infile "ls" "wc -l" outfile -> 결과 36
// < infile ls | wc -l > outfile
