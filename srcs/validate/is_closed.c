/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:00:08 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 23:10:13 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	is_line_closed(char *line)
{
	int	len;
	int	i;

	i = 0;
	if (line == NULL)
		return (-1);
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] != '1')
			return (E_ERR);
		i++;
	}
	return (E_OK);
}

t_ok	is_closed(t_game game)
{
	int	i;

	i = 1;
	if (is_line_closed(game.map->tiles[0]))
		return (g_eno = E_MAPEDGES, E_ERR);
	if (is_line_closed(game.map->tiles[game.map->hauteur - 1]))
		return (g_eno = E_MAPEDGES, E_ERR);
	while (i < game.map->hauteur)
	{
		if (game.map->tiles[i][0] != '1')
			return (g_eno = E_MAPEDGES, E_ERR);
		if (game.map->tiles[i][game.map->largeur - 1] != '1')
			return (g_eno = E_MAPEDGES, E_ERR);
		i++;
	}
	return (E_OK);
}
