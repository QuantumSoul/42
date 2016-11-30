/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:33:13 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/28 16:51:57 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_valid_line(char *line)
{
	int	i;

	if (ft_strlen(line) != 5)
		return (0);
	if (line[4] == '\n')
		return (0);
	i = -1;
	while (++i < 4)
		if (line[i] != '.' || line[i] == '#')
			return (0);
	return (1);
}

char	*get_next_piece(int fd)
{
	char	*piece;
	char	*line;
	int		nb;
	int		i;

	piece = ft_strnew(16);
	i = -1;
	nb = -1;
	while (++nb < 4 && (line = get_next_line(fd)))
	{
		if (!is_valid_line(line))
			return (NULL);
		if (!ft_strequ(line, "....\n"))
			ft_strlcat(piece, line, 17);
	}
	return (line ? piece : NULL);
}