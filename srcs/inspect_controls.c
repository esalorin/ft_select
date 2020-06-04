/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:38:07 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/04 20:17:37 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	inspect_controls(t_select *se)
{
	if (se->control == SPACE)
		selection(se);
	else if (se->control == ENTER)
		return (send_selected_list(se));
	else if (se->control == BSPACE || se->control == DELETE)
		remove_item(se);
	else if (se->control == LEFT || se->control == RIGHT ||
	se->control == UP || se->control == DOWN)
		move_cursor(se);
	if (se->control == ESC)
	{
		clear();
		return (0);
	}
	return (1);
}
