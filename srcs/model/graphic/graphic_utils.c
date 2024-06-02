/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:52:27 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/02 11:01:26 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

t_ok	imgs_to_window(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game.map->hauteur)
	{
		j = 0;
		while (j < game.map->largeur)
		{
			place_image(&game, j, i, E_PLANCHE);
			place_tile(&game, i, j);
			j++;
		}
		i++;
	}
	return (E_OK);
}

mlx_instance_t	*get_img_by_pos(t_game *game, int y, int x, t_bloc bloc)
{
	int	j;

	j = 0;
	while (j < (int)game->graphics->tiles_img[bloc]->count)
	{
		if (game->graphics->tiles_img[bloc]->instances[j].y - (y * 32) == 0
			&& game->graphics->tiles_img[bloc]->instances[j].x - (x * 32) == 0)
		{
			return (&(game->graphics->tiles_img[bloc]->instances[j]));
		}
		j++;
	}
	return (NULL);
}
