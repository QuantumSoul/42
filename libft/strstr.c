/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:19:48 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/07 18:13:06 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*tmp;

	if (little[0] == '\0')
		return ((char*)big);
	i = -1;
	j = -1;
	len = ft_strlen(little);
	while (big[++i] && j < len - 1)
		if (big[i] != little[++j])
			j = -1;
		else if (j == 0)
			tmp = (char*)&big[i];
	return (j == len - 1 ? tmp : NULL);
}
