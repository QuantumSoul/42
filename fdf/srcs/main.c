/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:11:38 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/06 12:24:45 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <fcntl.h>

void	exit_error(char *s)
{
	if (!s)
	{
		perror("fdf");
		exit(1);
	}
	ft_putstr_fd(s, 2);
	exit(1);
}

void	exit_main(void)
{
	mlx_destroy_window(mlx_get_core()->co, mlx_get_core()->win);
	garbage_collector(CLEAR, NULL, NULL);
	exit(0);
}

void	create_events(t_key_evt **head, t_mlx_core *core)
{
	mlx_do_key_autorepeaton(core->co);
	new_key_evt(head, K_Z, &translate_up);
	new_key_evt(head, K_Q, &translate_left);
	new_key_evt(head, K_S, &translate_down);
	new_key_evt(head, K_D, &translate_right);
	new_key_evt(head, K_I, &zoom_in);
	new_key_evt(head, K_O, &zoom_out);
	new_key_evt(head, K_UP, &rotate_up);
	new_key_evt(head, K_LEFT, &rotate_left);
	new_key_evt(head, K_DOWN, &rotate_down);
	new_key_evt(head, K_RIGHT, &rotate_right);
	garbage_collector(ADD, head, &clear_key_evts);
	mlx_hook(core->win, K_PRESS_EVT, K_PRESS_MASK, &key_hook, *head);
}

t_map	*init_map(int ac, char **av)
{
	int			s_xy;
	int			s_z;
	int			fd;
	t_matrix	*tmp;
	t_map		*map;

	if (ac < 2 || ac > 4)
		exit_error("usage: fdf [file] [scale xy] [scale z]\n");
	if (!(fd = open(av[1], O_RDONLY)))
		exit_error(NULL);
	if (!(map = read_file(fd)))
		exit_error(NULL);
	close(fd);
	s_xy = ac > 2 ? ft_atoi(av[2]) : SCALE_XY;
	s_z = ac > 3 ? ft_atoi(av[3]) : SCALE_Z;
	tmp = create_identity(4);
	scale(&tmp, s_xy, s_xy, s_z);
	translation(&tmp, -(map->vect->x / 2), -(map->vect->y / 2), 0);
	transform_map(map->r_head->c_head, tmp);
	delete_matrix(tmp);
	return (map->r_head->c_head);
}

int		main(int ac, char **av)
{
	t_map		*map;
	t_camera	*cam;
	t_mlx_core	*core;
	t_key_evt	*events;

	map = init_map(ac, av);
	garbage_collector(ADD, map, &delete_map);
	cam = new_camera(90, 90, 0, 300);
	garbage_collector(ADD, cam, &delete_camera);
	core = mlx_get_core();
	events = init_key_evts(K_ECHAP, &exit_main, cam, map);
	create_events(&events, core);
	projection(map, cam);
	mlx_loop(core->co);
	exit_main();
	return (0);
}
