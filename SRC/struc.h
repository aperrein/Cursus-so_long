/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:19:38 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/05 09:51:33 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUC_H
# define STRUC_H

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_solong_img
{
	int		height;
	int		width;
	void	*empty;
	void	*wall;
	void	*colec;
	void	*exit;
	void	*player;
	void	*both;
}	t_solong_img;

typedef struct s_game
{
	char			**map;
	char			**clone;
	void			*mlx;
	void			*win;
	int				height;
	int				width;
	int				nb_p;
	int				nb_c;
	int				a_c;
	int				nb_e;
	int				a_e;
	int				nb_m;
	int				old_e;
	t_pos			player;
	t_pos			exit;
	t_pos			*item;
	t_solong_img	img;
}	t_game;

#endif
