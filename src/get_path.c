/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhauuy <qhauuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:23:01 by qhauuy            #+#    #+#             */
/*   Updated: 2024/04/27 17:22:10 by qhauuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path_base(char **envp)
{
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
			return (ft_split(*envp + 5, ":"));
		envp++;
	}
	return (NULL);
}

static char	**add_slash(char **path)
{
	char	**result;
	int		i;
	int		n;

	n = get_length(path);
	result = ft_calloc(n + 1, sizeof(char *));
	if (result == NULL)
		return (deep_free(path, n), NULL);
	i = 0;
	while (i < n)
	{
		result[i] = ft_strjoin(path[i], "/");
		if (result[i] == NULL)
		{
			deep_free(result, i);
			deep_free(path, n);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	deep_free(path, n);
	return (result);
}

char	**get_path(char **envp)
{
	char	**result;

	result = get_path_base(envp);
	if (result == NULL)
		return (NULL);
	result = add_slash(result);
	if (result == NULL)
		return (NULL);
	return (result);
}
