/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:05:17 by jtaylor           #+#    #+#             */
/*   Updated: 2018/11/19 10:03:33 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	check if points are empty, return a value to shift in the x
*/

int		tetrimino_x(t_tetri *tetri)
{
	int	x_shift;

	x_shift = 0;
	while ((tetri->shape)[0][x_shift] == '.')
	{
		x_shift++;
	}
	return (x_shift);
}

/*
** checks if tetris piece's size will overflow the board
** return (1) or (0) if it overflows the board
*/

int		check_tetrimino_max(t_tetri *tetrimino, t_square *square,
					t_point *point)
{
	if ((point->y + tetrimino->height <= (int)square->size) &&
			(point->x - tetrimino_x(tetrimino) + tetrimino->width <=
			(int)square->size))
		return (1);
	return (0);
}

/*
** checks if a tetrimino will fit at a given board point,
** return (1) or if it doesn't fit return (NULL);
*/

int		check_tetrimino_fits(t_tetri *tetrimino, t_square *square,
					t_point *point)
{
	int		x;
	int		y;
	char	**tetri_shape;
	char	**str_square;

	tetri_shape = tetrimino->shape;
	str_square = square->rows;
	if (check_tetrimino_max(tetrimino, square, point) != 1)
		return (0);
	y = 0;
	while (tetri_shape[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (!(str_square[y + point->y][x - tetrimino_x(tetrimino) +
				point->x] == '.' ||
				tetri_shape[y][x] == '.'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/*
** draws a tetrimmino on a square board , the top left corner of the
** tetrimino is at the point , drawn with the letter specidied
*/

void	place_a_tetrimino(t_tetri *tetrimino, t_square *square,
							t_point *point)
{
	int		x;
	int		y;
	char	**tetri_shape;
	char	**str_square;

	y = 0;
	tetri_shape = tetrimino->shape;
	str_square = square->rows;
	while (tetri_shape[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (tetri_shape[y][x] != '.')
			{
				str_square[y + point->y][x - tetrimino_x(tetrimino) +
				point->x] = tetri_shape[y][x];
			}
			x++;
		}
		y++;
	}
	tetrimino->start->x = (point->x) - tetrimino_x(tetrimino);
	tetrimino->start->y = point->y;
}

/*
** removes a tetrimino from the board
*/

void	remove_a_tetrimino(t_tetri *tetrimino, t_square *square)
{
	int		x;
	int		y;
	char	**tetri_shape;
	char	**str_square;

	y = 0;
	tetri_shape = tetrimino->shape;
	str_square = square->rows;
	while ((tetrimino->shape)[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (tetri_shape[y][x] != '.')
			{
				str_square[y + tetrimino->start->y]
				[x + tetrimino->start->x] = '.';
			}
			x++;
		}
		y++;
	}
}
