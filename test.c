#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int rows;
    char empty;
    char obstacle;
    char full;
    char **grid; // A 2D array for variable columns
} Map;

void free_map(Map *map) {
    for (int i = 0; i < map->rows; i++) {
        free(map->grid[i]);
    }
    free(map->grid);
}

int read_map(const char *filename, Map *map) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open the file.\n");
        return 0;
    }

    fscanf(file, "%d %c %c %c\n", &map->rows, &map->empty, &map->obstacle, &map->full);

    map->grid = (char **)malloc(sizeof(char *) * map->rows);
    if (map->grid == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(file);
        return 0;
    }

    for (int i = 0; i < map->rows; i++) {
        char temp[1000]; // Assuming maximum of 1000 characters per line
        if (fscanf(file, "%s", temp) != 1) {
            fprintf(stderr, "Invalid map format.\n");
            fclose(file);
            free_map(map);
            return 0;
        }

        map->grid[i] = strdup(temp);
    }

    fclose(file);
    return 1;
}

int can_place_square(int x, int y, int size, const Map *map) {
    if (x + size > map->rows) {
        return 0;
    }

    for (int i = x; i < x + size; i++) {
        if (strlen(map->grid[i]) - y < size) {
            return 0;
        }

        for (int j = y; j < y + size; j++) {
            if (map->grid[i][j] == map->obstacle) {
                return 0;
            }
        }
    }
    return 1;
}

void find_biggest_square(const Map *map) {
    int max_size = 0;
    int max_x = 0;
    int max_y = 0;

    for (int x = 0; x < map->rows; x++) {
        for (int y = 0; y < strlen(map->grid[x]); y++) {
            int size = 1;
            while (can_place_square(x, y, size, map)) {
                size++;
            }

            if (size - 1 > max_size) {
                max_size = size - 1;
                max_x = x;
                max_y = y;
            }
        }
    }

    for (int i = max_x; i < max_x + max_size; i++) {
        for (int j = max_y; j < max_y + max_size; j++) {
            map->grid[i][j] = map->full;
        }
    }
}

void print_grid(const Map *map) {
    for (int i = 0; i < map->rows; i++) {
        printf("%s\n", map->grid[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s map_file1 [map_file2 ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        Map map;
        if (read_map(argv[i], &map)) {
            find_biggest_square(&map);
            print_grid(&map);
            free_map(&map);
        } else {
            fprintf(stderr, "Map error\n");
        }
        printf("\n");
    }

    return 0;
}

