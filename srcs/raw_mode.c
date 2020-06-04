/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:27:40 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/04 15:37:09 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	unset_rawmode(t_select *se)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &se->original_mode) == -1)
		;
}

void	set_rawmode(t_select *se)
{
	if (tcgetattr(STDIN_FILENO, &se->original_mode) == -1)
		;
	se->raw_mode = se->original_mode;
	se->raw_mode.c_lflag &= ~(ICANON | ECHO);
	se->raw_mode.c_cc[VMIN] = 1;
	se->raw_mode.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &se->raw_mode) == -1)
		;
}
