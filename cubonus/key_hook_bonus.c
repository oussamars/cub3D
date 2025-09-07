/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 09:57:59 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/07 14:20:15 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	colision(t_cube *data, int px, int py)
{
	int	map_x;
	int	map_y;

	map_x = px / TILE;
	map_y = py / TILE;
	if (map_y < 0 || map_y > data->height)
		return (ERROR);
	if (map_x < 0 || map_x >= (int)ft_strlen(data->map[map_y]))
		return (ERROR);
	if (data->map[map_y][map_x] == '1')
		return (ERROR);
	return (0);
}

int	key_press(int key, void *ptr)
{
	t_cube	*data;

	data = (t_cube *)ptr;
	if (key == XK_Escape)
		ft_exit(data);
	if (key == XK_space)
		data->key.space = TRUE;
	if (key == XK_Right)
		data->key.rotate_right = TRUE;
	if (key == XK_Left)
		data->key.rotate_left = TRUE;
	if (key == XK_w)
		data->key.up = TRUE;
	if (key == XK_s)
		data->key.down = TRUE;
	if (key == XK_a)
		data->key.left = TRUE;
	if (key == XK_d)
		data->key.right = TRUE;
	return (0);
}

int	key_release(int key, void *ptr)
{
	t_cube	*data;

	data = (t_cube *)ptr;
	if (key == XK_space)
		data->key.space = FALSE;
	if (key == XK_Right)
		data->key.rotate_right = FALSE;
	if (key == XK_Left)
		data->key.rotate_left = FALSE;
	if (key == XK_w)
		data->key.up = FALSE;
	if (key == XK_s)
		data->key.down = FALSE;
	if (key == XK_a)
		data->key.left = FALSE;
	if (key == XK_d)
		data->key.right = FALSE;
	return (0);
}

int	mouse_func(int x, int y, t_cube *data)
{
	int	dx;

	(void)y;
	dx = x - (WIN_WIDTH / 2);
	if (dx == 0)
		return (0);
	data->angle += dx * data->r_speed;
	data->angle = normalizeangle(data->angle);
	mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
