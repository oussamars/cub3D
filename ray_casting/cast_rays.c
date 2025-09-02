/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:12:24 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/02 11:46:05 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	wallstripheight(t_cube *data, double angle)
{
	double	pp_dis;
	double	correcteddistance;

	find_distance(data, angle);
	correcteddistance = data->walldis * cos(angle - data->angle);
	pp_dis = ((data->width * TILE) / 2) / tan(data->fov / 2);
	data->wallstriph = (TILE / correcteddistance) * pp_dis;
}
