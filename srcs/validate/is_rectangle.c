/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:42:11 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/30 17:21:44 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_ok	is_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->hauteur)
	{
		if (game->map->tiles[i])
		{
			if (game->map->largeur != (int)ft_strlen(game->map->tiles[i]))
				return (g_eno = E_MAPEDGES, E_ERR);
		}
		i++;
	}
	return (E_OK);
}
