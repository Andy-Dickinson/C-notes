#include <stdio.h>

int main(void) {

    // \e[1m to start bold
    // \e[m resets
    printf("\e[1mHello in bold\n");
    printf("half bo\e[mld\n");

    return 0;
}
