/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "sok.h"

int my_change_x(char **str, int *player, int sens)
{
    char temp;
    int a = player[0];
    int b = player[1];

    if (sens == 0) {
        if (str[b][a + 2] == '#' || str[b][a + 2] == 'X') return (0);
        if (str[b][a + 2] == 'O') str = my_fall(str, a, b, sens);
        else {
            temp = str[b][a + 2], str[b][a + 2] = str[b][a + 1];
            str[b][a + 1] = str[b][a], str[b][a] = temp;
        }
    }
    if (sens == 1) {
        if (str[b][a - 2] == '#' || str[b][a - 2] == 'X') return (0);
        if (str[b][a - 2] == 'O') str = my_fall(str, a, b, sens);
        else {
            temp = str[b][a - 2], str[b][a - 2] = str[b][a - 1];
            str[b][a - 1] = str[b][a], str[b][a] = temp;
        }
    } my_change_xs(str, player, sens);
}

int find_close(int y, int x, char **str)
{
    int col = 0;
    int line = 0;

    if (str[y][x] == 'X') {
        if (str[y][x + 1] == '#') line++;
        if (str[y][x - 1] == '#') line++;
        if (str[y + 1][x] == '#') col++;
        if (str[y - 1][x] == '#') col++;
        if (line != 0 && col != 0) endwin(), exit (1);
    }
    return (0);
}

int check_stock(char **str, int *box)
{
    int x = 0;
    int y = 0;

    while (str[y] != NULL) {
        while (str[y][x] != '\0') {
            find_close(y, x, str);
            x++;
        }
        x = 0, y++;
    }
    return (0);
}

int *create_xy(int y, int x, int *assign)
{
    assign = malloc(sizeof(int) * 2);
    assign[0] = x;
    assign[1] = y;
    return (assign);
}

int count_arg(char **str)
{
    int nb = 0;

    while (str[nb] != NULL)
        nb++;
    return (nb);
}