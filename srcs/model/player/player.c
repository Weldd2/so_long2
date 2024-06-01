/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:06:05 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 20:37:43 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	new_player(t_game *game)
{
	t_player	*player;
	int			i;
	int			j;

	player = ft_calloc(1, sizeof(t_player));
	player->p_y = -1;
	player->p_x = -1;
	i = 0;
	while (i < game->map->hauteur)
	{
		j = 0;
		while (j < game->map->largeur)
		{
			if (game->map->tiles[i][j] == 'P')
			{
				player->p_x = j;
				player->p_y = i;
			}
			j++;
		}
		i++;
	}
	game->player = player;
}

void	free_player(t_player *player)
{
	free(player);
}

