#include <stdio.h>

void pre_main(void) __attribute__((constructor));

/**
 * pre_main - Function to be executed before main.
 */
void pre_main(void)
{
    printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}
