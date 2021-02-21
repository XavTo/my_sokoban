/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "sok.h"

int my_count_x(int y, int x, char **str, int nb)
{
    if (str[y][x] == 'X')
        nb++;
    return (nb);
}

char **my_fall(char **str, int a, int b, int sens)
{
    char temp;

    if (sens == 0) {
        temp = str[b][a], str[b][a + 1] = str[b][a];
        str[b][a] = ' ', str[b][a + 2] = 'X';
    }
    if (sens == 1) {
        temp = str[b][a], str[b][a - 1] = str[b][a];
        str[b][a] = ' ', str[b][a - 2] = 'X';
    }
    if (sens == 2) {
        temp = str[b][a], str[b + 1][a] = str[b][a];
        str[b][a] = ' ', str[b + 2][a] = 'X';
    }
    if (sens == 3) {
        temp = str[b][a], str[b - 1][a] = str[b][a];
        str[b][a] = ' ', str[b - 2][a] = 'X';
    }
    return (str);
}

int my_resize(char **str, obj_t *obj, char *filepath, int *pos)
{
    erase();
    if (COLS <= count_arg(str) + 2 || LINES <= count_arg(str) + 2) {
        pos[0] = LINES / 2;
        pos[1] = COLS / 2 - (my_strlen("too small") / 2);
        erase(), mvprintw(pos[0], pos[1], "Too Small !");
    }
    else return (my_win(str, filepath, pos, obj));
}

int find_obj(obj_t *obj, char **str)
{
    int x = 0;
    int y = 0;
    int save = 0;

    while (str[y] != NULL) {
        while (str[y][x] != '\0') {
            find_obj_check(y, x, str, obj);
            x++;
        }
        save = x, x = 0, y++;
    }
    obj->size = create_xy(y, save, obj->size);
}

int my_change_xs(char **str, int *player, int sens)
{
    char temp;
    int a = player[0];
    int b = player[1];

    if (sens == 2) {
        if (str[b + 2][a] == '#' || str[b + 2][a] == 'X') return (0);
        if (str[b + 2][a] == 'O') str = my_fall(str, a, b, sens);
        else {
            temp = str[b + 2][a], str[b + 2][a] = str[b + 1][a];
            str[b + 1][a] = str[b][a], str[b][a] = temp;
        }
    }
    if (sens == 3) {
        if (str[b - 2][a] == '#' || str[b - 2][a] == 'X') return (0);
        if (str[b - 2][a] == 'O') str = my_fall(str, a, b, sens);
        else {
            temp = str[b - 2][a], str[b - 2][a] = str[b - 1][a];
            str[b - 1][a] = str[b][a], str[b][a] = temp;
        }
    }
}