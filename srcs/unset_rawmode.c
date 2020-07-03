/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_rawmode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:27:40 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/07/03 15:39:34 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	unset_rawmode(t_select *se)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &se->original_mode) == -1)
		ft_putendl_fd("tcsetattr failed.. Exiting.", STDERR_FILENO);
	tputs(tgetstr("ve", NULL), 1, ft_putint_fd);
	tputs(tgetstr("te", NULL), 1, ft_putint_fd);
}
