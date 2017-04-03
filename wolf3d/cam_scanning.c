/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_scanning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:49:10 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/03 19:32:00 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "raycasting.h"
#include "bg_casting.h"
#include "mob_casting.h"

int	bidon()
{
	printf("TEST\n");
	return (1);
}

static void	cast_mobs(t_ray *ray, t_player *player, double correction, int i)
{
	if ((is_looking_left(player->cam) || is_looking_right(player->cam)) &&
		ray->v_mob && ray->v_mob->data.i.w < ray->d)
	{
		ray->h = (WALL_SIZE * player->cam->f) / (ray->v_mob->data.i.w * cos(correction));
		ray->v_mob->data.h = (ray->v_mob->height * player->cam->f) / (ray->v_mob->data.i.w * cos(correction));
		ray->filter = get_filter_value(player->tile->data, ray->v_mob->data.i.w);
		draw_mob(&player->cam->screen, i, ray, ray->v_mob);
	}
	if (ray->v_mob)
		ray->v_mob = NULL;
	if ((is_looking_up(player->cam) || is_looking_down(player->cam)) &&
		ray->h_mob && ray->h_mob->data.i.w < ray->d)
	{
		ray->h = (WALL_SIZE * player->cam->f) / (ray->h_mob->data.i.w * cos(correction));
		ray->h_mob->data.h = (ray->h_mob->height * player->cam->f) / (ray->h_mob->data.i.w * cos(correction));
		ray->filter = get_filter_value(player->tile->data, ray->h_mob->data.i.w);
		draw_mob(&player->cam->screen, i, ray, ray->h_mob);
	}
	if (ray->h_mob)
		ray->h_mob = NULL;
}

static void	cast_ray(t_ray *ray, t_player *player, double correction, int i)
{
	if (ray->a && fabs(ray->a) != M_PI)
		horiz_intersec(ray, player);
	if (fabs(ray->a) != M_PI_2 && fabs(ray->a) != (M_PI + M_PI_2))
		vert_intersec(ray, player);
	if (ray->h_i.w < player->cam->f && ray->h_i.w < ray->v_i.w)
	{
		ray->d = ray->h_i.w;
		ray->h = (WALL_SIZE * player->cam->f) / (ray->h_i.w * cos(correction));
		ray->filter = get_filter_value(player->tile->data, ray->h_i.w);
		cast_background(ray, i, player);
		draw_tile(&player->cam->screen, i, ray);
		cast_reflection(ray, i, player);
	}
	else if (ray->v_i.w < player->cam->f)
	{
		ray->d = ray->v_i.w;
		ray->h = (WALL_SIZE * player->cam->f) / (ray->v_i.w * cos(correction));
		ray->filter = get_filter_value(player->tile->data, ray->v_i.w);
		cast_background(ray, i, player);
		draw_tile(&player->cam->screen, i, ray);
		cast_reflection(ray, i, player);
	}
	else
		ray->d = player->cam->f;
}

void		scan_environment(t_player *player)
{
	int			i;
	double		angle;
	t_ray		ray;

	i = -1;
	ray.h_i.w = player->cam->f;
	ray.v_i.w = player->cam->f;
	ray.h_mob = NULL;
	ray.v_mob = NULL;
	while (++i <= player->cam->screen.w)
	{
		angle = atan((player->cam->half_scr - i) / player->cam->f);
		ray.a =  angle + ft_to_rad(player->cam->angle);
		cast_ray(&ray, player, angle, i);
		cast_mobs(&ray, player, angle, i);
	}
	refresh_win();
}
