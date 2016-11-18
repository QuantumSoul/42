/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:36:05 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/17 17:56:20 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	if (*s != '\0')
		return (!(tmp = ft_strrchr(s + 1, c)) && *s == c ? (char*)s : tmp);
	return (c == '\0' ? (char*)s : NULL);
}
