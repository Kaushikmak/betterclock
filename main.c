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

int main(){
    printf(PURPLE LOW_DENSITY_DOTTED_SQUARE);

    return 0;
}