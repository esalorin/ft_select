/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_windowsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 15:56:32 by esalorin          #+#    #+#             */
/*   Updated: 2020/06/04 16:48:53 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	count_cols(struct winsize w, t_select *se, int list)
{
	if (list % w.ws_row)
		se->files_per_row = list / w.ws_row + 1;
	else
		se->files_per_row = list / w.ws_row;
	if (list % se->files_per_row)
		se->files_per_col = list / se->files_per_row + 1;
	else
		se->files_per_col = list / se->files_per_row;
	if (w.ws_col >= (se->files_per_row * se->max_len))
		return (0);
	return (1);
}

void		check_windowsize(t_select *se)
{
	struct winsize	w;
	int				list;

	list = ft_arraylen(se->args);
	while (ioctl(STDIN_FILENO, TIOCGWINSZ, &w) != -1)
	{
		if (w.ws_row >= list)
		{
			se->files_per_row = 1;
			se->files_per_col = list;
			return ;
		}
		else
		{
			if (count_cols(w, se, list))
				return ;
		}
		ft_putstr_fd("ft_select: not enough lines and/or columns", STDERR_FILENO);
	}
	ft_putstr_fd("ioctl(): an error occurred", STDERR_FILENO);
}
