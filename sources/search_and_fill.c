#include "ft_h.h"
#include "ft_filehandeling.h"
#include "ft_filereader.h"
#include "search_and_fill.h"
#include "ft_valid.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int search_and_fill(char *file, int filesize, board_settings *settings)
{
    if(fill_board(file,filesize,settings) == 0)
        return (0);
    find_biggest_square(settings);
    print_grid(settings);
    return (1);
}



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
				return (0);
			line[horizontal] = c;
			horizontal++;
		}
		line[horizontal] = 0;
		skipparams += horizontal;
		horizontal = 0;
		vertical++;
	}
	return (1);
}

void find_biggest_square(board_settings *settings) {
    int max_size = 0;
    int max_x = 0;
    int max_y = 0;

    for (int x = 0; x < settings->rows; x++) {
        for (int y = 0; y < settings->line_lenght; y++) {
            if (settings->board[x][y] != settings->obstacle) {
                int size = 1;
                while (can_place_square(x, y, size, settings)) {
                    size++;
                }

                if (size -1 > max_size) {
                    max_size = size - 1;
                    max_x = x;
                    max_y = y;
                }
            }
        }
    }

    for (int i = max_x; i < max_x + max_size; i++) {
        for (int j = max_y; j < max_y + max_size; j++) {
            settings->board[i][j] = settings->fill;
        }
    }
}

int can_place_square(int x, int y, int size,board_settings *board) {
    if (x + size > board->rows || y + size > board->line_lenght) {
        return 0;
    }

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (board->board[i][j] == board->obstacle) {
                return 0;
            }
        }
    }
    
      if (size == 1 && board->board[x][y] != board->empty) {
        return 1;
    }

    return 1;
}


void print_grid(board_settings *board) {
    for (int i = 0; i < board->rows; i++) {
        printf("%s\n", board->board[i]);
    }
}