/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:51:02 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/30 18:43:19 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

// int	new_game(char *filename, t_game **game)
// {
// 	t_game	*game;

// 	if (ber_to_game(filename, &game) == E_ERR)
// 		return (E_ERR);
// 	// game->graphics = new_graphics();
// 	game->counter = new_counter();
// 	game->player = new_player();
// 	return (game);
// }

int	ber_to_game(char *filename, t_game **game)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (g_eno = E_OPEN, E_ERR);
	ber_to_map(fd, filename, game);
	if (fill_counter(game) == E_ERR)
		return (E_ERR);
	fill_player(game);
	return (E_OK);
}

// void	free_game(t_game *game)
// {
// 	free_graphics(game->graphics);
// 	free_counter(game->counter);
// 	free_map(game->map);
// 	free_player(game->player);
// 	free(game);
// }

