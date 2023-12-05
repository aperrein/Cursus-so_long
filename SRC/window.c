/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:33:27 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/07 16:10:15 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_good(t_game *game, char *good, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, good, \
		game->img.width * i, game->img.height * j);
}

int	end_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.empty);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.colec);
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.both);
	mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_error(game, "");
	exit(0);
	return (0);
}

int	keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		end_window(game);
	if (keysym == XK_w)
		move(game, 0, -1);
	if (keysym == XK_s)
		move(game, 0, 1);
	if (keysym == XK_a)
		move(game, -1, 0);
	if (keysym == XK_d)
		move(game, 1, 0);
	return (0);
}

void	img_init(t_game *game)
{
	game->img.empty = mlx_xpm_file_to_image(game->mlx, \
		"srct/empty.xpm", &(game->img.width), &(game->img.height));
	game->img.exit = mlx_xpm_file_to_image(game->mlx, \
		"srct/exit.xpm", &(game->img.width), &(game->img.height));
	game->img.wall = mlx_xpm_file_to_image(game->mlx, \
		"srct/wall.xpm", &(game->img.width), &(game->img.height));
	game->img.player = mlx_xpm_file_to_image(game->mlx, \
		"srct/player.xpm", &(game->img.width), &(game->img.height));
	game->img.colec = mlx_xpm_file_to_image(game->mlx, \
		"srct/collectable.xpm", &(game->img.width), &(game->img.height));
	game->img.both = mlx_xpm_file_to_image(game->mlx, \
		"srct/both.xpm", &(game->img.width), &(game->img.height));
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return ;
	game->nb_m = 0;
	game->old_e = 0;
	img_init(game);
	game->win = mlx_new_window(game->mlx, game->width * 40, \
		game->height * 40, "So_long");
	if (!game->win)
		return ;
	mlx_loop_hook(game->mlx, &view, game);
	mlx_hook(game->win, 17, 0, &end_window, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &keypress, game);
	mlx_loop(game->mlx);
}
