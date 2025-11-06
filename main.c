#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>

// TERMINAL characters
#define LOW_DENSITY_DOTTED_SQUARE       "░"
#define MEDIUM_DENSITY_DOTTED_SQUARE    "▒"
#define HIGH_DENSITY_DOTTED_SQUARE      "▓"
#define EMPTY                           " "
#define SOLID_SQUARE                    "█"
#define SOLID_CENTER_SQUARE             "■"

// TERMINAL colors
const struct {
    const char *BLACK, *RED, *GREEN, *YELLOW, *BLUE, *PURPLE, *CYAN, *WHITE, *RESET;
} COLOR = {
    "\e[0;30m", "\e[0;31m", "\e[0;32m", "\e[0;33m",
    "\e[0;34m", "\e[0;35m", "\e[0;36m", "\e[0;37m",
    "\x1b[0m"
};

// digits matrix (Unchanged)
int digits[10][5][5] = {
        // ZERO
        {{1,1,1,1,1}
        ,{1,0,0,0,1}
        ,{1,0,0,0,1}
        ,{1,0,0,0,1}
        ,{1,1,1,1,1}},
        // ONE
        {{0,0,1,0,0}
        ,{0,1,1,0,0}
        ,{0,0,1,0,0}
        ,{0,0,1,0,0}
        ,{1,1,1,1,1}},
        // TWO
        {{1,1,1,1,1}
        ,{0,0,0,0,1}
        ,{1,1,1,1,1}
        ,{1,0,0,0,0}
        ,{1,1,1,1,1}},
        // THREE
        {{1,1,1,1,1}
        ,{0,0,0,0,1}
        ,{0,1,1,1,1}
        ,{0,0,0,0,1}
        ,{1,1,1,1,1}},
        // FOUR
        {{1,0,0,1,0}
        ,{1,0,0,1,0}
        ,{1,1,1,1,1}
        ,{0,0,0,1,0}
        ,{0,0,0,1,0}},
        // FIVE
        {{1,1,1,1,1}
        ,{1,0,0,0,0}
        ,{1,1,1,1,1}
        ,{0,0,0,0,1}
        ,{1,1,1,1,1}},
        // SIX
        {{1,1,1,1,1}
        ,{1,0,0,0,0}
        ,{1,1,1,1,1}
        ,{1,0,0,0,1}
        ,{1,1,1,1,1}},
        // SEVEN
        {{1,1,1,1,1}
        ,{0,0,0,0,1}
        ,{0,0,0,1,0}
        ,{0,0,1,0,0}
        ,{0,1,0,0,0}},
        // EIGHT
        {{1,1,1,1,1}
        ,{1,0,0,0,1}
        ,{1,1,1,1,1}
        ,{1,0,0,0,1}
        ,{1,1,1,1,1}},
        // NINE
        {{1,1,1,1,1}
        ,{1,0,0,0,1}
        ,{1,1,1,1,1}
        ,{0,0,0,0,1}
        ,{1,1,1,1,1}},

};

// Separator
int separator[5][3] = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
};
#define SEP_WIDTH 3
#define DIGIT_WIDTH 5

void printNumberRow(int n, int row, const char *colorvalue){
    int d[2];
    d[0] = n / 10;
    d[1] = n % 10;

    for (int k = 0; k < 2; k++) {
        for (int j = 0; j < DIGIT_WIDTH; j++) {
            if (digits[d[k]][row][j])
                printf("%s%s%s", colorvalue, SOLID_SQUARE, COLOR.RESET);
            else
                printf(EMPTY);
        }
        if (k == 0) {
             printf(EMPTY);
        }
    }
}

void printSeparatorRow(int row, const char *colorvalue) {
    for (int j = 0; j < SEP_WIDTH; j++) {
        if (separator[row][j])
            printf("%s%s%s", colorvalue, LOW_DENSITY_DOTTED_SQUARE, COLOR.RESET);
        else
            printf(EMPTY);
    }
}


int main(){
    char inputBuffer[10];
    // hide cursor
    printf("\033[?25l");

    while(1){
        struct timeval tval = {0,0};
        fd_set fdset;
        FD_ZERO(&fdset);
        FD_SET(STDIN_FILENO, &fdset);

        if (select(STDIN_FILENO + 1, &fdset, NULL, NULL, &tval) > 0) {
            fgets(inputBuffer, sizeof(inputBuffer), stdin);
            inputBuffer[strcspn(inputBuffer, "\n")] = 0;
            if (strcmp(inputBuffer, "q") == 0) { 
                break;
            }
        }

        // time
        time_t t = time(NULL);
        struct tm *currentTime = localtime(&t);


        for (int i = 0; i < 5; i++) {

            printNumberRow((currentTime->tm_hour)%12, i, COLOR.RED);
            printf("  ");


            printSeparatorRow(i, COLOR.YELLOW);

            printNumberRow(currentTime->tm_min, i, COLOR.GREEN);
            printf("  ");


            printSeparatorRow(i, COLOR.YELLOW);
            printf("  ");

            printNumberRow(currentTime->tm_sec, i, COLOR.BLUE);

            printf("\n");
        }
        
        fflush(stdout);


        printf("\033[5A"); 
        sleep(1);
    }
     // show cursor again
    printf("\033[?25h");
    // move cursor below clock after exit
    printf("\033[5B");


    return 0;
}