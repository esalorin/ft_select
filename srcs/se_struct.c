/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:18:02 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/04 16:35:29 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			set_struct(t_select *se, char **av, int ac)
{
	if (!(se->args = ft_arraydup(av)))
		return (0);
	se->cursor = 0;
	if (!(se->selected = (int*)ft_memalloc(sizeof(int) * ac)))
		return (0);
	ft_bzero((void*)se->selected, ac);
	se->max_len = max_len(se->args);
	se->control = 0;
	return (1);
}
