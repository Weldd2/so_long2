/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:36:11 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 15:18:12 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

t_errno				g_eno;

static void	printerr(void)
{
	static const char	*errstr[] = {\
		[E_GLOBAL] = "An error occured", \
		[E_OPEN] = "Could not open file.", \
		[E_MAPEMPTY] = "Map is empty", \
		[E_MAPWIDTH] = "Map has lines of different width.", \
		[E_MAPEDGES] = "Map is not surrounded by walls.", \
		[E_FINISHABLE] = "Map is not finishable.", \
		[E_INVALID_CHAR] = "Invalid char found.", \
		[E_COLLECTIBLE] = "Less than one collectible found", \
		[E_EXIT] = "Map must have exactly one exit", \
		[E_PLAYER] = "Map must have exactly one player"
	};
	if (errstr[g_eno])
		ft_printf("%s\n", errstr[g_eno]);
}

void	print_map(t_game game)
{
	for (int i = 0; i < game.map->hauteur; i++)
	{
		ft_printf("%s\n", game.map->tiles[i]);
	}
}


int	main(__attribute__((unused))int argc, __attribute__((unused)) char **argv)
{
	t_game	game;

	if (argc != 2)
		return (g_eno = E_OPEN, printerr(), EXIT_FAILURE);
	new_game(argv[1], &game);
	if (validate(game) == E_ERR)
		return (free_game(game), printerr(), EXIT_FAILURE);
	mlx_loop(game.graphics->mlx);
	mlx_terminate(game.graphics->mlx);
	free_game(game);
	return (E_OK);
}