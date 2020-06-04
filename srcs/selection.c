/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:39:14 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/28 17:41:24 by eenasalorin      ###   ########.fr       */
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
