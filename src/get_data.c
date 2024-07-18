/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:51:15 by qhauuy            #+#    #+#             */
/*   Updated: 2024/04/26 23:32:58 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_data(t_data *data)
{
	if (data)
	{
		close(data->input_fd);
		close(data->output_fd);
		deep_free(data->path, get_length(data->path));
		free(data);
	}
}

static void	open_fd_ends(t_data *data, char *input_file, char *output_file)
{
	data->input_fd = open(input_file, O_RDONLY);
	if (data->input_fd == -1)
		perror("input file error");
	data->output_fd = open(output_file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->output_fd == -1)
	{
		perror("output file error");
		free_data(data);
		exit(EXIT_FAILURE);
	}
}

t_data	*get_data(char **argv, char **envp)
{
	t_data	*result;

	result = ft_calloc(1, sizeof(t_data));
	if (result == NULL)
		return (ft_stop("memory allocation error", NULL, NULL), NULL);
	open_fd_ends(result, argv[1], argv[4]);
	result->path = get_path(envp);
	if (result->path == NULL)
		return (ft_stop("path error", result, NULL), NULL);
	return (result);
}
