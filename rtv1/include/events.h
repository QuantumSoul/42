/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:10:33 by edescoin          #+#    #+#             */
/*   Updated: 2017/06/20 12:31:23 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "structures.h"
# ifndef __APPLE__
#  include <SDL2/SDL.h>
# else
#  include "SDL2/SDL.h"
# endif

/*
** events.c
*/
void	clear_events(t_event **head);
void	delete_event(t_event **head);
void	new_event(t_event **head, SDL_EventType type, void *data, int (*fct)());
void	wait_events(t_event *list_evts);

/*
** key_functions.c
*/
int		key_exit(SDL_Event *current, t_event *evt);

#endif
