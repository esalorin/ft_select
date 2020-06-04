/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:29:26 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/28 17:59:56 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	se_read(t_select *se)
{
	while (read(STDIN_FILENO, &se->control, 4) > 0)
	{
		if (!inspect_controls(se))
			return ;
		se->control = 0;
	}
}
