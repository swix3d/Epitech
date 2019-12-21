#include <unistd.h>
#include <stdlib.h>

int my_putchar(const char c)
{
    write(1, &c, 1);
}

void tree(const int size);

int main(int argc, char *argv[])
{
    if (argc <= 1)
        return 0;

    tree(atoi(argv[1]));
}
