#include <iostream>
#include <fstream>

void puzzle01();
void puzzle02();

int main() {
    puzzle01();
    puzzle02();
    return 0;
}

bool isDistinct(std::string line) {
    for(int i = 0; i < line.length(); i++) {
        for(int j = i + 1; j < line.length(); j++) {
            if(line[i] == line[j]) {
                return false;
            }
        }
    }
    return true;
}

void puzzle01() {
    // read a file line by line

    std::ifstream file("../input.txt");
    std::string str;
    while (std::getline(file, str)) {
        int pos = 0;
        bool found = false;
        while(!found) {
            if(isDistinct(str.substr(pos, 4))) {
                found = true;
                std::cout << str.substr(pos, 4) << " at position " << pos + 4 << std::endl;
            }
            pos++;
        }
    }
}

void puzzle02() {
    // read a file line by line

    std::ifstream file("../input.txt");
    std::string str;
    while (std::getline(file, str)) {
        int pos = 0;
        bool found = false;
        while(!found) {
            if(isDistinct(str.substr(pos, 14))) {
                found = true;
                std::cout << str.substr(pos, 14) << " at position " << pos + 14 << std::endl;
            }
            pos++;
        }
    }
}


