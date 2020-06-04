/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 17:00:51 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/04 15:39:05 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	modify_selection_info(int *selected, int max)
{
	int i;

	i = 0;
	while (i + 1 < max)
	{
		selected[i] = selected[i + 1];
		i++;
	}
}

void		remove_item(t_select *se)
{
	char	**new_list;

	if (ft_arraylen(se->args) > 1)
	{
		new_list = ft_arrayrem(se->args, se->cursor);
		ft_arraydel(se->args);
		se->args = new_list;
		if (se->cursor == (int)ft_arraylen(se->args))
			se->cursor--;
		else
			modify_selection_info(&se->selected[se->cursor],
			ft_arraylen(se->args));
		se->max_len = max_len(se->args);
		se_print_list(se);
	}
	else
		se->control = ESC;
}
