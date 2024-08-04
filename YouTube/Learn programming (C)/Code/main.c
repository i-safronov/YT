#include <stdio.h>
#include <string.h>
#include "data_structure/array/array.c"

int main()
{
    void const *ptr = create(INT, 10);
    int item = 1;
    int item1 = 2;
    int item2 = 3;
    int item3 = 4;

    add(ptr, &item);
    add(ptr, &item1);
    add(ptr, &item2);
    add(ptr, &item3);

    void (*default_pr)(void const *p);
    default_pr = default_print;

    printf_i(ptr, default_pr);

    delete (ptr, 0);

    printf("After delete: \n"); 

    printf_i(ptr, default_pr);

    return 0;
}