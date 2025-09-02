/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WallDis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:14:06 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/01 11:34:05 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	horizontal_gridline(t_cube *data)
{
	data->dis->ahx = data->px;
	data->dis->ahy = data->py;
	data->dis->xhstep = INFINITY;
	data->dis->yhstep = INFINITY;
}

void	vertical_gridline(t_cube *data)
{
	data->dis->avx = data->px;
	data->dis->avy = data->py;
	data->dis->xvstep = INFINITY;
	data->dis->yvstep = INFINITY;
}

void	first_hori_intersect(t_cube *data, double angle)
{
	data->dis->ahy = floor(data->py / TILE) * TILE;
	if (lookdown(angle))
		data->dis->ahy += TILE;
	// we did this if it looking down because the y incrementing downward
	data->dis->ahx = data->px + ((data->dis->ahy - data->py) / tan(angle));
	data->dis->xhstep = TILE / tan(angle);
	data->dis->yhstep = TILE;
	if (lookup(angle)) // if looking UP y must be decremented
		data->dis->yhstep = -data->dis->yhstep;
	if (left(angle))
		data->dis->xhstep = -fabs(data->dis->xhstep);
	// if looking LEFT x must be decremented
	else
		data->dis->xhstep = fabs(data->dis->xhstep);
	// if looking RIGHT x must be incremented
	data->dis->hwallhitx = data->dis->ahx;
	data->dis->hwallhity = data->dis->ahy;
	if (lookup(angle))
		data->dis->hwallhity--;
}

void	first_vert_intersect(t_cube *data, double angle)
{
	data->dis->avx = floor(data->px / TILE) * TILE;
	if (right(angle))
		data->dis->avx += TILE;
	data->dis->avy = data->py + (data->dis->avx - data->px) * tan(angle);
	data->dis->xvstep = TILE;
	data->dis->yvstep = TILE * tan(angle);
	if (left(angle)) // if looking LEFT x must be decremented
		data->dis->xvstep = -data->dis->xvstep;
	if (lookup(angle))
		data->dis->yvstep = -fabs(data->dis->yvstep);
	// if looking UP y must be decremented
	else
		data->dis->yvstep = fabs(data->dis->yvstep);
	// if looking DOWN y must be incremeted
	data->dis->vwallhitx = data->dis->avx;
	data->dis->vwallhity = data->dis->avy;
	if (left(angle))
		data->dis->vwallhitx--;
}

void	find_distance(t_cube *data, double angle)
{
	if (fabs(sin(angle)) < 1e-6) // if the grid line vertical
		horizontal_gridline(data);
	else
		first_hori_intersect(data, angle);
	if (fabs(cos(angle)) < 1e-6) // if the grid line horizontal
		vertical_gridline(data);
	else
		first_vert_intersect(data, angle);
	wall_hit_cords(data);
	data->walldis = distance(data);
}
