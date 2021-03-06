/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:48:19 by edescoin          #+#    #+#             */
/*   Updated: 2017/03/03 22:10:24 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	translate_left(t_mouse_evt *arg)
{
	arg->ftl->x_max -= 10 / arg->ftl->zoom;
	arg->ftl->x_min -= 10 / arg->ftl->zoom;
	clear_image(arg->img);
	draw_fractal(arg->img, arg->ftl);
}

void	translate_right(t_mouse_evt *arg)
{
	arg->ftl->x_max += 10 / arg->ftl->zoom;
	arg->ftl->x_min += 10 / arg->ftl->zoom;
	clear_image(arg->img);
	draw_fractal(arg->img, arg->ftl);
}

void	translate_up(t_mouse_evt *arg)
{
	arg->ftl->y_max -= 10 / arg->ftl->zoom;
	arg->ftl->y_min -= 10 / arg->ftl->zoom;
	clear_image(arg->img);
	draw_fractal(arg->img, arg->ftl);
}

void	translate_down(t_mouse_evt *arg)
{
	arg->ftl->y_max += 10 / arg->ftl->zoom;
	arg->ftl->y_min += 10 / arg->ftl->zoom;
	clear_image(arg->img);
	draw_fractal(arg->img, arg->ftl);
}

void	toggle_cross(t_mouse_evt *arg)
{
	arg->img->disp_cross = !(arg->img->disp_cross);
	draw_fractal(arg->img, arg->ftl);
}
