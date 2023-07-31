/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skawanis <skawanis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:32:03 by skawanis          #+#    #+#             */
/*   Updated: 2023/07/31 21:29:33 by skawanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	start_with(char *heystack, char *needle)
{
	size_t	i;

	if (!heystack || !needle)
		return (0);
	i = 0;
	while (1)
	{
		if (needle[i] != '\0' && heystack[i] != needle[i])
			return (0);
		if (needle[i] == '\0')
			return (1);
		i++;
	}
}

char	*ft_strndup(const char *s1, size_t size)
{
	char	*dest;

	dest = ft_calloc(sizeof(char), size + 1);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, size);
	return (dest);
}

//int main(void)
//{
//	printf("%d\n", start_with("esttest", "test"));
//	printf("%d\n", start_with("esttest", "tesuto"));
//	printf("%d\n", start_with("esttest", "t"));
//}
