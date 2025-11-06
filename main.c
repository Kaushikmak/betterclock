#include <stdio.h>
#include <time.h>
#include <string.h>

// TERMINAL characters
#define LOW_DENSITY_DOTTED_SQUARE       "░"
#define MEDIUM_DENSITY_DOTTED_SQUARE    "▒"
#define HIGH_DENSITY_DOTTED_SQUARE      "▓"
#define EMPTY                           " "
#define SOLID_SQUARE                    "█"
#define SOLID_CENTER_SQUARE             "■"

// TERMINAL colors
#define BLACK   "\e[0;30m"
#define RED     "\e[0;31m"
#define GREEN   "\e[0;32m"
#define YELLOW  "\e[0;33m"
#define BLUE    "\e[0;34m"
#define PURPLE  "\e[0;35m"
#define CYAN    "\e[0;35m"
#define WHITE   "\e[0;37m"

// digits matrix
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
        ,{1,0,0,0,1}
        ,{1,1,1,1,1}
        ,{1,0,0,0,1}
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
        {{0,1,1,1,1}
        ,{0,1,0,0,1}
        ,{0,1,1,1,1}
        ,{0,0,0,0,1}
        ,{1,1,1,1,1}},

};

int main(){
    // get time in seprate entities
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    printf(PURPLE "%d\n",(currentTime->tm_hour)%12);
    return 0;
}