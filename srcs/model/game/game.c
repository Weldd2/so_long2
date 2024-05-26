/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:51:02 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 14:39:38 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

t_game	*new_game(int hauteur, int largeur)
{
	t_game	*game;

	game->map = new_map(hauteur, largeur);
	game->graphics = new_graphics(hauteur, largeur);
	game->counter = new_counter();
	game->player = new_player();
	return (game);
}

void	free_game(t_game *game)
{
	free_graphics(game->graphics);
	free_counter(game->counter);
	free_map(game->map);
	free_player(game->player);
	free(game);
}

