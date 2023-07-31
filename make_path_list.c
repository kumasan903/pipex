/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:08:21 by skawanis          #+#    #+#             */
/*   Updated: 2023/07/31 21:30:28 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path(char**envp, size_t *path_len)
{
	size_t	i;
	char	**path;

	i = 0;
	while (1)
	{
		if (envp[i] == NULL)
			break ;
		if (start_with(envp[i], "PATH="))
			path = ft_split(envp[i] + 5, ':');
		i++;
	}
	*path_len = 0;
	while (path[*path_len] != NULL)
		*path_len += 1;
	return (path);
}

static char	**add_cmd_name(const char **path_list, size_t path_len, char *cmd)
{
	size_t	i;
	char	**cmd_path_list;
	char	*new_cmd;
	char	*cmd_name;

	cmd_name = ft_strndup(cmd, ft_strclen_s(cmd, ' '));
	new_cmd = ft_strjoin("/", cmd_name);
	cmd_path_list = ft_calloc(sizeof(char *), path_len + 1);
	i = 0;
	while (path_list[i] != NULL)
	{
		cmd_path_list[i] = ft_strjoin(path_list[i], new_cmd);
		i++;
	}
	i = 0;
	while (path_list[i] != NULL)
	{
		free((void *)path_list[i]);
		path_list[i] = NULL;
		i++;
	}
	free(path_list);
	return (cmd_path_list);
}

char	**make_cmd_path_list(char **argv, char **envp)
{
	size_t		path_len;
	const char	**path = (const char **)get_path(envp, &path_len);
	const char	**cmd_path_list = (const char **)add_cmd_name(path, path_len, argv[1]);
	(void)argv;
	return ((char **)cmd_path_list);
}
