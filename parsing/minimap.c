#include "../cube.h"

void	draw_rectangle(t_cube *data, int pos_drawing_x, int pos_drawing_y,
		int tile_size ,int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < tile_size)
	{
		i = 0;
		while (i < tile_size)
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

void	draw_mini_map(t_cube *data, int j, int map_j, int start_i)
{
	int(i), (map_i), (draw_x), (draw_y);
	i = 0;
	while (i < 9)
	{
		map_i = start_i + i;
		draw_x = i * 12;
		draw_y = j * 12;
		if (map_i >= 0 && map_i < (int)ft_strlen(data->map[map_j]))
		{
			if (player_or_zero(data->map[map_j][map_i]) == 1)
				draw_rectangle(data, draw_x, draw_y, 12, 0xFFFFFF);
			else
				draw_rectangle(data, draw_x, draw_y, 12, 0x000000);
		}
		else
			draw_rectangle(data, draw_x, draw_y, 12, 0x333333);
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
		draw_rectangle(data, draw_x, draw_y, 12, 0x333333);
		i++;
	}
}

void	mini_map(t_cube *data)
{
	int(j), (map_j), (player_x), (player_y), (tile_size), (start_i), (start_j),
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
			draw_mini_map(data, j, map_j, start_i);
		else
			draw_out_of_bounds_row(data, j);
		j++;
	}
	player_draw_x = (4 * tile_size) + (tile_size / 2);
	player_draw_y = (4 * tile_size) + (tile_size / 2);
	draw_rectangle(data, player_draw_x, player_draw_y, 4, 0xFF0000);
}
