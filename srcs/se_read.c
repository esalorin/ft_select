/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:29:26 by esalorin          #+#    #+#             */
/*   Updated: 2020/07/03 16:10:51 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	se_read(t_select *se)
{
	se->control = 0;
	while (read(STDIN_FILENO, &se->control, 4) > 0)
	{
		if (!inspect_controls(se))
			return ;
		se->control = 0;
	}
}
