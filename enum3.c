#include <stdio.h>

typedef enum {
    false = 0,
    true = 1
} boolean;

int main() {
    boolean a = true;
    boolean b = false;

    if (a)
        printf("a é verdadeiro\n");
    else
        printf("a é falso\n");

    if (b)
        printf("b é verdadeiro\n");
    else
        printf("b é falso\n");

    return 0;
}
