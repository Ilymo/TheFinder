#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    int *p = &s;
    printf("%p\n", p);
}
