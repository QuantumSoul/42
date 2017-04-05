/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:52 by edescoin          #+#    #+#             */
/*   Updated: 2017/04/05 19:20:55 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define TITLE			"Wolf3D"
# define HEIGHT 		700
# define WIDTH 			700
# define NB_TEXTURES	2
# define SPEED			1
# define WALL_SIZE		16
# define TEXT_SIZE		64
# define BUFF_SIZE		1024

# ifndef __APPLE__
#  include <SDL2/SDL.h>
#  define SDL_VIDEO		SDL_VIDEO_DRIVER_X11
# else
#  include "SDL.h"
#  define SDL_VIDEO		SDL_VIDEO_DRIVER_COCOA
# endif

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "structures.h"

/*
** angles.c
*/
int					is_east(double angle);
int					is_north(double angle);
int					is_south(double angle);
int					is_west(double angle);

/*
** camera.c
*/
t_camera			*create_camera(int fov, int angle, double sensibility);
void				delete_camera(t_camera *cam);
void				refresh_cam(t_camera *cam);
void				set_camera_fov(t_camera	*cam, int fov);

/*
** cam_angles.c
*/
int					is_looking_down(t_camera *cam);
int					is_looking_left(t_camera *cam);
int					is_looking_right(t_camera *cam);
int					is_looking_up(t_camera *cam);

/*
** cam_scanning.c
*/
void				scan_environment(t_player *player);

/*
** events.c
*/
void				clear_events(t_event **head);
void				delete_event(t_event **head);
void				new_event(t_event **head, SDL_Scancode key, int (*fct)());
void				wait_events(t_event *list_evts, t_player *player);

/*
** graphics.c
*/
Uint32				get_color(int r, int g, int b);
Uint8				get_filter_value(t_map_data *data, double dist);
void				refresh_win();
void				SDL_DestroyCore();
t_SDL_Core			*SDL_GetCore();

/*
** key_events.c
**t_key_data			*new_key_data(SDL_Keycode key, int (*fct)(), t_player *player);
**int					key_hook(SDL_Event evt, t_event *list_evts);
*/

/*
** key_functions_*.c
*/
int					move_down(t_player *player);
int					move_left(t_player *player);
int					move_right(t_player *player);
int					move_up(t_player *player);
int					rotate_left(t_player *player);
int					rotate_right(t_player *player);

/*
** main.c
*/
void				exit_error(char *s);
void				exit_main();

/*
** map.c
*/
void				delete_map(t_map *map);
t_map				*read_file(int fd);
void				set_map_brightness(t_map *map, int percent);

/*
** mob.c
*/
t_mob				*create_mob(t_npc_spts *spts, int w, int h, int view);
void				delete_mob(t_mob *mob);
void				insert_mob(t_map *cell, char *nbs);

/*
** player.c
*/
t_player			*create_player(t_camera *cam, double x, double y, t_map *map);
void				delete_player(t_player *player);

/*
** sprites.c
*/
t_sprite			*create_sprite(char *path, int h, int map_width, int delay);
void				delete_sprite(t_sprite *sprite);

/*
** textures.c
*/
t_texture			*create_texture(char *path);
void				delete_texture(t_texture *texture);
t_texture			*load_reflection(t_tile type);
t_texture			*load_texture(t_tile type);

/*
** tiles.c
*/
void				delete_cell(t_map *cell);
t_map				*insert_cell(t_map *head, t_map *cell);
int					is_empty(t_map *tile);
t_map				*goto_tile(t_vector *crd, t_map *tile);
t_map				*new_cell(t_vector *vect, t_tile type, t_map_data *data);

/*
** tools.c
*/
void				set_rect_crd(SDL_Rect *rect, int x, int y);
void				set_rect_dim(SDL_Rect *rect, int w, int h);
t_ray				*set_wall(t_ray *ray, t_map **ray_wall, t_map *wall);

/*
** transformations.c
*/
void				translation();
void				rotation();

#endif
