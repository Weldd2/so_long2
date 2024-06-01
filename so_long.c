/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:36:11 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 19:59:34 by antoinemura      ###   ########.fr       */
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

void	t_exit(t_game game)
{
	mlx_terminate(game.graphics->mlx);
	free_game(game);
	printerr();
	exit(EXIT_SUCCESS);
}

void my_keyhook(mlx_key_data_t keydata, __attribute__((unused)) void* game)
{
	t_game *g;

	g = (t_game *)game;
	mlx_instance_t *instance = get_img_instance_by_position(g, g->player->p_y, g->player->p_x, E_TNT);
	if (instance)
	{
		if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
			&& (g->player->p_x-1 > 0)
			&& (g->map->tiles[g->player->p_y][g->player->p_x-1] != '1')
			)
		{
			instance->x -= 32;
			g->player->p_x--;
		}
		if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
			&& (g->player->p_y+1 > 0)
			&& (g->map->tiles[g->player->p_y+1][g->player->p_x] != '1')
			)
		{
			instance->y += 32;
			g->player->p_y++;
		}
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
			&& (g->player->p_y-1 > 0)
			&& (g->map->tiles[g->player->p_y-1][g->player->p_x] != '1')
			)
		{
			instance->y -= 32;
			g->player->p_y--;
		}
		if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
			&& (g->player->p_x+1 > 0)
			&& (g->map->tiles[g->player->p_y][g->player->p_x+1] != '1')
			)
		{
			instance->x += 32;
			g->player->p_x++;
		}
		if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		{
			t_exit(*g);
		}
		if (g->map->tiles[g->player->p_y][g->player->p_x] == 'C')
		{
			g->map->tiles[g->player->p_y][g->player->p_x] = '0';
			instance = get_img_instance_by_position(game, g->player->p_y, g->player->p_x, E_FLEUR);
			instance->enabled = false;
			g->counter->c_count--;
		}
		if (g->counter->c_count == 0 && g->map->tiles[g->player->p_y][g->player->p_x] == 'E')
		{
			t_exit(*g);
		}
	}
	else 
	{
		ft_printf("no instance");
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
	mlx_key_hook(game.graphics->mlx, &my_keyhook, &game);
	mlx_loop(game.graphics->mlx);
	t_exit(game);
	return (E_OK);
}