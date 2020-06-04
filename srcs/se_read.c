/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:29:26 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/04 22:19:46 by eenasalorin      ###   ########.fr       */
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
