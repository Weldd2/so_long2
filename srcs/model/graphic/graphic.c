/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:25:00 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 19:36:20 by antoinemura      ###   ########.fr       */
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
	(*graph)->tiles_img[E_BRIQUE] = img;
	texture = mlx_load_png("./assets/echelle.png");
	img = mlx_texture_to_image((*graph)->mlx, texture);
	mlx_delete_texture(texture);
	(*graph)->tiles_img[E_ECHELLE] = img;
	texture = mlx_load_png("./assets/fleur.png");
	img = mlx_texture_to_image((*graph)->mlx, texture);
	mlx_delete_texture(texture);
	(*graph)->tiles_img[E_FLEUR] = img;
	texture = mlx_load_png("./assets/planche.png");
	img = mlx_texture_to_image((*graph)->mlx, texture);
	(*graph)->tiles_img[E_PLANCHE] = img;
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/tnt.png");
	img = mlx_texture_to_image((*graph)->mlx, texture);
	mlx_delete_texture(texture);
	(*graph)->tiles_img[E_TNT] = img;
}

static t_ok	imgs_to_window(t_game game)
{
	int			i;
	int			j;
	int32_t instance;

	i = 0;
	while (i < game.map->hauteur)
	{
		j = 0;
		while (j < game.map->largeur)
		{
			instance = mlx_image_to_window(game.graphics->mlx, game.graphics->tiles_img[E_PLANCHE], j * 32, i * 32);
			game.graphics->tiles_img[E_PLANCHE]->instances[instance].z = 1;
			if (game.map->tiles[i][j] == '1')
			{
				instance = mlx_image_to_window(game.graphics->mlx, game.graphics->tiles_img[E_BRIQUE], j * 32, i * 32);
				game.graphics->tiles_img[E_BRIQUE]->instances[instance].z = 2;
			}
			else if (game.map->tiles[i][j] == 'C')
			{
				instance =  mlx_image_to_window(game.graphics->mlx, game.graphics->tiles_img[E_FLEUR], j * 32, i * 32);
				game.graphics->tiles_img[E_FLEUR]->instances[instance].z = 3;
			}
			else if (game.map->tiles[i][j] == 'E')
			{
				instance = mlx_image_to_window(game.graphics->mlx, game.graphics->tiles_img[E_ECHELLE], j * 32, i * 32);
				game.graphics->tiles_img[E_ECHELLE]->instances[instance].z = 3;
			}
			else if (game.map->tiles[i][j] == 'P')
			{
				instance = mlx_image_to_window(game.graphics->mlx, game.graphics->tiles_img[E_TNT], j * 32, i * 32);
				game.graphics->tiles_img[E_TNT]->instances[instance].z = 4;
			}
			j++;
		}
		i++;
	}
	return (E_OK);
}

mlx_instance_t	*get_img_instance_by_position(t_game *game, int y, int x, t_bloc bloc)
{
	for (int j = 0; j < (int)game->graphics->tiles_img[bloc]->count; j++)
	{
		if (game->graphics->tiles_img[bloc]->instances[j].y - (y * 32) == 0 
			&& game->graphics->tiles_img[bloc]->instances[j].x - (x * 32)== 0)
		{
			return (&(game->graphics->tiles_img[bloc]->instances[j]));
		}
	}
	return (NULL);
}

void	new_graphics(t_game *game)
{
	t_graphics	*graphics;
	mlx_t		*mlx;

	graphics = ft_calloc(1, sizeof(t_graphics));
	mlx = NULL;
	mlx = mlx_init(512, 512, "So_long", true);
	graphics->mlx = mlx;
	set_images(&graphics);
	game->graphics = graphics;
	imgs_to_window(*game);
}

void	free_graphics(t_graphics *graph)
{
	mlx_terminate(graph->mlx);
}
