/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:25:00 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 15:06:49 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

void	set_images(t_graphics **graph)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/brique.png");
	img = mlx_texture_to_image((*graph)->mlx, texture);
	// TODO ERROR
	mlx_delete_texture(texture);
	(*graph)->tiles_img[0] = img;
	texture = mlx_load_png("./assets/echelle.png");
	img = mlx_texture_to_image((*graph)->mlx, texture);
	mlx_delete_texture(texture);
	(*graph)->tiles_img[1] = img;
	texture = mlx_load_png("./assets/fleur.png");
	img = mlx_texture_to_image((*graph)->mlx, texture);
	mlx_delete_texture(texture);
	(*graph)->tiles_img[2] = img;
	texture = mlx_load_png("./assets/planche.png");
	img = mlx_texture_to_image((*graph)->mlx, texture);
	(*graph)->tiles_img[3] = img;
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/tnt.png");
	img = mlx_texture_to_image((*graph)->mlx, texture);
	mlx_delete_texture(texture);
	(*graph)->tiles_img[4] = img;
}

static t_ok	imgs_to_window(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game.map->hauteur)
	{
		j = 0;
		while (j < game.map->largeur)
		{
			if (game.map->tiles[i][j] == '1')
				mlx_image_to_window(game.graphics->mlx, game.graphics->tiles_img[0], j * 32, i * 32);
			else if (game.map->tiles[i][j] == '0')
				mlx_image_to_window(game.graphics->mlx, game.graphics->tiles_img[3], j * 32, i * 32);
			else if (game.map->tiles[i][j] == 'C')
				mlx_image_to_window(game.graphics->mlx, game.graphics->tiles_img[2], j * 32, i * 32);
			else if (game.map->tiles[i][j] == 'E')
				mlx_image_to_window(game.graphics->mlx, game.graphics->tiles_img[1], j * 32, i * 32);
			else if (game.map->tiles[i][j] == 'P')
				mlx_image_to_window(game.graphics->mlx, game.graphics->tiles_img[4], j * 32, i * 32);
			j++;
		}
		i++;
	}
	return (E_OK);
}

void	new_graphics(t_game *game)
{
	t_graphics	*graphics;
	mlx_t		*mlx;

	graphics = ft_calloc(1, sizeof(t_graphics));
	mlx = NULL;
	mlx = mlx_init(512, 512, "So_lonng", true);
	graphics->mlx = mlx;
	set_images(&graphics);
	game->graphics = graphics;
	imgs_to_window(*game);
}

// void	get_img_instance_by_position(t_game *game, int y, int x)
// {
// 	*game->graphics->tiles_img
// }

void	free_graphics(t_graphics *graph)
{
	mlx_terminate(graph->mlx);
}
