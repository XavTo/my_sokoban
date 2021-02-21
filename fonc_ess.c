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

int find_close(int y, int x, char **str, find_t *find)
{
    int count = 0;
    int counts = 0;
    int i = 0;
    int *pos = malloc(sizeof(int) * 2);

    if (str[y][x] == 'X') {
        if (str[y][x + 1] == '#') count++;
        if (str[y][x - 1] == '#') count++;
        if (str[y + 1][x] == '#') counts++;
        if (str[y - 1][x] == '#') counts++;
        if (count >= 1 && counts >= 1) (*find).block++;
        if ((*find).block == (*find).nb) {
            pos[0] = LINES / 2 - (count_arg(str) / 2);
            pos[1] = COLS / 2 - (my_strlen(str[1]) / 2);
            while (str[i] != NULL)
                mvprintw(pos[0], pos[1], str[i]), pos[0]++, i++;
            refresh(), endwin(), free(pos), exit (1);
        }
    }
    free(pos);
}

int check_stock(char **str, int *box)
{
    int x = 0;
    int y = 0;
    find_t find;

    find.block = 0, find.nb = 0;
    while (str[y] != NULL) {
        while (str[y][x] != '\0') {
            find.nb = my_count_x(y, x, str, find.nb);
            x++;
        }
        x = 0, y++;
    }
    x = 0, y = 0;
    while (str[y] != NULL) {
        while (str[y][x] != '\0') {
            find_close(y, x, str, &find);
            x++;
        }
        x = 0, y++;
    }
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