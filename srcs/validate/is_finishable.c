/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finishable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:00:42 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/31 16:00:21 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_ok	**init_visited(int hauteur, int largeur)
{
	t_ok	**visited;
	int		i;
	int		j;
	
	i = 0;
	visited = malloc(hauteur * sizeof(t_ok *));
	while (i < hauteur) {
		visited[i] = malloc(largeur * sizeof(t_ok));
		j = 0;
		while (j < largeur)
		{
			visited[i][j] = false;
			j++;
		}
		i++;
	}
	return (visited);
}

void	free_visited(t_ok **visited, int hauteur)
{
	int	i;

	i = 0;
	while (i < hauteur)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

typedef struct s_queue_node {
	int x, y;
	struct s_queue_node *next;
} t_queue_node;

typedef struct s_queue {
	t_queue_node *front, *rear;
} t_queue;

void	enqueue(t_queue *q, int x, int y)
{
	t_queue_node	*new_node;
	
	new_node = malloc(sizeof(t_queue_node));
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	if (q->rear == NULL)
	{
		q->front = q->rear = new_node;
		return ;
	}
	q->rear->next = new_node;
	q->rear = new_node;
}

t_queue_node	*dequeue(t_queue *q)
{
	t_queue_node	*temp;

	if (q->front == NULL)
		return (NULL);
	temp = q->front;
	q->front = q->front->next;
	if (q->front == NULL)
		q->rear = NULL;
	return (temp);
}

t_ok	is_valid(int x, int y, t_map *map, t_ok **visited)
{
	return (x >= 0 && x < map->hauteur && y >= 0 && y < map->largeur &&
			 map->tiles[x][y] != '1' && !visited[x][y]);
}

t_ok bfs(t_game *game)
{
	int		directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int		i;
	t_ok	**visited;
	t_queue q = {NULL, NULL};
	int 	consumables_found;
	t_ok	exit_found;

	enqueue(&q, game->player->p_y, game->player->p_x);
	visited = init_visited(game->map->hauteur, game->map->largeur);
	visited[game->player->p_y][game->player->p_x] = true;
	exit_found = false;
	consumables_found = 0;
	while (q.front != NULL)
	{
		t_queue_node *node = dequeue(&q);
		int x = node->x, y = node->y;
		free(node);
		if (game->map->tiles[x][y] == 'C')
			consumables_found++;
		if (game->map->tiles[x][y] == 'E')
			exit_found = true;
		i = 0;
		while (i < 4)
		{
			int new_x = x + directions[i][0];
			int new_y = y + directions[i][1];
			if (is_valid(new_x, new_y, game->map, visited)) {
				visited[new_x][new_y] = true;
				enqueue(&q, new_x, new_y);
			}
			i++;
		}
	}
	free_visited(visited, game->map->hauteur);
	return (consumables_found == game->counter->c_count && exit_found);
}

static t_ok backtrack(t_game *game) {
	if (bfs(game)) {
		return (E_OK);
	} else {
		return (E_ERR);
	}
}

t_ok	is_finishable(t_game *game)
{
	t_map		map;
	t_player	p;
	t_counter	counter;
	t_ok		ret;

	map = *(game->map);
	p = *(game->player);
	counter = *(game->counter);
	ret = backtrack(game);
	free_map(game->map);
	free_player(game->player);
	free_counter(game->counter);
	return (game->map = &map, game->player = &p, game->counter = &counter, ret);
}
