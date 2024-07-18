/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:38:17 by qhauuy            #+#    #+#             */
/*   Updated: 2024/04/26 23:39:01 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	run_cmd(t_cmd *cmd, int input_fd, int output_fd, int pipe_other_fd)
{
	close(pipe_other_fd);
	if (dup2(input_fd, 0) < 0)
		return (perror("dup2 error for input"));
	if (dup2(output_fd, 1) < 0)
		return (perror("dup2 error for output"));
	if (execve(cmd->pathname, cmd->split, NULL))
		return (perror("execve error"));
}

void	run_pipe(t_pipe *pipe_, t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		perror("fork error");
	else if (pid == 0)
		run_cmd(pipe_->cmd[0], data->input_fd, pipe_->fd[1], pipe_->fd[0]);
	else
	{
		pid = fork();
		if (pid < 0)
			perror("fork error");
		else if (pid == 0)
			run_cmd(pipe_->cmd[1], pipe_->fd[0], data->output_fd, pipe_->fd[1]);
		else
		{
			free_all(data, pipe_);
			while (wait(NULL) > 0)
				;
			return ;
		}
	}
	free_all(data, pipe_);
}
