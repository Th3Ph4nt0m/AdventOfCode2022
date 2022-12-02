#include <iostream>
#include <fstream>
#include <map>

void puzzle01();
void puzzle02();

int main() {
    //puzzle01();
    puzzle02();
    return 0;
}


void puzzle01(){
    // Rock paper scissors
    // Opponent picks A for rock, B for paper, C for scissors
    // Other player picks X for rock, Y for paper, Z for scissors

    // Read a file line by line
    std::ifstream file("../input.txt");
    std::string str;
    int meScore = 0;
    while (std::getline(file, str))
    {
        // split the string at the space
        std::string delimiter = " ";
        std::string opponent = str.substr(0, str.find(delimiter));
        std::string me = str.substr(str.find(delimiter) + 1, str.length());

        // convert the strings to int
        int opponentInt = 0;
        int meInt = 0;

        if (opponent == "A") {
            opponentInt = 1;
        } else if (opponent == "B") {
            opponentInt = 2;
        } else if (opponent == "C") {
            opponentInt = 3;
        }

        if (me == "X") {
            meInt = 1;
            meScore += 1;
            std::cout << "meScore: " << meScore << std::endl;
        } else if (me == "Y") {
            meInt = 2;
            meScore+= 2;
            std::cout << "meScore: " << meScore << std::endl;
        } else if (me == "Z") {
            meInt = 3;
            meScore+= 3;
            std::cout << "meScore: " << meScore << std::endl;
        }

        // compare the ints
        if (opponentInt == meInt) {
            std::cout << "Tie" << std::endl;
            meScore += 3;
        } else if (opponentInt == 1 && meInt == 2) {
            std::cout << "You win" << std::endl;
            meScore += 6;
        } else if (opponentInt == 1 && meInt == 3) {
            std::cout << "You lose" << std::endl;
            meScore += 0;
        } else if (opponentInt == 2 && meInt == 1) {
            std::cout << "You lose" << std::endl;
            meScore += 0;
        } else if (opponentInt == 2 && meInt == 3) {
            std::cout << "You win" << std::endl;
            meScore += 6;
        } else if (opponentInt == 3 && meInt == 1) {
            std::cout << "You win" << std::endl;
            meScore += 6;
        } else if (opponentInt == 3 && meInt == 2) {
            std::cout << "You lose" << std::endl;
            meScore += 0;
        }

    }
    std::cout << "Your score is: " << meScore << std::endl;
}

void puzzle02(){
    // Read a file line by line
    std::ifstream file("../input.txt");
    std::string str;
    int meScore = 0;
    while (std::getline(file, str)) {
        // split the string at the space
        std::string delimiter = " ";
        std::string opponent = str.substr(0, str.find(delimiter));
        std::string me = str.substr(str.find(delimiter) + 1, str.length());

        // convert the strings to int
        int opponentInt = 0;
        int meInt = 0;

        // Rock
        if (opponent == "A") {
            opponentInt = 1;
        // Paper
        } else if (opponent == "B") {
            opponentInt = 2;
        // Scissors
        } else if (opponent == "C") {
            opponentInt = 3;
        }

        // me describes how the round must end
        // X means I must lose
        // Y means draw
        // Z means I must win

        if(opponentInt == 1) {
            std::cout << "Opponent picked rock" << std::endl;
            switch (me[0]) {
                case 'X':
                    std::cout << "X" << std::endl;
                    meInt = 3;
                    meScore += 0 + 3;
                    break;
                case 'Y':
                    std::cout << "Y" << std::endl;
                    meInt = 1;
                    meScore += 3 + 1;
                    break;
                case 'Z':
                    std::cout << "Z" << std::endl;
                    meInt = 2;
                    meScore += 6 + 2;
                    break;
            }
        } else if(opponentInt == 2) {
            std::cout << "Opponent picked paper" << std::endl;
            switch (me[0]) {
                case 'X':
                    std::cout << "X" << std::endl;
                    meInt = 1;
                    meScore += 0 + 1;
                    break;
                case 'Y':
                    std::cout << "Y" << std::endl;
                    meInt = 2;
                    meScore += 3 + 2;
                    break;
                case 'Z':
                    std::cout << "Z" << std::endl;
                    meInt = 3;
                    meScore += 6 + 3;
                    break;
            }
        } else if(opponentInt == 3) {
            std::cout << "Opponent picked scissors" << std::endl;
            switch (me[0]) {
                case 'X':
                    std::cout << "X" << std::endl;
                    meInt = 2;
                    meScore += 0 + 2;
                    break;
                case 'Y':
                    std::cout << "Y" << std::endl;
                    meInt = 3;
                    meScore += 3 + 3;
                    break;
                case 'Z':
                    std::cout << "Z" << std::endl;
                    meInt = 1;
                    meScore += 6 + 1;
                    break;
            }
        }
    }
    std::cout << "Your score is: " << meScore << std::endl;
}
