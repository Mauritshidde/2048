#include <iostream>
#include <vector>
#include <string>
#include <curses.h>
#include <time.h>
#include <cstdlib>

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

        bool moved = false;
        std::vector<std::vector<int>> board = {{2, 2, 0, 2}, {2, 0, 0, 0}, {2, 2, 0, 2048}, {2, 4, 32, 16}};
};  

Board::Board() {

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
}

void Board::up() {
    moved = false;
    for (int j=0; j < 4; j++) {
        int base = 1;
        for (int k=0; k < 3; k++) {
            for (int i=base; i < 4; i++) {
                if ((board.at(i).at(j) == board.at(i-1).at(j)) && (board.at(i).at(j) != 0)) {
                    board.at(i-1).at(j) = board.at(i).at(j) * 2;
                    board.at(i).at(j) = 0;
                    base++;
                    moved = true;
                } else if (board.at(i).at(j) == 0) {

                } else if (board.at(i-1).at(j) == 0) {
                    board.at(i-1).at(j) = board.at(i).at(j);
                    board.at(i).at(j) = 0; 
                    moved = true;
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
                if ((board.at(i).at(j) == board.at(i+1).at(j)) && (board.at(i).at(j) != 0)) {
                    board.at(i+1).at(j) = board.at(i).at(j) * 2;
                    board.at(i).at(j) = 0;
                    base++;
                    moved = true;
                } else if (board.at(i).at(j) == 0) {

                } else if (board.at(i+1).at(j) == 0) {
                    board.at(i+1).at(j) = board.at(i).at(j);
                    board.at(i).at(j) = 0; 
                    moved = true;
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
                if ((board.at(j).at(i) == board.at(j).at(i-1)) && (board.at(j).at(i) != 0)) {
                    board.at(j).at(i-1) = board.at(j).at(i) * 2;
                    board.at(j).at(i) = 0;
                    base++;
                    moved = true;
                } else if (board.at(j).at(i) == 0) {

                } else if (board.at(j).at(i-1) == 0) {
                    board.at(j).at(i-1) = board.at(j).at(i);
                    board.at(j).at(i) = 0; 
                    moved = true;
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
                if ((board.at(j).at(i) == board.at(j).at(i+1)) && (board.at(j).at(i) != 0)) {
                    board.at(j).at(i+1) = board.at(j).at(i) * 2;
                    board.at(j).at(i) = 0;
                    base++;
                    moved = true;
                } else if (board.at(j).at(i) == 0) {

                } else if (board.at(j).at(i+1) == 0) {
                    board.at(j).at(i+1) = board.at(j).at(i);
                    board.at(j).at(i) = 0;
                    moved = true;
                }
            }
        }
    }
}

void Board::run() {
    right();
}

void Board::draw() {
    std::cout << "┌";
    for (int i=0; i < 21; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;

    for (int j=0; j < 4; j++) {
        for (int i=0; i < 21; i++) {
            if (i == 0) {
                std::cout << "|";
            } else if (i == 5) {
                std::cout << "|";
            } else if (i == 10) {
                std::cout << "|";
            } else if (i == 15) {
                std::cout << "|";
            } else if (i == 20) {
                std::cout << "|";
            } else {
                if (i == 4 - std::to_string(board.at(j).at(0)).length()+1) {
                    std::cout << board.at(j).at(0);
                    i += std::to_string(board.at(j).at(0)).length()-1;
                } else if (i == 9 - std::to_string(board.at(j).at(1)).length()+1) {
                    std::cout << board.at(j).at(1);
                    i += std::to_string(board.at(j).at(1)).length()-1;
                } else if (i == 14 - std::to_string(board.at(j).at(2)).length()+1) {
                    std::cout << board.at(j).at(2);
                    i += std::to_string(board.at(j).at(2)).length()-1;
                } else if (i == 19 - std::to_string(board.at(j).at(3)).length()+1) {
                    std::cout << board.at(j).at(3);
                    i += std::to_string(board.at(j).at(3)).length()-1;
                } else {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }

    for (int i=0; i < 21; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

int main() {
    // char x = getchar();
    srand(time(NULL));
    Board board;
    board.draw();
    board.run();
    board.draw();
    // board.run();
    // board.draw();
    // board.run();
    // board.draw();

    // std::cout << x << std::endl;    
    return 0;
}