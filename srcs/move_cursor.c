/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:40:05 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/28 18:00:30 by eenasalorin      ###   ########.fr       */
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
