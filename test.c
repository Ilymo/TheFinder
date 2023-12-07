#include <stdio.h>
#include <math.h>

int main(void)
{
    float n = ((70^2) + (-20^2));
    printf("%f\n", n);
    n = sqrt(n);
    printf("%f\n", n);
    n = round(n);
    printf("%f\n", n);
}
