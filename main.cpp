#include <iostream>
#include <vector>
#include <string>
#include <curses.h>

class Board {
    public:
        Board();
        void run();
        void draw();
    private:
        void up();
        void down();
        void left();
        void right();
        void placenumber();

        std::vector<std::vector<int>> board = {{2, 2, 0, 2}, {2, 0, 0, 0}, {2, 2, 0, 2048}, {2, 4, 32, 16}};
};  

Board::Board() {

}

void Board::up() {
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=base; i < 4; i++) {
                if ((board.at(i).at(j) == board.at(i-1).at(j)) && (board.at(i).at(j) != 0)) {
                    board.at(i-1).at(j) = board.at(i).at(j) * 2;
                    board.at(i).at(j) = 0;
                    base++;
                } else if (board.at(i).at(j) == 0) {

                } else if (board.at(i-1).at(j) == 0) {
                    board.at(i-1).at(j) = board.at(i).at(j);
                    board.at(i).at(j) = 0; 
                }
            }
        }
    }
}

void Board::down() {
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=3-base; i >= 0; i--) {
                if ((board.at(i).at(j) == board.at(i+1).at(j)) && (board.at(i).at(j) != 0)) {
                    board.at(i+1).at(j) = board.at(i).at(j) * 2;
                    board.at(i).at(j) = 0;
                    base++;
                } else if (board.at(i).at(j) == 0) {

                } else if (board.at(i+1).at(j) == 0) {
                    board.at(i+1).at(j) = board.at(i).at(j);
                    board.at(i).at(j) = 0; 
                }
            }
        }
    }
}

void Board::left() {
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=base; i < 4; i++) {
                if ((board.at(j).at(i) == board.at(j).at(i-1)) && (board.at(j).at(i) != 0)) {
                    board.at(j).at(i-1) = board.at(j).at(i) * 2;
                    board.at(j).at(i) = 0;
                    base++;
                } else if (board.at(j).at(i) == 0) {

                } else if (board.at(j).at(i-1) == 0) {
                    board.at(j).at(i-1) = board.at(j).at(i);
                    board.at(j).at(i) = 0; 
                }
            }
        }
    }
}

void Board::right() {
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=3-base; i >= 0; i--) {
                if ((board.at(j).at(i) == board.at(j).at(i+1)) && (board.at(j).at(i) != 0)) {
                    board.at(j).at(i+1) = board.at(j).at(i) * 2;
                    board.at(j).at(i) = 0;
                    base++;
                } else if (board.at(j).at(i) == 0) {

                } else if (board.at(j).at(i+1) == 0) {
                    board.at(j).at(i+1) = board.at(j).at(i);
                    board.at(j).at(i) = 0; 
                }
            }
        }
    }
}

void Board::run() {
    right();
}

void Board::draw() {
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
                if (i == 4 - std::to_string(board.at(j).at(0)).length()+1) {
                    std::string str = std::to_string(board.at(j).at(0));
                    char arr[str.size()];
                    for (int i=0; i < str.size(); i++) {
                        arr[i] = char(str.at(i));
                        printw("%c", str.at(i));
                    }
                    i += std::to_string(board.at(j).at(0)).length()-1;
                } else if (i == 9 - std::to_string(board.at(j).at(1)).length()+1) {
                    std::string str = std::to_string(board.at(j).at(1));
                    char arr[str.size()];
                    for (int i=0; i < str.size(); i++) {
                        arr[i] = char(str.at(i));
                        printw("%c", str.at(i));
                    }
                    i += std::to_string(board.at(j).at(1)).length()-1;
                } else if (i == 14 - std::to_string(board.at(j).at(2)).length()+1) {
                    std::string str = std::to_string(board.at(j).at(2));
                    char arr[str.size()];
                    for (int i=0; i < str.size(); i++) {
                        arr[i] = char(str.at(i));
                        printw("%c", str.at(i));
                    }
                    i += std::to_string(board.at(j).at(2)).length()-1;
                } else if (i == 19 - std::to_string(board.at(j).at(3)).length()+1) {
                    std::string str = std::to_string(board.at(j).at(3));
                    char arr[str.size()];
                    for (int i=0; i < str.size(); i++) {
                        arr[i] = char(str.at(i));
                        printw("%c", str.at(i));
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
}

int main() {
    // char x = getchar();
    Board board;
    board.draw();
    board.run();
    board.draw();
    initscr();

    int c;
    bool door = true;
    while (door = true) {
        board.draw();
        c = getch();
        // printw("%c", c);
        clear();
        refresh();
    }
    endwin();
    // board.run();
    // board.draw();
    // board.run();
    // board.draw();

    // std::cout << x << std::endl;    
    return 0;
}