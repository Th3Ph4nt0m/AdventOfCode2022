#include <iostream>
#include <fstream>

void puzzle01();
void puzzle02();

int main() {
    puzzle01();
    puzzle02();
    return 0;
}

void puzzle01() {
    int count = 0;
    // read a file line by line
    std::ifstream file("../input.txt");
    std::string str;
    while (std::getline(file, str)) {

        // one line contains two ranges of numbers
        // a range is displayed as "min-max"
        // two ranges are seperated by a comma

        // get the first range
        int min = std::stoi(str.substr(0, str.find('-')));
        int max = std::stoi(str.substr(str.find('-') + 1, str.find(' ')));

        std::cout << min << " " << max << std::endl;

        // get the second range after the comma
        int min2 = std::stoi(str.substr(str.find(',') + 1, str.find('-', str.find(','))));
        int max2 = std::stoi(str.substr(str.find('-', str.find(',')) + 1, str.find(' ', str.find(','))));


        std::cout << min2 << " " << max2 << std::endl;

        // in how many pairs does one range fully contain the other?
        if ((min <= min2 && max >= max2) || (min2 <= min && max2 >= max)) {
            count++;
        }
    }

    std::cout << count << std::endl;
}

void puzzle02() {
    int count = 0;
    // read a file line by line
    std::ifstream file("../input.txt");
    std::string str;
    while (std::getline(file, str)) {

        // one line contains two ranges of numbers
        // a range is displayed as "min-max"
        // two ranges are seperated by a comma

        // get the first range
        int min = std::stoi(str.substr(0, str.find('-')));
        int max = std::stoi(str.substr(str.find('-') + 1, str.find(' ')));

        std::cout << min << " " << max << std::endl;

        // get the second range after the comma
        int min2 = std::stoi(str.substr(str.find(',') + 1, str.find('-', str.find(','))));
        int max2 = std::stoi(str.substr(str.find('-', str.find(',')) + 1, str.find(' ', str.find(','))));

        std::cout << min2 << " " << max2 << std::endl;

        // How many pairs overlap?
        if ((min <= min2 && max >= min2) || (min2 <= min && max2 >= min)) {
            count++;
        }
    }
    std::cout << count << std::endl;
}
