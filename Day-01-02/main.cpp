#include <iostream>
#include <fstream>

int main() {
    // take a file as input
    std::ifstream file("../input.txt");
    // read the file line by line
    std::string line;
    int current = 0;
    int topthree[3] = {0, 0, 0};
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
            // check if the current is greater than the top three
            for(int i = 0; i < 3; i++) {
                if(current > topthree[i]) {
                    // shift the top three down
                    for(int j = 2; j > i; j--) {
                        topthree[j] = topthree[j-1];
                    }
                    // insert the current
                    topthree[i] = current;
                    break;
                }
            }
            // reset the current
            current = 0;
        }
        std::cout << line << std::endl;
    }
    std::cout << "Result: " << topthree[0] + topthree[1] + topthree[2] << std::endl;
}
