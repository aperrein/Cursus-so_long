/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:46:17 by aperrein          #+#    #+#             */
/*   Updated: 2023/04/05 11:18:56 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_check(int argc, char *file)
{
	if (argc == 1)
		return (error("Error\nArg missing"));
	if (argc > 2)
		return (error("Error\nToo many args"));
	if (!ber_check(file))
		return (error("Error\nMap must be a .ber"));
	return (1);
}

int	line_nb(char *s, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(s, O_RDONLY);
	line = get_next_line(fd);
	if (line)
	{
		game->width = (int)ft_strlen(line) - 1;
	}
	(void)game;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	map_fill(char *file, t_game *game)
{
	int	i;
	int	e;
	int	fd;

	fd = open(file, O_RDONLY);
	i = 0;
	e = 0;
	while (i < game->height)
	{
		game->map[i] = get_next_line(fd);
		if ((int)ft_strlen(game->map[i]) != game->width + 1)
			e = 1;
		i++;
	}
	close(fd);
	if (e)
		free_error(game, "Error\nThe map is not rectangular\n");
	(void)game;
}

void	map_read(char *s, t_game *game)
{
	game->height = line_nb(s, game);
	game->map = malloc(sizeof(char *) * (game->height +1));
	if (game->map)
		map_fill(s, game);
	if (!game->height)
		free_error(game, "Error\nThe file is empty\n");
}

int	map_init(int argc, char *argv[], t_game *game)
{
	if (!file_check(argc, argv[1]))
		return (0);
	game->nb_c = 0;
	game->nb_e = 0;
	game->nb_p = 0;
	map_read(argv[1], game);
	if (!(game->map))
		return (0);
	map_check(game);
	return (1);
}
