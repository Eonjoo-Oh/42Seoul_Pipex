/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoh <eoh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:25:09 by eoh               #+#    #+#             */
/*   Updated: 2023/06/12 13:03:43 by eoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**add_slash(char **path)
{
	int		i;
	char	*old_path;

	i = 0;
	while (path[i])
	{
		old_path = path[i];
		path[i] = ft_strjoin(path[i], "/");
		free(old_path);
		i++;
	}
	return (path);
}

char	**get_path(char **envp)
{
	char	*temp_path;
	char	**path;
	int		i;

	temp_path = NULL;
	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			temp_path = envp[i];
			break ;
		}
		i++;
	}
	if (temp_path == 0)
		return (0);
	temp_path += 5;
	path = (ft_split(temp_path, ':'));
	path = add_slash(path);
	return (path);
}
