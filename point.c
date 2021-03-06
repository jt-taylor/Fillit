/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:50:03 by jtaylor           #+#    #+#             */
/*   Updated: 2018/11/19 10:05:31 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		*creat_point(int len)
{
	t_point	*point;

	if ((point = (t_point *)ft_memalloc(sizeof(*point))))
	{
		point->x = len % 5;
		point->y = ((len + 5) / 5);
		if (point->y > 0)
			point->y -= 1;
	}
	return (point);
}

void		free_point(t_point **point)
{
	if (!point)
		return ;
	free(*point);
	*point = NULL;
}

void		free_minmax_points(t_point ***points)
{
	if (!points)
		return ;
	free_point(*points + 1);
	free_point(*points);
	free(*points);
	*points = NULL;
}
