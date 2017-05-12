/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:54:06 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/12 23:04:10 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <math.h>

static char	*get_data(const char *str, char *buff, int fd)
{
	char	*n;
	int		nb;

	if ((nb = read(fd, buff, 1024)) > 0)
	{
		lseek(fd, 0, SEEK_SET);
		buff[1023] = '\0';
		if (!(buff = ft_strstr(buff, str)))
			return (NULL);
		buff += ft_strlen(str) + 1;
		while (*buff && (*buff == ':' || ft_isspace(*buff)))
			++buff;
		if ((n = ft_strchr(buff, '\n')))
		 	*n = '\0';
		return (buff);
	}
	else if (nb < 0)
		exit_error(NULL);
	return (NULL);
}

int			get_map_brightness(t_map_data *data, int fd, char *buff)
{
	char	*tmp;

	if ((tmp = get_data("brightness", buff, fd)))
		set_map_brightness(data, ft_atoi(tmp));
	else
		set_map_brightness(data, 100);
	return (tmp != NULL);
}

int			get_map_background(t_map_data *data, int fd, char *buff)
{
	char	*tmp;

	if (!(tmp = get_data("background", buff, fd)) || ft_strequ(tmp, "none"))
		data->bgd = NULL;
	else
		data->bgd = create_texture(tmp);
	return (tmp != NULL);
}

int			get_map_reflection(t_map_data *data, int fd, char *buff)
{
	char	*tmp;

	if (!(tmp = get_data("reflections", buff, fd)) ||
		!ft_strequ(tmp, "true"))
		data->reflection = 0;
	else
		data->reflection = 1;
	return (tmp != NULL);
}

int			get_map_floor(t_map_data *data, int fd, char *buff)
{
	char	*tmp;

	if (!(tmp = get_data("floor", buff, fd)) || ft_strequ(tmp, "none"))
	{
		if (data->bgd)
			data->floor.a = 0;
		else
		{
			data->floor.r = 0;
			data->floor.g = 0;
			data->floor.b = 0;
			data->floor.a = 255;
		}
	}
	else
	{
		data->floor.r = ft_atoi(tmp);
		tmp = ft_strchr(tmp, ',');
		data->floor.g = tmp ? ft_atoi(++tmp) : 0;
		tmp = ft_strchr(tmp, ',');
		data->floor.b = tmp ? ft_atoi(++tmp) : 0;
		tmp = ft_strchr(tmp, ',');
		data->floor.a = tmp ? ft_atoi(++tmp) : 0;
	}
	return (tmp != NULL);
}
