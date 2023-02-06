#include <ncurses.h>
#include <string>
#include <iostream>

int main() {
    initscr();

    int t = 1231;
    std::string tw;
    tw = std::to_string(t);
    std::cout << t << std::endl;

    int c;
    bool door = true;
    while (door = true) {
        c = getch();
        printw("%c", c);
    }
    endwin();
    
    return 0;
}