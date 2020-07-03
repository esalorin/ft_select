/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_selected_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 17:26:10 by esalorin          #+#    #+#             */
/*   Updated: 2020/07/03 16:11:15 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	send_selected_list(t_select *se)
{
	int i;

	i = 0;
	while (se->args[i])
	{
		if (se->selected[i])
			ft_printf("%s ", se->args[i]);
		i++;
	}
}
