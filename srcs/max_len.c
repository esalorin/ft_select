/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 17:13:58 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/28 17:41:55 by eenasalorin      ###   ########.fr       */
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