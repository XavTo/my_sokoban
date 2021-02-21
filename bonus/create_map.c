/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "sok.h"

int recup_input(int sur, char **str)
{
    int c = 0;
    int count = 0;

    while (1) {
        c = getch();
        if (c == 10) {stock_in_str(sur, str);
            break;}
        count++;
        if (count == 3 && c == 66) {
            sur++;
            break;
        }
        if (count == 3 && c == 65) {
            sur--;
            break;
        }
    }
    if (sur < 1) sur++;
    if (sur > 9) sur--;
    return (sur);
}

char **double_tab_map(char **str, char *buff)
{
    int i = 0;
    int backline = 0;
    int a = 0;
    int b = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '\n') backline++;
        i++;
    } str = malloc(sizeof(char *) * backline + 10), i = 0;
    while (buff[i] != '\0') {
        if (buff[i] == '\n') str[b] = malloc(sizeof(char) * a + 1), b++, a = 0;
        i++, a++;
    } str[b] = malloc(sizeof(char) * a + 1), b = 0, a = 0, i = 0;
    while (buff[i] != '\0') {
        if (buff[i] == '\n') str[a][b] = '\0', b = 0, a++, i++;
        str[a][b] = buff[i], i++, b++;
    }
    str[a + 1] = NULL;
    return (str);
}

char **create_str_map(char **str, char *filepath)
{
    int ret = 0;
    int op = 0;
    char *buff;
    struct stat sb;

    if (stat(filepath, &sb) == -1)
        endwin(), exit (84);
    buff = malloc(sizeof(char) * sb.st_size + 1);
    op = open(filepath, O_RDONLY);
    if (op <= -1)
        endwin(), exit (84);
    ret = read(op, buff, sb.st_size);
    buff[ret] = '\0';
    str = double_tab_map(str, buff);
    free (buff);
    return (str);
}

int boucle_play(char **str, int *pos)
{
    int i = 0;
    int save = pos[0];
    int sur = 1;
    char *new = malloc(sizeof(char) * 500);
    char *space = malloc(sizeof(char) * 500);

    while (1) {
        usleep(50000), erase(), refresh(), pos[0] = save, i = 0;
        space = change_space(new, space), mvprintw(0, 0, space);
        while (str[i] != NULL) {
            attron(A_NORMAL);
            if (i == sur) {
                attron(A_STANDOUT), mvprintw(pos[0], pos[1], str[sur]);
                attroff(A_STANDOUT);
            }
            else mvprintw(pos[0], pos[1], str[i]);
            pos[0]++, i++;
        }
        sur = recup_input(sur, &new), refresh();
    }
}

int create_map(void)
{
    int fd = 0;
    int c = 0;
    char *filepath = "own_map";
    char **str;
    int *pos = malloc(sizeof(int) * 2);

    fd = open(filepath, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) exit (84);
    str = create_str_map(str, "default");
    initscr();
    curs_set(0);
    noecho();
    pos[0] = 1;
    pos[1] = (COLS - 25);
    boucle_play(str, pos);
    endwin(), exit(0);
    return (reset(filepath));
}