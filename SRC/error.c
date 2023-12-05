/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:22:37 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/05 11:16:57 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_check(char *s)
{
	char	*ext;

	ext = ft_strrchr(s, '.');
	if (!ext)
		return (0);
	if (ft_strncmp(ext, ".ber", 5) != 0)
		return (0);
	return (1);
}

int	error(char *s)
{
	ft_printf("%s\n", s);
	return (0);
}

void	free_error(t_game *game, char *s)
{
	int	i;

	i = 0;
	while (i < game->height)
		free(game->map[i++]);
	free(game->map);
	game->map = NULL;
	if (game->nb_c)
		free(game->item);
	ft_printf("%s", s);
}

char	**clone(t_game *game)
{
	int		i;
	char	**res;

	i = 0;
	res = malloc(sizeof(char *) * game->height);
	while (i < game->height)
	{
		res[i] = ft_strdup(game->map[i]);
		i++;
	}
	return (res);
}
