/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:40:05 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/04 15:37:09 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_cursor(t_select *se)
{
	if (se->control == LEFT)
	{
		se->cursor--;
		if (se->cursor < 0)
			se->cursor = (int)ft_arraylen(se->args) - 1;
	}
	else if (se->control == RIGHT)
	{
		se->cursor++;
		if (se->cursor == (int)ft_arraylen(se->args))
			se->cursor = 0;
	}
	se_print_list(se);
}
