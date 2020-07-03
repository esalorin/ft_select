/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rawmode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:27:40 by esalorin          #+#    #+#             */
/*   Updated: 2020/07/03 16:11:26 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** Using tcgetattr() to read the current attributes into a struct,
** modifying the struct by hand, and passing the modified struct to tcsetattr()
** to write the new terminal attributes.
** The c_lflag field is for “local flags”.
** There is an ICANON flag that allows us to turn off canonical mode.
** This means we will finally be reading input byte-by-byte, instead of
** line-by-line. (In canonical mode keyboard input is only sent to your program
** when the user presses Enter)
** ECHO feature causes each key you type to be printed to the terminal.
** (~ is NOT-operator)
** c_cc field stands for “control characters”.
** VMIN value sets the minimum number of bytes of input needed before read()
** can return.
** VTIME value sets the maximum amount of time to wait before read() returns.
*/

/*
** tgetent() function looks up the termcap entry for name.
** tgetstr() function gets the string entry for id.
** tputs() function outputs the string.
*/

void	set_rawmode(t_select *se)
{
	char	buf[1024];

	if (tcgetattr(STDIN_FILENO, &se->original_mode) == -1)
	{
		ft_putendl_fd("tcgetattr failed.. Exiting.", STDERR_FILENO);
		exit(1);
	}
	se->raw_mode = se->original_mode;
	se->raw_mode.c_lflag &= ~(ICANON | ECHO);
	se->raw_mode.c_cc[VMIN] = 1;
	se->raw_mode.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &se->raw_mode) == -1)
	{
		ft_putendl_fd("tcsetattr failed.. Exiting.", STDERR_FILENO);
		exit(1);
	}
	if (tgetent(buf, se->term) < 1)
		ft_putendl_fd("tgetent: entry/terminfo database could not be found", 2);
	tputs(tgetstr("vi", NULL), 1, ft_putint_fd);
	tputs(tgetstr("ti", NULL), 1, ft_putint_fd);
}
