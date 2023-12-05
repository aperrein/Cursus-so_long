/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:13:27 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/07 16:07:26 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	e_move(t_game *game, int x, int y)
{
	game->map[y][x] = 'B';
	game->old_e = 1;
	if (!game->nb_c)
	{
		free(game->item);
		ft_printf("Bravo, you win in %d moves !\n", game->nb_m);
		end_window(game);
	}
}

void	move(t_game *game, int i, int j)
{
	int	x;
	int	y;

	x = game->player.x + i;
	y = game->player.y + j;
	if (game->map[y][x] != '1')
	{
		game->nb_m++;
		ft_printf("%d moves\n", game->nb_m);
		if (!game->old_e)
			game->map[y - j][x - i] = '0';
		else
			game->map[y - j][x - i] = 'E';
		if (game->map[y][x] == 'E')
			e_move(game, x, y);
		else
		{
			if (game->map[y][x] == 'C')
				game->nb_c--;
			game->map[y][x] = 'P';
			game->old_e = 0;
		}
		game->player.x = x;
		game->player.y = y;
	}
}

void	good(t_game *game, int i, int j)
{
	if (game->map[j][i] == '0')
		print_good(game, game->img.empty, i, j);
	if (game->map[j][i] == '1')
		print_good(game, game->img.wall, i, j);
	if (game->map[j][i] == 'C')
		print_good(game, game->img.colec, i, j);
	if (game->map[j][i] == 'E')
		print_good(game, game->img.exit, i, j);
	if (game->map[j][i] == 'P')
		print_good(game, game->img.player, i, j);
	if (game->map[j][i] == 'B')
		print_good(game, game->img.both, i, j);
}

int	view(t_game *game)
{
	int	i;
	int	j;

	if (!game->win)
		return (0);
	j = -1;
	while (++j < game->height)
	{
		i = -1;
		while (++i < game->width)
			good(game, i, j);
	}
	return (0);
}
