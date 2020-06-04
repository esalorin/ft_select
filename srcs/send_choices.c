/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_choices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 17:26:10 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/28 17:29:03 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	send_choices(t_select *se)
{
	int i;

	i = 0;
	while (se->args[i])
	{
		if (se->selected[i])
			ft_printf("%s ", se->args[i]);
		i++;
	}
	return (0);
}
