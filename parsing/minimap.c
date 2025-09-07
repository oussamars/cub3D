/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:52:11 by oboussel          #+#    #+#             */
/*   Updated: 2025/09/06 16:37:41 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	draw_minimap_tile(t_cube *data, int pos_drawing_x, int pos_drawing_y,
		int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < 12)
	{
		i = 0;
		while (i < 12)
		{
			if ((j == 0 || i == 0) && color == 0x000000)
				mlx_pixel_put(data->mlx, data->win, pos_drawing_x + i,
					pos_drawing_y + j, 0xFFFFFF);
			else
				mlx_pixel_put(data->mlx, data->win, pos_drawing_x + i,
					pos_drawing_y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_player(t_cube *data, int pos_drawing_x, int pos_drawing_y,
		int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (j == 0 && color == 0x000000)
				mlx_pixel_put(data->mlx, data->win, pos_drawing_x + i,
					pos_drawing_y + j, 0xFFFFFF);
			else if (i == 0 && color == 0x000000)
				mlx_pixel_put(data->mlx, data->win, pos_drawing_x + i,
					pos_drawing_y + j, 0xFFFFFF);
			else
				mlx_pixel_put(data->mlx, data->win, pos_drawing_x + i,
					pos_drawing_y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_minimap_row(t_cube *data, int j, int map_j, int start_i)
{
	int (i), (map_i), (draw_x), (draw_y);
	i = 0;
	while (i < 9)
	{
		map_i = start_i + i;
		draw_x = i * 12;
		draw_y = j * 12;
		if (map_i >= 0 && map_i < (int)ft_strlen(data->map[map_j]))
		{
			if (player_or_zero(data->map[map_j][map_i]) == 1)
				draw_minimap_tile(data, draw_x, draw_y, 0xFFFFFF);
			else
				draw_minimap_tile(data, draw_x, draw_y, 0x000000);
		}
		else
			draw_minimap_tile(data, draw_x, draw_y, 0x333333);
		i++;
	}
}

static void	draw_out_of_bounds_row(t_cube *data, int j)
{
	int	i;
	int	draw_x;
	int	draw_y;

	i = 0;
	while (i < 9)
	{
		draw_x = i * 12;
		draw_y = j * 12;
		draw_minimap_tile(data, draw_x, draw_y, 0x333333);
		i++;
	}
}

void	mini_map(t_cube *data)
{
	int (j), (map_j), (player_x), (player_y), (tile_size), (start_i), (start_j),
		(player_draw_x), (player_draw_y);
	j = 0;
	tile_size = 12;
	player_x = data->px / TILE;
	player_y = data->py / TILE;
	start_i = player_x - 4;
	start_j = player_y - 4;
	while (j < 9)
	{
		map_j = start_j + j;
		if (map_j >= 0 && map_j < data->height)
			draw_minimap_row(data, j, map_j, start_i);
		else
			draw_out_of_bounds_row(data, j);
		j++;
	}
	player_draw_x = (4 * tile_size) + (tile_size / 2);
	player_draw_y = (4 * tile_size) + (tile_size / 2);
	draw_player(data, player_draw_x, player_draw_y, 0xFF0000);
}
