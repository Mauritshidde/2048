#include <iostream>
#include <vector>
#include <string>
#include <curses.h>
#include <chrono>
#include <math.h>

class Board {
    public:
        Board();
        void run();
        void draw();
        void up();
        void down();
        void left();
        void right();
        void placenumber();
        bool movepossible();
        
        bool moved = true;
        int score =0;
    private:
        std::vector<std::vector<int>> board = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
};  

Board::Board() {

}

bool Board::movepossible() {
    bool canmove = false;
    std::vector<std::vector<int>> board2;

    board2 = board;
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=base; i < 4; i++) {
                if (board2.at(i-1).at(j) == 0) {
                    board2.at(i-1).at(j) = board2.at(i).at(j);
                    board2.at(i).at(j) = 0; 
                    canmove = true;
                } else if ((board2.at(i).at(j) == board2.at(i-1).at(j)) && (board2.at(i).at(j) != 0)) {
                    board2.at(i-1).at(j) = board2.at(i).at(j) * 2;
                    board2.at(i).at(j) = 0;
                    base++;
                    canmove = true;
                } else if (board2.at(i).at(j) == 0) {

                }
            }
        }
    }

    board2 = board;
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=3-base; i >= 0; i--) {
                if (board2.at(i+1).at(j) == 0) {
                    board2.at(i+1).at(j) = board2.at(i).at(j);
                    board2.at(i).at(j) = 0; 
                    canmove = true;
                } else if ((board2.at(i).at(j) == board2.at(i+1).at(j)) && (board2.at(i).at(j) != 0)) {
                    board2.at(i+1).at(j) = board2.at(i).at(j) * 2;
                    board2.at(i).at(j) = 0;
                    base++;
                    canmove = true;
                } else if (board2.at(i).at(j) == 0) {

                }
            }
        }
    }

    board2 = board;
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=base; i < 4; i++) {
                if (board2.at(j).at(i-1) == 0) {
                    board2.at(j).at(i-1) = board2.at(j).at(i);
                    board2.at(j).at(i) = 0; 
                    canmove = true;
                } else if ((board2.at(j).at(i) == board2.at(j).at(i-1)) && (board2.at(j).at(i) != 0)) {
                    board2.at(j).at(i-1) = board2.at(j).at(i) * 2;
                    board2.at(j).at(i) = 0;
                    base++;
                    canmove = true;
                } else if (board2.at(j).at(i) == 0) {

                }
            }
        }
    }

    board2 = board;
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=3-base; i >= 0; i--) {
                if (board2.at(j).at(i+1) == 0) {
                    board2.at(j).at(i+1) = board2.at(j).at(i);
                    board2.at(j).at(i) = 0;
                    canmove = true;
                } else if ((board2.at(j).at(i) == board2.at(j).at(i+1)) && (board2.at(j).at(i) != 0)) {
                    board2.at(j).at(i+1) = board2.at(j).at(i) * 2;
                    board2.at(j).at(i) = 0;
                    base++;
                    canmove = true;
                } else if (board2.at(j).at(i) == 0) {

                }
            }
        }
    }
    
    return canmove;
}

void Board::placenumber() {
    if (moved) {
        bool notfound = true;
        while (notfound) {
            int val = rand() % 4;
            int val2 = rand() % 4;
            if (board.at(val).at(val2) == 0) {
                board.at(val).at(val2) = 2;
                notfound = false;
            }
        }
    }
    moved = false;
}

void Board::up() {
    moved = false;
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=base; i < 4; i++) {
                if (board.at(i-1).at(j) == 0) {
                    board.at(i-1).at(j) = board.at(i).at(j);
                    board.at(i).at(j) = 0; 
                    moved = true;
                } else if ((board.at(i).at(j) == board.at(i-1).at(j)) && (board.at(i).at(j) != 0)) {
                    board.at(i-1).at(j) = board.at(i).at(j) * 2;
                    board.at(i).at(j) = 0;
                    score += board.at(i-1).at(j);
                    base++;
                    moved = true;
                } else if (board.at(i).at(j) == 0) {

                }
            }
        }
    }
}

void Board::down() {
    moved = false;
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=3-base; i >= 0; i--) {
                if (board.at(i+1).at(j) == 0) {
                    board.at(i+1).at(j) = board.at(i).at(j);
                    board.at(i).at(j) = 0; 
                    moved = true;
                } else if ((board.at(i).at(j) == board.at(i+1).at(j)) && (board.at(i).at(j) != 0)) {
                    board.at(i+1).at(j) = board.at(i).at(j) * 2;
                    board.at(i).at(j) = 0;
                    score += board.at(i+1).at(j);
                    base++;
                    moved = true;
                } else if (board.at(i).at(j) == 0) {

                }
            }
        }
    }
}

