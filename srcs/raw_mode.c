/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenasalorinta <eenasalorinta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:27:40 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/05/28 16:17:11 by eenasalorin      ###   ########.fr       */
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
