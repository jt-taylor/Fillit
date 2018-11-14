/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetriminoes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:20:06 by jtaylor           #+#    #+#             */
/*   Updated: 2018/11/11 17:56:45 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillet_header_master.h"

int		validate_new_lines(char *tetrimino_str, int *end_in_newline)
{
	int	new_line_placement;

	new_line_placement = TETRI_SIZE - 1;
	while  (new_line_placement > 0)
	{
		if (tetrimino_str[new_line_placement] != '\n')
			return (-1);
		new_line_placement -= 5;
	}
	if (tetrimino_str[TETRI_SIZE] != '\n' && tetrimino_str[TETRI_SIZE] != '\0')
		return (-1);
	if (tetrimino_str[TETRI_SIZE] != '\0')
		*ends_in_newline = 1;
	else
		*ends_in_newline = 0;
	return (0);
}
}

int		check_valid_num_pieces(int count)
{
	if (count > 26 || count < 0)
		return (-1);
	return (0);
}

t_list	*read_tetriminos(int fd)
{
	char	*tetrimino_str;
	int		end_in_newline;
	int		tetri_cnt;
	t_list	*tail;
	t_list	*head;

	tetrimino_str = ft_strnew(TETRI_SIZE + 1);
	tetri_cnt = 0;
	while (read(fd, tetrimino_str, (TETRI_SIE + 1)))
	{
		if (validate_newline(tetrimino_str, &ends_in_newline) == -1 ||
				check_valid_num_pieces(tetri_cnt + 1) == -1)
			return (NULL);
		tetrimino_str[TETRI_SIZE] = '\0';
		if //(lstadd_tetri(&head, &tail, tetrimino_str, tetri_cnt) == -1)
			// return (NULL);
		ft_bzero(tetrimino_str, TETRI_SIZE + 1);
		tetri_cnt++;
	}
	ft_strdel(&tetrimino_str);
	if (tetri_cnt == 0 || ends_in_newline == 1)
		return (NULL);
	return (head);
}

t_list	*get_tetris_pieces_from_file(char const *filename)
{
	int fd;
	t_list	*tetri_list;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
	if //(!(tetri_list = read_tetriminoes(fd)))
	{
		close(fd);
		return (NULL);
	}
	if ((close(fd) == -1))
		return (NULL);
	return (tetri_list);
}
