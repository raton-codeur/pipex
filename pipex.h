/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:34:44 by qhauuy            #+#    #+#             */
/*   Updated: 2024/04/26 23:38:48 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

typedef struct s_data
{
	int			input_fd;
	int			output_fd;
	char		**path;
}	t_data;

typedef struct s_cmd
{
	char	**split;
	char	*pathname;
}	t_cmd;

typedef struct s_pipe
{
	t_cmd	*cmd[2];
	int		fd[2];
}	t_pipe;

/* utils.c*/
void	ft_stop(char *message, t_data *data, t_pipe *pipe_);
void	free_all(t_data *data, t_pipe *pipe_);

/* get_data.c */
t_data	*get_data(char **argv, char **envp);
void	free_data(t_data *data);

/* get_path.c */
char	**get_path(char **envp);

/* get_pipe.c */
t_pipe	*get_pipe(t_data *data, char **argv_cmd);
void	free_pipe(t_pipe *pipe_);

/* run_pipe.c */
void	run_pipe(t_pipe *pipe_, t_data *data);

#endif
