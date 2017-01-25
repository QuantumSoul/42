/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:27:54 by edescoin          #+#    #+#             */
/*   Updated: 2017/01/25 22:00:46 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

char	*add_new_cells(t_map **last, t_vector *crd, char *nbs)
{
	char	*tmp;

	while (*nbs && *(nbs + 1))
	{
		while (*nbs && *nbs != '\n' && ft_isspace(*nbs))
			++nbs;
		if (*nbs == '\n')
		{
			*last = (*last)->r_head;
			++crd->y;
			crd->x = -1;
			++nbs;
		}
		if ((tmp = ft_strspc(nbs)))
		{
			*last = insert_cell(*last, new_cell(create_vector((++crd->x), crd->y,
															ft_atoi(nbs))));
			nbs = tmp;
		}
		else if (*nbs)
			return (nbs);
	}
	return (NULL);
}

t_map	*read_file(char *path)
{
	t_vector	crds;
	char		*nbs;
	char		*tmp;
	int			len;
	int			fd;
	t_map		*last;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (NULL);
	nbs = ft_strnew(BUFF_SIZE);
	last = NULL;
	crds.x = -1;
	crds.y = 0;
	len = 0;
	while (read(fd, nbs + len, BUFF_SIZE - len) > 0)
	{
		tmp = add_new_cells(&last, &crds, nbs);
		len = ft_strlen(tmp);
		ft_strncpy(nbs, tmp, len);
		ft_memset(nbs + len, '\0', BUFF_SIZE - len);
	}
	free(nbs);
	return (last->r_head->c_head);
}

void	delete_map(t_map *map)
{
	t_map	*r_head;

	while (map)
	{
		r_head = map->down;
		while (map->right)
		{
			map = map->right;
			free(map->left->vect);
			free(map->left);
		}
		free(map->vect);
		free(map);
		map = r_head;
	}
}
