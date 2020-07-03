/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_rawmode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:27:40 by esalorin          #+#    #+#             */
/*   Updated: 2020/07/03 16:11:44 by esalorin         ###   ########.fr       */
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
