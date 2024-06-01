/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finishable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:00:42 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 23:10:13 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_ok	**init_visited(int hauteur, int largeur)
{
	t_ok	**visited;
	int		i;
	int		j;

	i = 0;
	visited = malloc(hauteur * sizeof(t_ok *));
	while (i < hauteur)
	{
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

void	enqueue(t_queue *q, int x, int y)
{
	t_queue_node	*new_node;

	new_node = malloc(sizeof(t_queue_node));
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	if (q->rear == NULL)
	{
		q->rear = new_node;
		q->front = new_node;
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

t_ok	is_finishable(t_game game)
{
	return (!bfs(game));
}
