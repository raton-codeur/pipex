/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:50:23 by qhauuy            #+#    #+#             */
/*   Updated: 2024/04/26 23:07:27 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_stop(char *message, t_data *data, t_pipe *pipe_)
{
	free_all(data, pipe_);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	free_all(t_data *data, t_pipe *pipe_)
{
	free_data(data);
	free_pipe(pipe_);
}
