/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalorin <esalorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:37:17 by eenasalorin       #+#    #+#             */
/*   Updated: 2020/06/04 16:54:20 by esalorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/srcs/libft.h"
# include <signal.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>

# define UP 4283163
# define DOWN 4348699
# define LEFT 4479771
# define RIGHT 4414235
# define ENTER 10
# define SPACE 32
# define BSPACE 127
# define DELETE 2117294875
# define ESC 27

typedef struct termios	t_term;

typedef struct			s_select
{
	char		**args;
	char		*term;
	int			*selected;
	int			cursor;
	int			max_len;
	int			control;
	int			files_per_col;
	int			files_per_row;
	t_term		original_mode;
	t_term		raw_mode;
}						t_select;

void					check_windowsize(t_select *se);
void					clear(void);
void					free_all(t_select *se);
void					move_cursor(t_select *se);
void					remove_item(t_select *se);
void					se_print_list(t_select *se);
void					se_read(t_select *se);
void					selection(t_select *se);
void					set_rawmode(t_select *se);
void					unset_rawmode(t_select *se);

int						inspect_controls(t_select *se);
int						max_len(char **args);
int						send_choices(t_select *se);
int						set_struct(t_select *se, char **av, int ac);

#endif
