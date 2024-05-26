/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:25:00 by antoinemura       #+#    #+#             */
/*   Updated: 2024/05/26 14:39:38 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long.h"

t_graphics	*new_graphics(int hauteur, int largeur)
{
	t_graphics	*graphics;
	mlx_t		*mlx;

	mlx = mlx_init(largeur, hauteur, "Test", true);
	graphics->mlx = NULL;
	set_images(graphics);
	return (graphics);
}

void	free_graphics(t_graphics *graph)
{
	mlx_terminate(graph->mlx);
}

void	set_images(t_graphics *graph)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/brique.png");
	img = mlx_texture_to_image(graph->mlx, texture);
	if (!img)
		error();
	mlx_delete_texture(texture);
	graph->tiles_img[0] = img;
	texture = mlx_load_png("./assets/echelle.png");
	img = mlx_texture_to_image(graph->mlx, texture);
	if (!img)
		error();
	mlx_delete_texture(texture);
	graph->tiles_img[1] = img;
	texture = mlx_load_png("./assets/fleur.png");
	img = mlx_texture_to_image(graph->mlx, texture);
	if (!img)
		error();
	mlx_delete_texture(texture);
	graph->tiles_img[2] = img;
	texture = mlx_load_png("./assets/planche.png");
	img = mlx_texture_to_image(graph->mlx, texture);
	if (!img)
		error();
	graph->tiles_img[3] = img;
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/tnt.png");
	img = mlx_texture_to_image(graph->mlx, texture);
	if (!img)
		error();
	mlx_delete_texture(texture);
	graph->tiles_img[4] = img;
}
