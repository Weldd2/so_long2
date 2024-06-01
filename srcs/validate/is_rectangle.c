/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:42:11 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 23:10:13 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_ok	is_rectangle(t_game game)
{
	int	i;

	i = 0;
	while (i < game.map->hauteur)
	{
		if (game.map->tiles[i])
		{
			if (game.map->largeur != (int)ft_strlen(game.map->tiles[i]))
				return (g_eno = E_MAPEDGES, E_ERR);
		}
		i++;
	}
	return (E_OK);
}
