/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "sok.h"

char **tab_swaps(char **str, int *player, int sens, obj_t *obj)
{
    char temp;
    int a = player[0];
    int b = player[1];

    if (sens == 2) {
        if (str[b + 1][a] == '#') return (str);
        if (str[b + 1][a] == 'O') {
            str[b + 1][a] = 'P', str[b][a] = ' ';
            return (str);
        }
        if (str[b + 1][a] == 'X') {
            my_change_x(str, player, sens);
            return (str);
        }
        temp = str[b][a], str[b][a] = str[b + 1][a], str[b + 1][a] = temp;
    }
    if (sens == 3)
        str = tab_swapsss(str, player, sens, obj);
    return (str);
}

char **tab_swap(char **str, int *player, int sens, obj_t *obj)
{
    char temp;
    int a = player[0];
    int b = player[1];

    if (sens == 0) {
        if (str[b][a + 1] == '#') return (str);
        if (str[b][a + 1] == 'O') {
            str[b][a + 1] = 'P', str[b][a] = ' ';
            return (str);
        }
        if (str[b][a + 1] == 'X') {
            my_change_x(str, player, sens);
            return (str);
        }
        temp = str[b][a], str[b][a] = str[b][a + 1], str[b][a + 1] = temp;
    }
    if (sens == 1)
        str = tab_swapss(str, player, sens, obj);
    str = tab_swaps(str, player, sens, obj);
    return (str);
}

int check_ifwin(char **str, obj_t *obj, char *filepath, int *pos)
{
    int c = 0;
    int count = 0;
    int a;
    int b;
    int i = 0;

    while (obj->fall[c] != NULL) {
        a = obj->fall[c][0], b = obj->fall[c][1];
        if (str[b][a] == ' ') str[b][a] = 'O';
        if (str[b][a] == 'X') count++;
        c++;
    }
    if (count == obj->nb_fall) {
        pos[0] = LINES / 2 - (count_arg(str) / 2);
        pos[1] = COLS / 2 - (my_strlen(str[1]) / 2);
        while (str[i] != NULL)
            mvprintw(pos[0], pos[1], str[i]), pos[0]++, i++;
        refresh(), free(pos), endwin(), exit (0);
    }
}

int my_move(char **str, obj_t *obj, char *filepath, int *pos)
{
    int c = 0;
    int count = 0;
    while (count != 3) { c = getch();
        if (c == 410) my_resize(str, obj, filepath, pos);
        if (c == 32) return (reset(filepath));
        count++;
        if (count == 3 && c == 67) {
            str = tab_swap(str, obj->player, 0, obj);
            break;}
        if (count == 3 && c == 68) {
            str = tab_swap(str, obj->player, 1, obj);
            break;}
        if (count == 3 && c == 66) {
            str = tab_swap(str, obj->player, 2, obj);
            break;}
        if (count == 3 && c == 65) {
            str = tab_swap(str, obj->player, 3, obj);
            break;}
        if (count == 1 && c != 27 && c != 32 && c != 410) break;
    } check_ifwin(str, obj, filepath, pos);
}

int my_win(char **str, char *filepath, int *pos, obj_t *obj)
{
    int i = 0;

    find_obj(obj, str);
    pos[0] = LINES / 2 - (count_arg(str) / 2);
    pos[1] = COLS / 2 - (my_strlen(str[1]) / 2);
    while (str[i] != NULL) {
        mvprintw(pos[0], pos[1], str[i]);
        pos[0]++;
        i++;
    }
    refresh(), noecho();
    my_move(str, obj, filepath, pos);
    check_stock(str, obj->box);
    return (my_win(str, filepath, pos, obj));
    endwin();
}