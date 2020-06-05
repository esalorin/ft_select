/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:40:05 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/05 15:22:52 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	move_down(t_select *se)
{
	se->cursor++;
	if (se->cursor == (int)ft_arraylen(se->args))
		se->cursor = 0;
}

static void	move_up(t_select *se)
{
	se->cursor--;
	if (se->cursor < 0)
		se->cursor = (int)ft_arraylen(se->args) - 1;
}

static void	move_right(t_select *se)
{
	if (se->cursor + se->files_per_col < (int)ft_arraylen(se->args))
		se->cursor += se->files_per_col;
	else if (se->args[se->cursor - se->files_per_col])
		se->cursor = se->cursor - se->files_per_col;
}

static void	move_left(t_select *se)
{
	if (se->cursor - se->files_per_col >= 0)
		se->cursor -= se->files_per_col;
	else if (se->args[ft_arraylen(se->args) - (se->files_per_col -
		se->cursor - 1)])
		se->cursor = ft_arraylen(se->args) - (se->files_per_col -
		se->cursor - 1);
}

void		move_cursor(t_select *se)
{
	if (se->control == LEFT && se->files_per_row != 1)
		move_left(se);
	else if (se->control == RIGHT && se->files_per_row != 1)
		move_right(se);
	else if (se->control == UP)
		move_up(se);
	else if (se->control == DOWN)
		move_down(se);
	se_print_list(se);
}
