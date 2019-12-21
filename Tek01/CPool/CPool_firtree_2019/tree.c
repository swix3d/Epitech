/*
** EPITECH PROJECT, 2019
** FirTree
** File description:
** tree2
*/

#include <stdlib.h>

int my_putchar(char c);
void change_color(const int allow_rand);
void putchar_n_times(const char c, const int n);

static int get_lines_count(const int size)
{
    int c_line = 4;
    int max_line = 0;

    for (int i = 0; i < size; i++, c_line++)
        max_line += c_line;

    return max_line;
}

static int get_last_col(const int size)
{
    int c_line = 4;
    int last_col = 1;
    int reduction = 1;

    for (int i = 0; i < size; i++, c_line++)
    {
        last_col += 2 * (c_line - reduction);

        if (i % 2 == 0)
            reduction += 1;
    }

    return last_col;
}

static void spaces_print(const int len_lines, const int stars_count)
{
    const int mid = len_lines / 2;
    const int spaces_to_print = mid - stars_count / 2;

    putchar_n_times(' ', spaces_to_print);
}

static void gen_lines(const int size, const int len_lines, const int last_col)
{
    int stars_count = 1;
    int inc_line = 4;
    int dec_count = 4;
    int actual_block = 1;

    change_color(2);

    spaces_print(last_col, stars_count);
    putchar_n_times('*', 1);

    my_putchar('\n');

    for (int i = 1; i < len_lines; i++)
    {
        stars_count += 2;

        if (i == inc_line)
        {
            stars_count -= dec_count;
            inc_line += 4 + actual_block;

            if (actual_block % 2 == 0)
                dec_count += 2;

            actual_block += 1;
        }

        spaces_print(last_col, stars_count);
        putchar_n_times('*', stars_count);

        my_putchar('\n');

        change_color(0);
    }
}

static void gen_bottom(const int size, const int last_col)
{
    const int le = (size % 2) == 0 ? size + 1 : size;

    change_color(1);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < last_col / 2 - le / 2; j++)
            my_putchar(' ');

        for (int j = 0; j < le; j++)
            my_putchar('|');

        my_putchar('\n');
    }
}

static void gen_tree(const int size)
{
    const int len_lines = get_lines_count(size);
    const int last_col = get_last_col(size);

    gen_lines(size, len_lines, last_col);
    gen_bottom(size, last_col);
}

void tree(int size)
{
    gen_tree(size);
}