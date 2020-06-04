/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:36:01 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/04 20:10:28 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_select(t_select *se)
{
	char	buf[1024];

	set_rawmode(se);
	if (tgetent(buf, se->term) < 1)
		ft_putendl_fd("tgetent: entry/terminfo database could not be found", 2);
	se_print_list(se);
	se_read(se);
	clear();
	unset_rawmode(se);
	free_all(se);
}

int			main(int ac, char **av)
{
	t_select	se;

	if (ac > 1)
	{
		if (!(se.term = getenv("TERM")))
		{
			ft_putendl_fd("Set a terminal type: 'export TERM=<type>'",
			STDERR_FILENO);
			return (0);
		}
		if (set_struct(&se, &av[1], ac - 1))
			ft_select(&se);
		else
			ft_putendl_fd("Malloc error. Exiting.", 2);
	}
	else
		ft_putendl_fd("ft_select: usage: <command> './ft_select [arg1, ...]'",
		STDERR_FILENO);
	return (0);
}
