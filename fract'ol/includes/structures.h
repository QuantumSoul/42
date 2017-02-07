/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:19:46 by edescoin          #+#    #+#             */
/*   Updated: 2017/02/07 17:40:19 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct			s_mlx_core
{
	void				*co;
	void				*win;
}						t_mlx_core;

typedef struct			s_image
{
	int					width;
	int					height;
	void				*ptr;
	char				*data;
	int					depth;
	int					size_line;
	int					endian;
}						t_image;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
	double				w;
}						t_vector;

typedef struct			s_key_evt
{
	int					key;
	void				(*fct)();
	struct s_key_evt	*next;
}						t_key_evt;

#endif
