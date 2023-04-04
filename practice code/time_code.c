#include <time.h>
#include <stdio.h>


// place code here to time
void code() {

    // prints out 10000 '.' to have the program doing something to time
    for (int i=0; i<10000; i++) {
        printf (".");
    }

    printf("\n");
}

int main() {

    // number of times to run code to time
    const int CODE_RUNS = 1;

    // declare clock_t object
    clock_t t;

    // declare number of times to run code block as size and create an array to store times
    double run_times_array[CODE_RUNS];

    // run timed code the number of times specified in CODE_RUNS, add each time to run_times_array
    for (int i=0;i<CODE_RUNS;i++){
        // print clock start time
        printf("start: %d\n", (int) (t = clock()));

        // run code to time
        code();

        // print clock stop time
        printf("stop: %d\n\n", (int) (t = clock() - t));

        // calculate elapsed time and add to array
        run_times_array[i] = (double) t / CLOCKS_PER_SEC;
    }

    double sum = 0;

    // retrieve the times for each run, print each to console and calculate sum
    for (int i=0;i<CODE_RUNS;i++) {
        sum = sum + run_times_array[i];
        printf("Elapsed time for run %d: %.4f seconds\n", i+1, run_times_array[i]);
    }

    // calculate average time and print to console
    float average = (double) sum / CODE_RUNS;
    printf("Average elapsed time after %d runs is %.4f seconds\n", CODE_RUNS, average);

    return 0;
}
