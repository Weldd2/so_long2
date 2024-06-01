/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:59:09 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 20:44:30 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

t_ok	new_map(int fd, t_game *game, int nb_line)
{
	int		y;
	char	*line;
	
	if (fd < 0)
		return (E_ERR);
	game->map = ft_calloc(1, sizeof(t_map));
	game->map->tiles = ft_calloc(nb_line + 1, sizeof(char *));
	line = gnl_and_trim(fd);
	game->map->largeur = (int)ft_strlen(line);
	y = 0;
	while (line != NULL)
	{
		game->map->tiles[y] = ft_str_split_char(line);
		line = gnl_and_trim(fd);
		y++;
	}
	game->map->hauteur = y;
	return (free(line), E_OK);
}

void	free_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->hauteur)
	{
		free(map->tiles[y]);
		y++;
	}
	free(map->tiles);
	free(map);
}

