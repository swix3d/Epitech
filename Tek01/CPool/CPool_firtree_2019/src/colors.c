#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const char *normal = "\x1B[0m";
const char *blink = "\x1B[5m";
const char *bold_c = "\x1b[1m";

const char *green = "\x1B[32m";
const char *red = "\x1B[31m";
const char *blue = "\x1B[36m";
const char *yellow = "\x1B[93m";
const char *magenta = "\x1B[95m";
const char *brown_ish = "\e[0;33m";

void my_putstr(const char *str);

static int rand_int(const int a, const int b)
{
    return (rand() % (b - a)) + a;
}

static void change_bliking_color(const char *color)
{
    my_putstr(normal);
    my_putstr(blink);
    my_putstr(color);
}

static void change_color_rm_blink(const char *color, const bool bold)
{
    my_putstr(normal);

    if (bold)
        my_putstr(bold_c);

    my_putstr(color);
}

void change_color(const int change)
{
    if (change == 0)
        return change_color_rm_blink(green, false);
    else if (change == 1)
        return change_color_rm_blink(brown_ish, true);
    else if (change == 2)
        return change_color_rm_blink(yellow, false);

    int r_chk = rand_int(1, 10);

    if (r_chk == 1)
        change_bliking_color(red);
    else if (r_chk == 2)
        change_bliking_color(blue);
    else if (r_chk == 3)
        change_bliking_color(yellow);
    else if (r_chk == 4)
        change_bliking_color(magenta);
    else if (r_chk >= 5)
        change_color_rm_blink(green, true);
}