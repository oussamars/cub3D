/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeftah- <imeftah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 10:13:00 by imeftah-          #+#    #+#             */
/*   Updated: 2025/09/02 13:31:09 by imeftah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	rotation(int key, t_cube *data)
{
	if (key == XK_Escape)
		ft_exit(data);
	if (key == XK_Right)
		data->angle += data->r_speed;
	if (key == XK_Left)
		data->angle -= data->r_speed;
}

void	up_down(int key, t_cube *data, double *x, double *y)
{
	if (key == XK_w)
	{
		*(x) += (MOVE * cos(data->angle));
		*(y) += (MOVE * sin(data->angle));
	}
	if (key == XK_s)
	{
		*(x) -= (MOVE * cos(data->angle));
		*(y) -= (MOVE * sin(data->angle));
	}
}

void	left_right(int key, t_cube *data, double *x, double *y)
{
	if (key == XK_a)
	{
		*(x) += sin(data->angle) * MOVE;
		*(y) -= cos(data->angle) * MOVE;
	}
	if (key == XK_d)
	{
		*(x) -= sin(data->angle) * MOVE;
		*(y) += cos(data->angle) * MOVE;
	}
}

int	key_check(int key, void *ptr)
{
	double	x;
	double	y;
	t_cube	*data;

	data = (t_cube *)ptr;
	x = data->px;
	y = data->py;
	rotation(key, data);
	left_right(key, data, &x, &y);
	up_down(key, data, &x, &y);
	if (colision(data, x, y) != -1)
	{
		data->px = x;
		data->py = y;
	}
	data->angle = normalizeangle(data->angle);
	render_all(data);
	return (0);
}
