/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:05:23 by jtaylor           #+#    #+#             */
/*   Updated: 2018/11/07 08:46:39 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Headers 
*/

/*	Print_Usage_Msg
**		Displays the proper usage of the executable if the wrong parameters are 
**		given as inputs. 
**
**		takes the executable name as paramater;
*/

void	print_usage_msg(const chat *prog_name)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd(prog_name, STDERR_FILENO);
	ft_putstr_fd(" [input_file]\n", STDERR_FILENO);
}

/*	main
**	checks if right # of arguments are then runs the function solve 
**	if !(solve)  write th string error to the standard output
*/

int		main(int ac, char **argv)
{
	if (argc != 2)
	{
		print_usage_msg(argv[0]);
		return (1);
	}
	if (!solve(argv[1]))
		write(1, "error\n", 6);
	return (0);
}
