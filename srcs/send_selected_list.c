/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_selected_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 17:26:10 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/04 20:11:50 by eenasalorin      ###   ########.fr       */
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
