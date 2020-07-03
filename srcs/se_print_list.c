/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:39:53 by esalorin          #+#    #+#             */
/*   Updated: 2020/07/03 16:10:40 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_width(int width)
{
	while (width--)
		ft_putchar_fd(' ', STDERR_FILENO);
}

static int	print_cols(t_select *se, int i)
{
	int			col;
	static int	row;

	if (!row || i == 0)
		row = se->files_per_row;
	col = se->files_per_col;
	ft_putstr_fd(se->args[i], STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);
	se->printed[i] = 1;
	print_width(se->max_len - (int)ft_strlen(se->args[i] + 1));
	(!--row) ? ft_putchar_fd('\n', STDERR_FILENO) : 0;
	while (col--)
	{
		i++;
		if (!se->args[i])
		{
			i = 0;
			while (se->args[i] && se->printed[i])
				i++;
			break ;
		}
	}
	if (!se->args[i])
		return (ft_arraylen(se->args));
	return (i);
}

void		se_print_list(t_select *se)
{
	int i;

	i = 0;
	clear();
	ft_bzero((void*)se->printed, se->ac * sizeof(int));
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
		{
			ft_putendl_fd(se->args[i], STDERR_FILENO);
			ft_putstr_fd(RESET, STDERR_FILENO);
			i++;
		}
		else
			i = print_cols(se, i);
	}
}
