/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:31:54 by skawanis          #+#    #+#             */
/*   Updated: 2023/08/01 18:39:09 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(const char *bin_path, char **argv, char **envp, int infile_fd)
{
	pid_t		pid;
	const char	**child_argv = (const char **)ft_split(argv[2], ' ');

	if (!bin_path)
	{
		perror("pipex");
		return ;
	}
	errno = 0;
	pid = fork();
	if (pid > 0)
	{
		wait(NULL);
	}
	if (pid == 0)
	{
		dup2(infile_fd, STDIN_FILENO);
		if(execve(bin_path, (char **)child_argv, envp))
			perror("pipex");
	}
}

void	check_arg_error(int argc, char **argv)
{
	(void)argv;
	if (argc != 3)
	{
		ft_putendl_fd("argc != 3", 2);
		exit (1);
	}
	if (access(argv[1], R_OK))
	{
		ft_putendl_fd("we can't read input file", 2);
		exit(1);
	}
}

char	*search_bynary(const char **cmd_path_list)
{
	size_t	i;
	int		ret;

	i = 0;
	while (cmd_path_list[i])
	{
		ret = access(cmd_path_list[i], X_OK);
		if (ret == 0)
		{
			return ((char *)cmd_path_list[i]);
		}
		i++;
	}
	return (NULL);
}

int	main(int argc, char**argv, char**envp)
{
	const char	**cmd_path_list = (const char **)make_cmd_path_list(argv, envp);
	const char	*bin_path = search_bynary(cmd_path_list);
	int			infile_fd;

	check_arg_error(argc, argv);
	infile_fd = open(argv[1], O_RDONLY);
	printf("infile_fd:%d\n", infile_fd);
	execute_cmd(bin_path, argv, envp, infile_fd);
	return (0);
}
