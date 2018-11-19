/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:14:50 by jtaylor           #+#    #+#             */
/*   Updated: 2018/11/19 10:04:22 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_next_point(t_point **point, char **square)
{
	if (!square)
		return (0);
	(*point)->x = (*point)->x + 1;
	while (square[(*point)->y] != NULL)
	{
		while (square[(*point)->y][(*point)->x] != '\0')
		{
			if (square[(*point)->y][(*point)->x] == '.')
				return (1);
			(*point)->x = (*point)->x + 1;
		}
		(*point)->y = (*point)->y + 1;
		(*point)->x = 0;
	}
	return (0);
}

int		solve_a_square(t_square *square, t_list **block, t_point *p_start)
{
	int found;

	found = 0;
	if (!block || !*block)
		return (1);
	while (!(found = check_tetrimino_fits((t_tetri *)(*block)->content,
					square, p_start)) && get_next_point(&p_start, square->rows))
		;
	if (!found)
		return (0);
	place_a_tetrimino((t_tetri *)(*block)->content, square, p_start);
	if (!solve_a_square(square, &((*block)->next), creat_point(0)))
	{
		remove_a_tetrimino((t_tetri *)(*block)->content, square);
		if (!get_next_point(&p_start, square->rows))
		{
			p_start->x = 0;
			p_start->y = 0;
			return (0);
		}
		return (solve_a_square(square, block, p_start));
	}
	return (1);
}

int		solve_squares(t_list **tetri_list)
{
	t_square	*square;
	t_point		*p_start;
	t_list		*tetri_list_tail;
	size_t		square_size;

	square_size = 2;
	if (!(square = create_square(square_size)))
		return (0);
	if (!(p_start = creat_point(0)))
		return (0);
	while ((tetri_list_tail = *tetri_list) &&
			!solve_a_square(square, &tetri_list_tail, p_start))
	{
		free_square(&square);
		if (!(square = create_square(++square_size)))
			return (0);
		p_start->x = 0;
		p_start->y = 0;
	}
	ft_putstrarr(square->rows);
	free_square(&square);
	free(square);
	return (1);
}

/*
** 	Solve :
** 		returns 1 if both get_tetriminos from file and solve_squares return
**		non zero (no error)
**		otherwise	:	return (0) to main which will print "error\n" to stdout
*/

int		solve(char const *filename)
{
	t_list	*tetri_list;

	if (!(tetri_list = get_tetris_pieces_from_file(filename)))
		return (0);
	if (!solve_squares(&tetri_list))
		return (0);
	return (1);
}
