/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 17:36:27 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/02 16:29:45 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rmchr(char *s, int c)
{
	char	*des;
	int		i;
	int		j;

	i = 0;
	j = ft_chrcount(s, c);
	if (!(des = (char*)malloc(sizeof(char) * (ft_strlen(s) - j))))
		return (NULL);
	j = 0;
	while (s && s[i])
	{
		if (s[i] != c)
			des[j++] = s[i];
		i++;
	}
	des[j] = '\0';
	return (des);
}
