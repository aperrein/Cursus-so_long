/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:17:41 by aperrein          #+#    #+#             */
/*   Updated: 2023/03/30 09:13:30 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_p(int x, int y, t_game *game)
{
	game->nb_p++;
	game->player.x = x;
	game->player.y = y;
}

void	set_e(int x, int y, t_game *game)
{
	game->nb_e++;
	game->exit.x = x;
	game->exit.y = y;
}

void	set_c(int x, int y, t_game *game)
{
	t_pos	*temp;
	int		i;

	game->nb_c++;
	i = 0;
	temp = malloc(sizeof(*temp) * game->nb_c);
	while (i < game->nb_c - 1)
	{
		temp[i] = game->item[i];
		i++;
	}
	if (game->nb_c > 1)
		free(game->item);
	game->item = temp;
	game->item[game->nb_c -1].x = x;
	game->item[game->nb_c -1].y = y;
}
