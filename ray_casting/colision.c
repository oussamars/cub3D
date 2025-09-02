/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboussel <oboussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:12:35 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/02 15:50:49 by oboussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	colision(t_cube *data, int px, int py)
{
	int	map_x;
	int	map_y;

	map_x = px / TILE;
	map_y = py / TILE;
	if (map_y < 0 || map_y >= data->height || map_x < 0 || map_x >= data->width
		|| map_x > ft_strlen(data->map[map_y]))
		return (ERROR);
	if (data->map[map_y][map_x] == '1')
		return (ERROR);
	return (0);
}
