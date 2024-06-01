/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 22:58:25 by amura             #+#    #+#             */
/*   Updated: 2024/06/01 23:10:13 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_ok	is_valid(int x, int y, t_map *map, t_ok **visited)
{
	return (x >= 0 && x < map->hauteur && y >= 0 && y < map->largeur
		&& map->tiles[x][y] != '1' && !visited[x][y]);
}

void	init_bfs_vars(t_bfs_vars *vars, t_game game)
{
	vars->directions[0][0] = -1;
	vars->directions[0][1] = 0;
	vars->directions[1][0] = 1;
	vars->directions[1][1] = 0;
	vars->directions[2][0] = 0;
	vars->directions[2][1] = -1;
	vars->directions[3][0] = 0;
	vars->directions[3][1] = 1;
	vars->q.front = NULL;
	vars->q.rear = NULL;
	enqueue(&(vars->q), game.player->p_y, game.player->p_x);
	vars->visited = init_visited(game.map->hauteur, game.map->largeur);
	vars->visited[game.player->p_y][game.player->p_x] = true;
	vars->exit_found = false;
	vars->consumables_found = 0;
}

void	process_adjacent_nodes(int x, int y, t_game game, t_bfs_vars *vars)
{
	int	i;
	int	new_x;
	int	new_y;

	i = 0;
	while (i < 4)
	{
		new_x = x + vars->directions[i][0];
		new_y = y + vars->directions[i][1];
		if (is_valid(new_x, new_y, game.map, vars->visited))
		{
			vars->visited[new_x][new_y] = true;
			enqueue(&(vars->q), new_x, new_y);
		}
		i++;
	}
}

void	process_current_node(int x, int y, t_game game, t_bfs_vars *vars)
{
	if (game.map->tiles[x][y] == 'C')
		(vars->consumables_found)++;
	if (game.map->tiles[x][y] == 'E')
		vars->exit_found = true;
}

t_ok	bfs(t_game game)
{
	t_bfs_vars		vars;
	t_queue_node	*node;
	int				x;
	int				y;

	init_bfs_vars(&vars, game);
	while (vars.q.front != NULL)
	{
		node = dequeue(&(vars.q));
		x = node->x;
		y = node->y;
		free(node);
		process_current_node(x, y, game, &vars);
		process_adjacent_nodes(x, y, game, &vars);
	}
	free_visited(vars.visited, game.map->hauteur);
	return (vars.consumables_found == game.counter->c_count && vars.exit_found);
}
