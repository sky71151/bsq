/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperez-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:22:35 by rperez-t          #+#    #+#             */
/*   Updated: 2023/11/08 18:43:06 by rvan-bae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_board.h"
#include "../includes/ft_h.h"
#include "ft_filehandeling.h"
#include "ft_filereader.h"

int	fill_board(char *file, int filesize, board_settings *settings)
{
	int		vertical;
	int		horizontal;
	int		skipparams;
	char	*line;
	char	c;

	vertical = 0;
	horizontal = 0;
	skipparams = get_line_size (file, filesize, 0);
	while (vertical < settings->rows)
	{
		line = settings->board[vertical];
		while (horizontal < settings->line_lenght)
		{
			c = file[horizontal + vertical + skipparams];
			if (c == '\n')
				c = file[horizontal + vertical + skipparams + 1];
			if (!(c == settings->empty || c == settings->obstacle))
				return (1);
			line[horizontal] = c;
			horizontal++;
		}
		line[horizontal] = 0;
		skipparams += horizontal;
		horizontal = 0;
		vertical++;
	}
	return (0);
}
