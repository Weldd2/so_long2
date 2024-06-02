/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:36:11 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/02 11:08:26 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_errno	g_eno;

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

void	t_exit(t_game game)
{
	mlx_terminate(game.graphics->mlx);
	free_graphics(game.graphics);
	free_game(game);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (g_eno = E_OPEN, printerr(), EXIT_FAILURE);
	if (new_game(argv[1], &game) == E_ERR)
		return (printerr(), EXIT_FAILURE);
	mlx_key_hook(game.graphics->mlx, &my_keyhook, &game);
	mlx_loop(game.graphics->mlx);
	t_exit(game);
	return (E_OK);
}
