#include <iostream>
#include <fstream>

int main() {
    // take a file as input
    std::ifstream file("../input.txt");
    // read the file line by line
    std::string line;
    int result = 0;
    int current = 0;
    while (std::getline(file, line)) {
        int temp = 0;
        // do something with the line
        if(!line.empty()) {
            // cast the string to an int
            temp = std::stoi(line);
            std::cout << "Temp" << temp << std::endl;
            current = current + temp;
            std::cout << "Current" << current << std::endl;
        } else {
            if(current > result) {
                result = current;
            }
                current = 0;
        }
        std::cout << line << std::endl;
    }
    std::cout << "Result: " << result << std::endl;
}
