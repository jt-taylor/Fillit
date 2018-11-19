/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:09:01 by jtaylor           #+#    #+#             */
/*   Updated: 2018/11/19 10:03:19 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** print usage message if wrong num parameters are given
*/

void	print_usage(char const *prog_name)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd(prog_name, STDERR_FILENO);
	ft_putstr_fd(" [input_file]\n", STDERR_FILENO);
}

int		main(int ac, char **argv)
{
	if (ac != 2)
	{
		print_usage(argv[0]);
		return (1);
	}
	if (!solve(argv[1]))
		write(1, "error\n", 6);
	return (0);
}
