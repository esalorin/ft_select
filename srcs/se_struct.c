/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:18:02 by esalorin          #+#    #+#             */
/*   Updated: 2020/07/03 16:11:01 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			se_struct(t_select *se, char **av, int ac)
{
	if (!(se->args = ft_arraydup(av)))
		return (0);
	se->cursor = 0;
	if (!(se->selected = (int*)ft_memalloc(sizeof(int) * ac)))
		return (0);
	if (!(se->printed = (int*)ft_memalloc(sizeof(int) * ac)))
		return (0);
	ft_bzero((void*)se->selected, sizeof(int) * ac);
	ft_bzero((void*)se->printed, sizeof(int) * ac);
	se->ac = ac;
	se->max_len = max_len(se->args);
	se->control = 0;
	g_select = se;
	return (1);
}
