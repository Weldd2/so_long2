/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:51:02 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 17:44:54 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

t_ok	new_game(char *filename, t_game *game)
{
	int		fd;
	int		nb_line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (g_eno = E_OPEN, E_ERR);
	nb_line = wc_l(filename);
	new_map(fd, game, nb_line);
	if (is_rectangle(*game) == E_ERR)
		return (free_map(game->map), g_eno = E_MAPWIDTH, E_ERR);
	if (new_counter(game) == E_ERR)
		return (E_ERR);
	new_player(game);
	if (validate(*game) == E_ERR)
		return (free_game(*game), E_ERR);
	new_graphics(game);
	return (close(fd), E_OK);
}

void	free_game(t_game game)
{
	free_counter(game.counter);
	free_map(game.map);
	free_player(game.player);
}