void Board::left() {
    moved = false;
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=base; i < 4; i++) {
                if (board.at(j).at(i-1) == 0) {
                    board.at(j).at(i-1) = board.at(j).at(i);
                    board.at(j).at(i) = 0; 
                    moved = true;
                } else if ((board.at(j).at(i) == board.at(j).at(i-1)) && (board.at(j).at(i) != 0)) {
                    board.at(j).at(i-1) = board.at(j).at(i) * 2;
                    board.at(j).at(i) = 0;
                    score += board.at(j).at(i-1);
                    base++;
                    moved = true;
                } else if (board.at(j).at(i) == 0) {

                }
            }
        }
    }
}

void Board::right() {
    moved = false;
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=3-base; i >= 0; i--) {
                if (board.at(j).at(i+1) == 0) {
                    board.at(j).at(i+1) = board.at(j).at(i);
                    board.at(j).at(i) = 0;
                    moved = true;
                } else if ((board.at(j).at(i) == board.at(j).at(i+1)) && (board.at(j).at(i) != 0)) {
                    board.at(j).at(i+1) = board.at(j).at(i) * 2;
                    board.at(j).at(i) = 0;
                    score += board.at(j).at(i+1);
                    base++;
                    moved = true;
                } else if (board.at(j).at(i) == 0) {

                }
            }
        }
    }
}

void Board::run() {
    up();
}

void Board::draw() {

    printw("%i", score);
    printw("\n");
    printw("\n");

    for (int i=0; i < 21; i++) {
        printw("-");
    }
    printw("\n");

    for (int j=0; j < 4; j++) {
        for (int i=0; i < 21; i++) {
            if (i == 0) {
                printw("|");
            } else if (i == 5) {
                printw("|");
            } else if (i == 10) {
                printw("|");
            } else if (i == 15) {
                printw("|");
            } else if (i == 20) {
                printw("|");
            } else {
                if (i == 4 - int(std::to_string(board.at(j).at(0)).length())+1) {
                    std::string str = std::to_string(board.at(j).at(0));
                    if (str == "0") {
                        printw(" ");
                    } else {
                        for (int i=0; i < int(str.size()); i++) {
                            printw("%c", str.at(i));
                        }
                    }
                    i += std::to_string(board.at(j).at(0)).length()-1;
                } else if (i == 9 - int(std::to_string(board.at(j).at(1)).length())+1) {
                    std::string str = std::to_string(board.at(j).at(1));
                    if (str == "0") {
                        printw(" ");
                    } else {
                        for (int i=0; i < int(str.size()); i++) {
                            printw("%c", str.at(i));
                        }
                    }
                    i += std::to_string(board.at(j).at(1)).length()-1;
                } else if (i == 14 - int(std::to_string(board.at(j).at(2)).length())+1) {
                    std::string str = std::to_string(board.at(j).at(2));
                    if (str == "0") {
                        printw(" ");
                    } else {
                        for (int i=0; i < int(str.size()); i++) {
                            printw("%c", str.at(i));
                        }
                    }
                    i += std::to_string(board.at(j).at(2)).length()-1;
                } else if (i == 19 - int(std::to_string(board.at(j).at(3)).length())+1) {
                    std::string str = std::to_string(board.at(j).at(3));
                    if (str == "0") {
                        printw(" ");
                    } else {
                        for (int i=0; i < int(str.size()); i++) {
                            printw("%c", str.at(i));
                        }
                    }
                    i += std::to_string(board.at(j).at(3)).length()-1;
                } else {
                    printw(" ");
                }
            }
        }
        printw("\n");
    }

    for (int i=0; i < 21; i++) {
        printw("-");
    }
    printw("\n");


    printw("keys:");
    printw("\n");
    printw("W: move up");
    printw("\n");
    printw("S: move down");
    printw("\n");
    printw("A: move left");
    printw("\n");
    printw("D: move right");
    printw("\n");
}

int main() {
    Board board;
    board.placenumber();
    
    initscr();
    bool door = true;
    int previouskey = 0;
    double deltaTime = 0;
    auto begin = std::chrono::high_resolution_clock::now();
    while (door) {
        board.draw();
        int c = getch();
        printw("%i", int(deltaTime));
        if (deltaTime >= 0.2) {
            previouskey = c;
            if (c == 'w') {
                board.up();
                deltaTime = 0;
            } else if (c == 'a') {
                board.left();
                deltaTime = 0;
            } else if (c == 'd') {
                board.right();
                deltaTime = 0;
            } else if (c == 's') {
                deltaTime = 0;
                board.down();
            } else if (c == 27) {
                door = false;    
                break;
            }
        }

        board.placenumber();
        board.moved = false;
        if (!board.movepossible()) {
            door = false;
            break;
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto dur = end - begin;
        auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(dur).count();
        deltaTime += (ms * pow(10, -9));

        begin = end;
        clear();
        refresh();
    }
    endwin();

    return 0;
}