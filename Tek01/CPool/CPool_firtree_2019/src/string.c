#include <unistd.h>

int my_putchar(char c);
void change_color(const int allow_change);

void putchar_n_times(const char c, const int n)
{
    for (int i = 0; i < n; i++)
    {
        change_color(-1);
        write(1, &c, 1);
    }
}

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;

    return i;
}

void my_putstr(const char *str)
{
    const int len = my_strlen(str);

    for (int i = 0; i < len; i++)
        my_putchar(str[i]);
}