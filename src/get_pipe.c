/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:48:05 by qhauuy            #+#    #+#             */
/*   Updated: 2024/06/17 15:32:12 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_cmd(t_cmd *cmd)
{
	if (cmd)
	{
		deep_free(cmd->split, get_length(cmd->split));
		free(cmd->pathname);
		free(cmd);
	}
}

void	free_pipe(t_pipe *pipe_)
{
	if (pipe_)
	{
		close(pipe_->fd[0]);
		close(pipe_->fd[1]);
		free_cmd(pipe_->cmd[0]);
		free_cmd(pipe_->cmd[1]);
		free(pipe_);
	}
}

static char	*get_cmd_pathname(char *name, char **path)
{
	char	*result;

	result = NULL;
	while (*path)
	{
		free(result);
		result = ft_strjoin(*path, name);
		if (access(result, X_OK) == 0)
			return (result);
		path++;
	}
	free(result);
	return (NULL);
}

static t_cmd	*get_cmd(t_data *data, t_pipe *pipe_, char *arg)
{
	t_cmd	*result;

	result = ft_calloc(1, sizeof(t_cmd));
	if (result == NULL)
		return (ft_stop("memory allocation error", data, pipe_), NULL);
	result->split = ft_split_quote(arg, ' ');
	if (result->split != NULL)
		result->pathname = get_cmd_pathname(result->split[0], data->path);
	if (result->split == NULL || result->pathname == NULL)
	{
		deep_free(result->split, get_length(result->split));
		result->split = NULL;
		ft_putstr_fd("command error for \"", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd("\". execve will fail", 2);
	}
	return (result);
}

t_pipe	*get_pipe(t_data *data, char **argv_cmd)
{
	t_pipe	*result;

	result = ft_calloc(1, sizeof(t_pipe));
	if (result == NULL)
		return (ft_stop("memory allocation error", data, NULL), NULL);
	if (pipe(result->fd) < 0)
		return (free(result), ft_stop("pipe error", data, NULL), NULL);
	printf("pipe 0 : %d\n, pipe 1 : %d\n", result->fd[0], result->fd[1]);
	
	result->cmd[0] = get_cmd(data, result, argv_cmd[0]);
	result->cmd[1] = get_cmd(data, result, argv_cmd[1]);
	return (result);
}
