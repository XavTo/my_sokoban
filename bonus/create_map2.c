/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** bootstrap
*/

#include "sok.h"

int stock_in_str(int sur, char **str)
{
    int i = my_strlen(*str);
    if (sur == 8)
        free((*str)), (*str) = malloc(sizeof(char) * 500);
    if (sur == 7)
        write_in_map((*str));
    if (sur == 1)
        (*str)[i] = '#', (*str)[i + 1] = '\0';
    if (sur == 2)
        (*str)[i] = ' ', (*str)[i + 1] = '\0';
    if (sur == 3)
        (*str)[i] = '\n', (*str)[i + 1] = '\0';
    if (sur == 4)
        (*str)[i] = 'P', (*str)[i + 1] = '\0';
    if (sur == 5)
        (*str)[i] = 'X', (*str)[i + 1] = '\0';
    if (sur == 6)
        (*str)[i] = 'O', (*str)[i + 1] = '\0';
    if (sur == 9)
        return (reset("map"));
}

int write_in_map(char *str)
{
    int fd = 0;

    fd = open("own_map", O_RDWR);
    if (fd == -1)
        return (-1);
    write(fd, str, my_strlen(str));
    close (fd);
    return (reset("own_map"));
}

char *change_space(char *str, char *str2)
{
    int i = 0;
    int a = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            str2[a] = '_', i++, a++;
        else
            str2[a] = str[i], i++, a++;
    }
    str2[a] = '\0';
    return (str2);
}