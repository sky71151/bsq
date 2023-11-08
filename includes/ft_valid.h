/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-bae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:49:24 by rvan-bae          #+#    #+#             */
/*   Updated: 2023/11/08 07:55:02 by rvan-bae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALID_H
# define FT_VALID_H

#include "ft_h.h"
#include "ft_filehandeling.h"
//#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>


int     check_map_valid(char *filename, board_settings *settings);
int     get_rows(char *line, int size);
int     check_first_line(char *file, board_settings *settings);
int	get_line_lenght(char *file, int line_number);
int check_all_lines_lenght(char *file, board_settings *settings);

int check_printable(board_settings *settings);


#endif
