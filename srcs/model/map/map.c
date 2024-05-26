/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:59:09 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 16:19:54 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

t_map	*new_map(int hauteur, int largeur)
{
	int		y;
	t_map	*map;

	y = 0;
	map = ft_calloc(1, sizeof(t_map *));
	map->hauteur = hauteur;
	map->largeur = largeur;
	map->tiles = ft_calloc(hauteur, sizeof(int *));
	while (y < hauteur)
	{
		map->tiles[y] = ft_calloc(largeur, sizeof(int));
		y++;
	}
	return (map);
}

int	fill_map(char *filename, t_map *map)
{
	int		fd;
	int		x;
	int		y;
	char	*line;

	y = 0;
	fd = open(filename, O_RDONLY);
	while (y < map->hauteur)
	{
		x = 0;
		line = gnl_and_trim(fd);
		while (line != NULL && x < map->largeur)
		{
			map->tiles[y][x] = line[x];
			x++;
		}
		y++;
	}
	return (free(line), close(fd), E_OK);
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

