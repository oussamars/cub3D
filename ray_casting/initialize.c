/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:12:43 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/02 13:31:20 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	get_window_size(t_cube *data, char *path)
{
	int	y;
	int	x;
	int	tmp;

	y = 0;
	while (data->map[y])
	{
		data->width = ft_strlen(data->map[0]);
		data->height++;
		y++;
	}
	return (0);
}

int	store_map(t_cube *data, char *path)
{
	int		fd;
	char	*buffer;
	int		i;

	i = 0;
	data->map = malloc((data->height + 1) * sizeof(char *));
	if (!data->map)
		return (ERROR);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		data->map[i++] = buffer;
	}
	data->map[i] = NULL;
	close(fd);
	return (0);
}

void	load_textures(t_cube *data)
{
	int	i;

	i = 0;
	data->t_text.textures[0] = mlx_xpm_file_to_image(data->mlx,
			data->game->north_texture, &data->t_text.width[0],
			&data->t_text.height[0]);
	data->t_text.textures[1] = mlx_xpm_file_to_image(data->mlx,
			data->game->south_texture, &data->t_text.width[1],
			&data->t_text.height[1]);
	data->t_text.textures[2] = mlx_xpm_file_to_image(data->mlx,
			data->game->east_texture, &data->t_text.width[2],
			&data->t_text.height[2]);
	data->t_text.textures[3] = mlx_xpm_file_to_image(data->mlx,
			data->game->west_texture, &data->t_text.width[3],
			&data->t_text.height[3]);
	data->t_text.textures[4] = NULL;
	while (i < 4)
	{
		data->t_text.addr[i] = mlx_get_data_addr(data->t_text.textures[i],
				&data->t_text.bpp[i], &data->t_text.len[i],
				&data->t_text.endian[i]);
		i++;
	}
}

void	initialize(t_cube *data, char *path)
{
	int	i;

	data->map = data->game->map;
	if (get_window_size(data, path) == ERROR)
		ft_exit(data);
	data->fov = 60 * (M_PI / 180);
	data->angle = 0 * (M_PI / 180);
	data->px = data->game->player_x * TILE;
	data->py = data->game->player_y * TILE;
	data->r_speed = 5 * (M_PI / 180);
	data->dis = ft_malloc(sizeof(t_dis_tools), ALLOC);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width * TILE, data->height
			* TILE, "cub3D");
	load_textures(data);
}
