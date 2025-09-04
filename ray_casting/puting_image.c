/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puting_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboussel <oboussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:13:46 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/03 16:26:21 by oboussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	my_pixel_put(t_cube *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || x >= data->width * TILE || y < 0 || y >= data->height * TILE)
		return ;
	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_wall(t_cube *data, double angle, int x)
{
	int				top;
	int				tex_y;
	unsigned int	color;
	int				i;

	i = 0;
	top = ((data->height * TILE) / 2) - (data->wallstriph / 2);
	get_texture_info(data, angle);
	while (i < data->height * TILE)
	{
		if (i >= top && i <= (data->height * TILE / 2) + (data->wallstriph / 2))
		{
			tex_y = (i - top) * (TEXTURE_TILE / data->wallstriph);
			color = get_color(data, data->t_text.index, data->t_text.tex_x,
					tex_y);
			my_pixel_put(data, x, i, color);
		}
		else if (i < top)
			my_pixel_put(data, x, i, data->game->ceiling_color);
		else
			my_pixel_put(data, x, i, data->game->floor_color);
		i++;
	}
}

void	draw_fov(t_cube *data)
{
	double	angle;
	double	angle_step;
	int		i;

	i = 0;
	angle = data->angle - (data->fov / 2);
	angle_step = data->fov / (data->width * TILE);
	while (i < data->width * TILE)
	{
		angle = normalizeangle(angle);
		wallstripheight(data, angle);
		draw_wall(data, angle, i);
		angle += angle_step;
		i++;
	}
}

void	render_all(t_cube *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->width * TILE, data->height
			* TILE);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len,
			&data->endian);
	draw_fov(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mini_map(data);
}
