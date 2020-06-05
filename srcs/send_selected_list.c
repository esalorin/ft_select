/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_selected_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 17:26:10 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/05 14:03:24 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	send_selected_list(t_select *se)
{
	int i;

	i = 0;
	clear();
	while (se->args[i])
	{
		if (se->selected[i])
			ft_printf("%s ", se->args[i]);
		i++;
	}
	return (0);
}
