/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:40:05 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/07/03 15:40:26 by eenasalorin      ###   ########.fr       */
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
	else
	{
		if ((se->files_per_col * se->files_per_row - 1) == se->cursor)
			se->cursor = se->files_per_col - 1;
		else
			se->cursor = se->files_per_col - 1 - ((se->files_per_col *
			se->files_per_row - 1) - se->cursor);
	}
	if (se->cursor < 0)
		move_right(se);
}

static void	move_left(t_select *se)
{
	if (se->cursor - se->files_per_col >= 0)
		se->cursor -= se->files_per_col;
	else
		se->cursor = se->files_per_col * se->files_per_row - 1 -
		(se->files_per_col - 1 - se->cursor);
	if (!se->args[se->cursor])
		move_left(se);
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
