#include <iostream>
#include <fstream>

void puzzle01();
void puzzle02();

int main() {
    puzzle01();
    puzzle02();
}

void puzzle01() {
    // read a file line by line
    std::ifstream file("../input.txt");
    std::string line;
    int sum = 0;
    while (std::getline(file, line)) {
        // split every line exactly in the middle
        std::string first = line.substr(0, line.size() / 2);
        std::string second = line.substr(line.size() / 2);

        // check which character (upper and lower case) appears in both strings
        for (char c = 'a'; c <= 'z'; ++c) {
            if (first.find(c) != std::string::npos && second.find(c) != std::string::npos) {
                // add the alphabet position to the sum
                sum += c - 'a' + 1;
            }
        }
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (first.find(c) != std::string::npos && second.find(c) != std::string::npos) {
                // add the alphabet +26 position to the sum
                sum += c - 'A' + 1 + 26;
            }
        }
    }
    std::cout << sum << std::endl;
}

void puzzle02() {
    // read a file line by line
    std::ifstream file("../input.txt");
    std::string line;
    int sum = 0;
    // get the lines in groups of 3
    while (std::getline(file, line)) {
        std::string first = line;
        std::string second;
        std::string third;
        std::getline(file, second);
        std::getline(file, third);

        // check which character (upper and lower case) appears in all strings
        for (char c = 'a'; c <= 'z'; ++c) {
            if (first.find(c) != std::string::npos && second.find(c) != std::string::npos && third.find(c) != std::string::npos) {
                // add the alphabet position to the sum
                sum += c - 'a' + 1;
            }
        }
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (first.find(c) != std::string::npos && second.find(c) != std::string::npos && third.find(c) != std::string::npos) {
                // add the alphabet +26 position to the sum
                sum += c - 'A' + 1 + 26;
            }
        }
    }
    std::cout << sum << std::endl;
}