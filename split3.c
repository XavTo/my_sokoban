/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "sok.h"

int find_obj_check(int y, int x, char **str, obj_t *obj)
{
    if (str[y][x] == 'P')
        obj->player = create_xy(y, x, obj->player);
    if (str[y][x] == 'X')
        obj->box = create_xy(y, x, obj->box);
    return (0);
}

int *my_check_p(int y, int x, char **str, int *vl)
{
    if (str[y][x] == 'P')
        vl[0]++;
    if (str[y][x] == 'O')
        vl[1]++;
    if (str[y][x] == 'X')
        vl[2]++;
    if (str[y][x] == '#')
        vl[3]++;
    return (vl);
}

int check_diese(char **str)
{
    int y = 0;

    while (str[y] != NULL) {
        if (str[y][0] != '#' || str[y][my_strlen(str[y]) - 1] != '#')
            free(str), endwin(), exit(84);
        y++;
    }
}

int check_if_vl_map(char **str)
{
    int y = 0;
    int x = 0;
    int *vl = malloc(sizeof(int) * 4);
    vl[0] = 0, vl[1] = 0, vl[2] = 0, vl[3] = 0;
    while (str[y] != NULL) {
        while (str[y][x] != '\0') vl = my_check_p(y, x, str, vl), x++;
        x = 0, y++;
    }
    while (str[0][x] != '\0') {
        if (str[0][x] != '#' && str[0][x] != '\n') free(vl), endwin(), exit(84);
        x++;
    } x = 0;
    while (str[y - 1][x] != '\0') {
        if (str[y - 1][x] != '#' && str[y - 1][x] != '\n')
            free(vl), endwin(), exit(84);
        x++;
    }
    if (vl[0] != 1 || vl[1] < 1 || vl[2] < 1
        || vl[3] < 1 || vl[1] > vl[2]) free(vl), free(str), endwin(), exit(84);
    free(vl);
}