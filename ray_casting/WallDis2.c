/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WallDis2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:14:14 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/01 11:55:55 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

double	normalizeangle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

double	distance(t_cube *data)
{
	double	h_dis;
	double	v_dis;

	h_dis = sqrt((data->dis->hwallhitx - data->px) * (data->dis->hwallhitx
				- data->px) + (data->dis->hwallhity - data->py)
			* (data->dis->hwallhity - data->py));
	v_dis = sqrt((data->dis->vwallhitx - data->px) * (data->dis->vwallhitx
				- data->px) + (data->dis->vwallhity - data->py)
			* (data->dis->vwallhity - data->py));
	if (h_dis < v_dis)
	{
		data->hit_check = HORZ;
		return (h_dis);
	}
	else
	{
		data->hit_check = VERT;
		return (v_dis);
	}
}

void	wall_hit_cords(t_cube *data)
{
	while (data->dis->hwallhitx >= 0 && data->dis->hwallhitx <= data->width
		* TILE && data->dis->hwallhity >= 0
		&& data->dis->hwallhity <= data->height * TILE)
	{
		if (colision(data, data->dis->hwallhitx, data->dis->hwallhity) == -1)
			break ;
		data->dis->hwallhitx += data->dis->xhstep;
		data->dis->hwallhity += data->dis->yhstep;
	}
	while (data->dis->vwallhitx >= 0 && data->dis->vwallhitx <= data->width
		* TILE && data->dis->vwallhity >= 0
		&& data->dis->vwallhity <= data->height * TILE)
	{
		if (colision(data, data->dis->vwallhitx, data->dis->vwallhity) == -1)
			break ;
		data->dis->vwallhitx += data->dis->xvstep;
		data->dis->vwallhity += data->dis->yvstep;
	}
}
