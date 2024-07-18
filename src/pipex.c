/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:51:21 by qhauuy            #+#    #+#             */
/*   Updated: 2024/04/26 23:39:12 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	t_pipe	*pipe_;

	if (argc != 5)
		return (ft_putendl_fd("wrong number of arguments", 2), 1);
	data = get_data(argv, envp);
	pipe_ = get_pipe(data, argv + 2);
	run_pipe(pipe_, data);
	return (0);
}
