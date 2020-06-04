/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:39:53 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/04 16:57:09 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_width(int width)
{
	while (width--)
		ft_putchar_fd(' ', STDERR_FILENO);
}

void		se_print_list(t_select *se)
{
	int i;

	i = 0;
	ft_putchar_fd('\n', STDERR_FILENO);
	clear();
	check_windowsize(se);
	while (se->args[i])
	{
		if (i == se->cursor)
			ft_putstr_fd(UNDERLINE, STDERR_FILENO);
		if (se->selected[i])
		{
			ft_putstr_fd(BGWHITE, STDERR_FILENO);
			ft_putstr_fd(CBLACK, STDERR_FILENO);
		}
		if (se->files_per_row == 1)
			ft_putendl_fd(se->args[i], STDERR_FILENO);
		ft_putstr_fd(RESET, STDERR_FILENO);
		if (se->args[i + 1] && se->files_per_row > 1)
			print_width(se->max_len - (int)ft_strlen(se->args[i] + 1));
		i++;
	}
}
