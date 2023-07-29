/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:31:54 by skawanis          #+#    #+#             */
/*   Updated: 2023/07/29 17:40:08 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static void execute_cmd(char *cmd, char **argv, char **envp)
{
	pid_t		pid;
	const char	**path = (const char **)get_path(envp);
	char		*child_argv[] = {"ls", NULL};
	size_t		i;
	int			flag;
	(void)argv;

	errno = 0;
	i = 0;
	printf("cmd:%s\n", cmd);
	while (path[i] && flag == 1)
	{
		flag = 0;
		pid = fork();
		if (pid > 0)
		{
			wait(NULL);
		//	printf("parent_prosess\n");
		}
		if (pid == 0)
		{
			if(execve(ft_strjoin(ft_strjoin(path[i], "/"),cmd), child_argv, envp))
				flag = 1;
//			if(execve("/bin/aa", child_argv, envp))
//				perror("pipex");
		}
		i++;
	}

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

char	**make_cmd_path_list(char **argv, char **envp)
{
	const char **path = get_path(envp);
	const char **path_list = 
}

int	main(int argc, char**argv, char**envp)
{
	const char **cmd_path_list = make_cmd_path_list(argv, envp);

	check_arg_error(argc, argv);
	execute_cmd(argv[1], argv, envp);
	return (0);
}
