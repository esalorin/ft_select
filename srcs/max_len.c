/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 17:13:58 by esalorin          #+#    #+#             */
/*   Updated: 2020/07/03 16:10:17 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	max_len(char **args)
{
	int	max_len;
	int	len;
	int	i;

	max_len = 0;
	len = 0;
	i = 0;
	while (args[i])
	{
		len = (int)ft_strlen(args[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}
