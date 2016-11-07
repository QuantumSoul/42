/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:39:40 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/07 18:12:27 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_pause(void)
{
	char	c;
	scanf("%c", &c);
	if (c != '\n')
		exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	char	*dst;

	if (!(dst = (char*)malloc(100)))
		exit(EXIT_FAILURE);

	printf("--- ft_strcpy ---\n123 : %s\n\n",
			ft_strcpy(dst, "123"));
	ft_pause();

	printf("--- ft_strcat ---\n123 + 456 : %s\n\n",
			ft_strcat(dst, "456"));
	ft_pause();

	printf("--- ft_strdup ---\n123 : %s\n\n",
			ft_strdup(dst));
	ft_pause();

	printf("--- ft_strlen ---\n123 : [%lu]\n\n",
			ft_strlen(dst));
	ft_pause();

	printf("--- ft_strncpy ---\n123456 : %s\n\n",
			ft_strncpy(dst, "123456", 9));
	ft_pause();

	printf("--- ft_strncat ---\n123456 + 789 : %s\n\n",
			ft_strncat(dst, "789", 3));
	ft_pause();

	printf("--- ft_strlcat ---\n123456 + 789 : [%lu] %s\n\n",
			ft_strlcat(dst, "789", 100), dst);
	ft_pause();

	printf("--- ft_strchr ---\n5 > 123456789 : %s\n\n",
			ft_strchr(dst, '5'));
	ft_pause();

	printf("--- ft_strrchr ---\n5 > 123456789-5*** : %s\n\n",
			ft_strrchr(ft_strcat(dst, "-5***"), '5'));
	ft_pause();
		return (0);
}
