/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:18:49 by jtaylor           #+#    #+#             */
/*   Updated: 2018/11/19 10:04:38 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**make_square_str(size_t size)
{
	char	**square;
	size_t	i;

	if ((square = (char **)ft_memalloc((sizeof(*square) * (size + 1)))))
	{
		i = 0;
		while (i < size)
		{
			if (!(square[i] = ft_strnew(size)))
			{
				while (--i)
					ft_strdel(&square[i]);
				free(square);
				return (NULL);
			}
			ft_memset(square[i++], '.', size);
		}
	}
	return (square);
}

void		free_square(t_square **square)
{
	size_t row;

	if (!square)
		return ;
	row = 0;
	while (row < (*square)->size)
		ft_strdel(&((*square)->rows[row++]));
	free((*square)->rows);
	(*square)->rows = NULL;
	free(*square);
	*square = NULL;
}

void		update_square(t_square **square, char **rows)
{
	size_t row;

	row = 0;
	while (row < (*square)->size)
		ft_strdel(&((*square)->rows[row++]));
	(*square)->rows = rows;
}

t_square	*create_square(size_t size)
{
	t_square *square;

	if ((square = (t_square *)ft_memalloc(sizeof(*square))))
	{
		if (!(square->rows = make_square_str(size)))
		{
			free(square);
			return (NULL);
		}
		square->size = size;
	}
	return (square);
}
