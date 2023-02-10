#include <stdio.h>

// creates an enum (enumerated list)
enum Level {
    LOW,        // value 0
    MEDIUM,     // value 1
    HIGH        // value 2
};

enum Level_2 {
    NEW_LOW = 5,    // value 5
    NEW_MEDIUM,     // value 6
    NEW_HIGH        // value 7
};

int main() {

    // declares an enum variable
    enum Level my_high = HIGH;

    // prints enum value
    printf("Low not set, so default = 0 and high = %d\n", my_high);

    // declares new enum variable
    enum Level_2 my_new_high = NEW_HIGH;

    // prints enum value for new high
    printf("Low set to 5, high value = %d\n", my_new_high);

    return 0;
}
