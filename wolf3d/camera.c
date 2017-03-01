/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:12:56 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/01 17:08:06 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_camera	*new_camera(int fov)
{
	t_camera	*cam;

	if (!(cam = malloc(sizeof(t_camera))))
		return (NULL);
	cam->fov = fov;
	cam->f = HEIGHT / (2 * tan(ft_to_rad(fov) / 2.0f));
	cam->screen = NULL;
	return (cam);
}

void		delete_camera(t_camera *cam)
{
	free(cam);
}

void		set_camera_fov(t_camera *cam, int fov)
{
	cam->fov = fov;
	cam->f = HEIGHT / (2 * tan(ft_to_rad(cam->fov) / 2.0f));
}
