/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 17:19:38 by esalorin          #+#    #+#             */
/*   Updated: 2020/07/03 16:09:40 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	free_all(t_select *se)
{
	ft_arraydel(se->args);
	ft_memdel((void**)&se->selected);
	ft_memdel((void**)&se->printed);
}
