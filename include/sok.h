/*
** EPITECH PROJECT, 2020
** runner
** File description:
** bottstrap
*/

#ifndef sok_h
#define sok_h

#include <ncurses.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "my.h"

typedef unsigned char uchar;

typedef struct {
    int *player;
    int *size;
    int *box;
    int nb_fall;
    int **fall;
} obj_t;

typedef struct {
    int block;
    int nb;
} find_t;

int my_win(char **str, char *filepath, int *pos, obj_t *obj);
int count_arg(char **str);
int *create_xy(int y, int x, int *assign);
int my_change_x(char **str, int *player, int sens);
int my_change_xs(char **str, int *player, int sens);
int reset(char *filepath);
int check_stock(char **str, int *player);
int find_obj(obj_t *obj, char **str);
char **my_fall(char **str, int a, int b, int sens);
int my_resize(char **str, obj_t *obj, char *filepath, int *pos);
int my_count_x(int y, int x, char **str, int nb);
char **tab_swapss(char **str, int *player, int sens, obj_t *obj);
char **tab_swapsss(char **str, int *player, int sens, obj_t *obj);
int count_boxs(obj_t *obj, char **str);
int check_box(int y, int x, char **str, obj_t *obj);
int check_boxs(int y, int *u, char **str, obj_t *obj);
int find_obj_check(int y, int x, char **str, obj_t *obj);
int check_if_vl_map(char **str);

#endif