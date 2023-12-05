/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:46:17 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/05 11:17:55 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_check(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][0] != '1')
			return (0);
		x++;
	}
	return (1);
}

void	get_info(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
				set_p(x, y, game);
			else if (game->map[y][x] == 'E')
				set_e(x, y, game);
			else if (game->map[y][x] == 'C')
				set_c(x, y, game);
			x++;
		}
		y++;
	}
}

void	recur_path(t_game *game, int y, int x)
{
	if (game->clone[y][x] != '0' && game->clone[y][x] != 'C'
			&& game->clone[y][x] != 'E' && game->clone[y][x] != 'P')
		return ;
	if (game->clone[y][x] == 'E')
		game->a_e++;
	if (game->clone[y][x] == 'C')
	{
		game->a_c++;
	}
	game->clone[y][x] = '2';
	recur_path(game, y, x - 1);
	recur_path(game, y, x + 1);
	recur_path(game, y - 1, x);
	recur_path(game, y + 1, x);
}

void	valid_path(t_game *game)
{
	int	i;

	i = 0;
	game->a_c = 0;
	game->a_e = 0;
	game->clone = clone(game);
	recur_path(game, game->player.y, game->player.x);
	if (!game->a_e || game->a_c != game->nb_c)
		free_error(game, "Error\nThere is no valid path\n");
	while (i < game->height)
		free(game->clone[i++]);
	free(game->clone);
}

void	map_check(t_game *game)
{
	if (!close_check(game))
	{
		free_error(game, "Error\nThe map is not surrounded by walls\n");
		return ;
	}
	get_info(game);
	if (game->nb_p != 1)
		free_error(game, "Error\nIncorrect player number\n");
	else if (game->nb_e != 1)
		free_error(game, "Error\nIncorrect exit number\n");
	else if (!game->nb_c)
		free_error(game, "Error\nAt least one collectable needed\n");
	else
		valid_path(game);
}
