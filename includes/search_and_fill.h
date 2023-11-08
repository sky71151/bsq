/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_fill.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 08:54:47 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/08 13:21:20 by rperez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SEARCH_AND_FILL_H
# define SEARCH_AND_FILL_H

#include "ft_h.h"
#include "ft_filehandeling.h"
//#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int can_place_square(int x, int y, int size,board_settings *board);
void find_biggest_square(board_settings *board);
void print_grid(board_settings *board);
int search_and_fill(char *file, int filesize, board_settings *settings);

#endif