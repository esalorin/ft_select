/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:39:14 by esalorin          #+#    #+#             */
/*   Updated: 2020/07/03 16:11:07 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	selection(t_select *se)
{
	if (se->selected[se->cursor] == 1)
		se->selected[se->cursor] = 0;
	else if (se->selected[se->cursor] == 0)
		se->selected[se->cursor] = 1;
	se->cursor++;
	if (se->cursor == (int)ft_arraylen(se->args))
		se->cursor = 0;
	se_print_list(se);
}
