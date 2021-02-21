/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "sok.h"

char **tab_swapss(char **str, int *player, int sens, obj_t *obj)
{
    char temp;
    int a = player[0];
    int b = player[1];

    if (str[b][a - 1] == '#') return (str);
    if (str[b][a - 1] == 'O') {
        str[b][a - 1] = 'P', str[b][a] = ' ';
        return (str);
    }
    if (str[b][a - 1] == 'X') {
        my_change_x(str, player, sens);
        return (str);
    }
    temp = str[b][a], str[b][a] = str[b][a - 1], str[b][a - 1] = temp;
    return (str);
}

char **tab_swapsss(char **str, int *player, int sens, obj_t *obj)
{
    char temp;
    int a = player[0];
    int b = player[1];

    if (str[b - 1][a] == '#') return (str);
    if (str[b - 1][a] == 'O') {
        str[b - 1][a] = 'P', str[b][a] = ' ';
        return (str);
    }
    if (str[b - 1][a] == 'X') {
        my_change_x(str, player, sens);
        return (str);
    }
    temp = str[b][a], str[b][a] = str[b - 1][a], str[b - 1][a] = temp;
    return (str);
}

int check_box(int y, int x, char **str, obj_t *obj)
{
    if (str[y][x] == 'O')
        obj->nb_fall++;
}

int check_boxs(int y, int *u, char **str, obj_t *obj)
{
    int x = 0;

    while (str[y][x] != '\0') {
        if (str[y][x] == 'O') {
            obj->fall[*u] = create_xy(y, x, obj->fall[*u]);
            (*u)++;
        }
        x++;
    }
}

int count_boxs(obj_t *obj, char **str)
{
    int y = 0;
    int u = 0;

    while (str[y] != NULL) {
        check_boxs(y, &u, str, obj);
        y++;
    }
    obj->fall[u] = NULL;
}