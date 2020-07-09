/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:04:30 by esalorin          #+#    #+#             */
/*   Updated: 2020/07/09 13:00:24 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	signal_handler(int sig)
{
	if (sig == SIGWINCH)
	{
		check_windowsize(g_select);
		se_print_list(g_select);
	}
	else if (sig == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
		unset_rawmode(g_select);
	}
	else if (sig == SIGCONT)
	{
		set_rawmode(g_select);
		signals();
		check_windowsize(g_select);
		se_print_list(g_select);
	}
	else if (sig == SIGINT || sig == SIGQUIT || sig == SIGTERM || sig == SIGHUP
	|| sig == SIGPIPE || sig == SIGALRM || sig == SIGXCPU || sig == SIGXFSZ ||
	sig == SIGVTALRM || sig == SIGPROF)
	{
		unset_rawmode(g_select);
		free_all(g_select);
		exit(0);
	}
}

void		signals(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGWINCH, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGHUP, signal_handler);
	signal(SIGPIPE, signal_handler);
	signal(SIGALRM, signal_handler);
	signal(SIGXCPU, signal_handler);
	signal(SIGXFSZ, signal_handler);
	signal(SIGVTALRM, signal_handler);
	signal(SIGPROF, signal_handler);
}
