/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 22:19:10 by amura             #+#    #+#             */
/*   Updated: 2024/06/01 22:27:55 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	move_player(t_game *g, int dx, int dy, mlx_instance_t *instance)
{
	if ((dx < 0 && g->player->p_x > 0
			&& g->map->tiles[g->player->p_y][g->player->p_x + dx] != '1')
		|| (dy < 0 && g->player->p_y > 0
		&& g->map->tiles[g->player->p_y + dy][g->player->p_x] != '1')
		|| (dx > 0 && g->map->tiles[g->player->p_y][g->player->p_x + dx] != '1')
		|| (dy > 0 && g->map->tiles[g->player->p_y + dy][g->player->p_x] != '1')
	)
	{
		instance->x += dx * 32;
		instance->y += dy * 32;
		g->player->p_x += dx;
		g->player->p_y += dy;
	}
}

void	handle_keypress(mlx_key_data_t keydata, t_game *g, mlx_instance_t *inst)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(g, -1, 0, inst);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(g, 0, 1, inst);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(g, 0, -1, inst);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(g, 1, 0, inst);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		t_exit(*g);
}

void	handle_collectibles_and_exit(t_game *g, mlx_instance_t *instance)
{
	if (g->map->tiles[g->player->p_y][g->player->p_x] == 'C')
	{
		g->map->tiles[g->player->p_y][g->player->p_x] = '0';
		instance = get_img_by_pos(g, g->player->p_y, g->player->p_x, E_FLEUR);
		instance->enabled = false;
		g->counter->c_count--;
	}
	if (g->counter->c_count == 0
		&& g->map->tiles[g->player->p_y][g->player->p_x] == 'E')
	{
		t_exit(*g);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *game)
{
	t_game			*g;
	mlx_instance_t	*instance;

	g = (t_game *)game;
	instance = get_img_by_pos(g, g->player->p_y, g->player->p_x, E_TNT);
	if (instance)
	{
		handle_keypress(keydata, g, instance);
		handle_collectibles_and_exit(g, instance);
	}
	else
	{
		ft_printf("no instance");
	}
}
