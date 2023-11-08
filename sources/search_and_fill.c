#include "ft_h.h"
#include "ft_filehandeling.h"
#include "ft_filereader.h"
#include "search_and_fill.h"
#include "ft_valid.h"
//#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int search_and_fill(char *file, int filesize, board_settings *settings)
{
    fill_board(file,filesize,settings);
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



int can_place_square(int x, int y, int size,board_settings *board) {
    if (x + size > board->rows) {
        return 0;
    }

    for (int i = x; i < x + size; i++) {
        if (board->line_lenght- y < size) {
            return 0;
        }

        for (int j = y; j < y + size; j++) {
            if (board->board[i][j] == board->obstacle) {
                return 0;
            }
        }
    }
    return 1;
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

                if (size > max_size) {
                    max_size = size;
                    max_x = x;
                    max_y = y;
                }
            }
        }
    }

    for (int i = max_x; i < max_x + max_size; i++) {
        for (int j = max_y; j < max_y + max_size; j++) {
            map->grid[i][j] = map->full;
        }
    }
}







/*
void find_biggest_square(board_settings *board) {
    int max_size = 0;
    int max_x = 0;
    int max_y = 0;

    for (int x = 0; x < board->rows; x++) {
        for (int y = 0; y < board->line_lenght; y++) {
            int size = 1;
            while (can_place_square(x, y, size, board)) {
                size++;
            }

            if (size > max_size) {
                max_size = size;
                max_x = x;
                max_y = y;
            }
        }
    }

    for (int i = max_x; i < max_x + max_size; i++) {
        for (int j = max_y; j < max_y + max_size; j++) {
            board->board[i][j] = board->fill;
        }
    }
}*/

void print_grid(board_settings *board) {
    for (int i = 0; i < board->rows; i++) {
        printf("%s\n", board->board[i]);
    }
}