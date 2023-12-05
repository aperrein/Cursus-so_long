/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:42:29 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/07 14:26:15 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "struc.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"

int		error(char *s);
int		ber_check(char *s);
int		map_init(int argc, char *argv[], t_game *game);
int		end_window(t_game *game);
int		view(t_game *game);
void	game_init(t_game *game);
void	img_init(t_game *game);
void	window_loop(t_game *game);
void	map_check(t_game *game);
void	free_error(t_game *game, char *s);
void	set_p(int x, int y, t_game *game);
void	set_e(int x, int y, t_game *game);
void	set_c(int x, int y, t_game *game);
void	good(t_game *game, int i, int j);
void	print_good(t_game *game, char *good, int i, int j);
void	move(t_game *game, int i, int j);
char	**clone(t_game *game);
#endif
