/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:39:53 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/28 21:11:32 by eenasalorin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_width(int width)
{
	while (width--)
		ft_putchar_fd(' ', 2);
}

void	se_print_list(t_select *se)
{
	int i;

	i = 0;
	tputs(tgetstr("cl", NULL), 1, ft_putint_fd);
	ft_putchar_fd('\n', 2);
	while (se->args[i])
	{
		if (i == se->cursor)
			ft_putstr_fd(UNDERLINE, STDERR_FILENO);
		if (se->selected[i])
			ft_putstr_fd(BGWHITE CBLACK, STDERR_FILENO);
		ft_putstr_fd(se->args[i], STDERR_FILENO);
		ft_putstr_fd(RESET, STDERR_FILENO);
		print_width(se->max_len - ft_strlen(se->args[i] + 1));
		i++;
	}
}
