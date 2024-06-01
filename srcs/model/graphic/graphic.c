/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:25:00 by antoinemura       #+#    #+#             */
/*   Updated: 2024/06/01 23:10:13 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	set_images(t_graphics **graph)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/brique.png");
	img = mlx_texture_to_image((*graph)->mlx, texture);
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

static void	place_image(t_game *game, int x, int y, t_bloc img_type)
{
	int32_t		instance;
	int			z_index;
	mlx_image_t	*image;

	image = game->graphics->tiles_img[img_type];
	if (img_type == E_PLANCHE)
		z_index = 1;
	if (img_type == E_BRIQUE)
		z_index = 2;
	else if (img_type == E_FLEUR)
		z_index = 3;
	else if (img_type == E_ECHELLE)
		z_index = 3;
	else if (img_type == E_TNT)
		z_index = 4;
	instance = mlx_image_to_window(game->graphics->mlx, image, x * 32, y * 32);
	game->graphics->tiles_img[img_type]->instances[instance].z = z_index;
}

static void	place_tile(t_game *game, int i, int j)
{
	if (game->map->tiles[i][j] == '1')
	{
		place_image(game, j, i, E_BRIQUE);
	}
	else if (game->map->tiles[i][j] == 'C')
	{
		place_image(game, j, i, E_FLEUR);
	}
	else if (game->map->tiles[i][j] == 'E')
	{
		place_image(game, j, i, E_ECHELLE);
	}
	else if (game->map->tiles[i][j] == 'P')
	{
		place_image(game, j, i, E_TNT);
	}
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
	free(graph);
}
