/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:31:54 by skawanis          #+#    #+#             */
/*   Updated: 2023/07/27 21:27:42 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void execute_cmd(char *cmd, char **argv, char **envp)
{
	pid_t	pid;
	char	*child_argv[] = {"ls -l", NULL};
	(void)cmd;
	(void)argv;

	errno = 0;
	pid = fork();
	if (pid > 0)
	{
		printf("parent_prosess\n");
		exit();
	}
	if (pid == 0)
		execve("/bin/ls", child_argv, envp);
}

static void	check_arg_error(int argc, char **argv)
{
	(void)argv;
	if (argc == 0)
	{
		ft_putendl_fd("this program require arguments.", 2);
		exit (1);
	}
}

static char	**get_path(char**envp)
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
	return (path);
}

int	main(int argc, char**argv, char**envp)
{
	char	**path;

	check_arg_error(argc, argv);
	path = get_path(envp);
	execute_cmd(argv[1], argv, envp);
	(void)path;
	return (0);
}
