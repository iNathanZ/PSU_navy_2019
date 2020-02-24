/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** coord.c
*/

#include "../include/my.h"
#include "../include/structures.h"
char **get_coord(char coord1, char coord2, char **arr, char boat)
{
    arr[coord2 - 49][coord1 - 65] = boat;
    return (arr);
}

char **fill_coord(char **array, coord_t *coord)
{
    get_coord(coord->x1, coord->y1, array, coord->boat);
    get_coord(coord->x2, coord->y2, array, coord->boat);
    if (coord->x1 == coord->x1) {
        for (int i = coord->y1 ; i != coord->y2 ; i++)
            get_coord(coord->x1, i, array, coord->boat);
    }
    if (coord->y1 == coord->y2) {
        for (int i = coord->x1 ; i != coord->x2 ; i++)
            get_coord(i, coord->y1, array, coord->boat);
    }
    return (array);
}

char **fill_map(char const *filepath, char **array, coord_t *coord)
{
    char *buffer = malloc(sizeof(char) * 32);
    int a = 0;
    char *content = malloc(sizeof(char) * 7);
    int j = 0;
    int fd = open_fd(filepath);

    if (fd == -1)
        return (NULL);
    while (read(fd, buffer, 8) != 0) {
        //CHECK_FILE;
        FILL_STRUCT;
        array = fill_coord(array, coord);
    }
    return (array);
}