/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/05/22 19:00:29 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	rotate_left(t_player *player)
{
	if (player->cam->angle + player->cam->sensi > 180)
		player->cam->angle = ((player->cam->angle + player->cam->sensi) - 180) -
							180;
	else
		player->cam->angle += player->cam->sensi;
	return (1);
}
int	rotate_right(t_player *player)
{
	if (player->cam->angle - player->cam->sensi < -180)
		player->cam->angle = ((player->cam->angle - player->cam->sensi) + 180) +
							180;
	else
		player->cam->angle -= player->cam->sensi;
	return (1);
}
