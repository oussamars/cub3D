/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gun_sky_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:55:05 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/07 14:21:37 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	put_gun(t_cube *data)
{
	int	x;
	int	color;
	int	y;
	int	px;
	int	py;

	x = 0;
	y = 0;
	py = WIN_HEIGHT - data->t_text.width[data->gun_index];
	while (y < data->t_text.height[data->gun_index])
	{
		x = 0;
		px = WIN_WIDTH / 2 - data->t_text.width[data->gun_index] / 2;
		while (x < data->t_text.width[data->gun_index])
		{
			color = get_color(data, data->gun_index, x, y);
			if ((unsigned int)color != 0xFF000000)
				my_pixel_put(data, px, py, color);
			px++;
			x++;
		}
		py++;
		y++;
	}
}

void	draw_sky(t_cube *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			color = get_color(data, 4, x, y);
			my_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}
