#include <iostream>
#include <fstream>

int main() {
    // read a file line by line
    std::ifstream file("../input.txt");
    std::string line;

    int cycle = 0, sum = 0, x = 1, x_pos = 0, y_pos = 0;
    // signal strength every 40 cycles. We need to find the 20th, 60th, 100th, 140th and 180th cycle (total 6)
    char current[40][6];
    while (std::getline(file, line)) {
        bool foundSpace = line.find(' ') != std::string::npos;
        // if we found a space, we need two cycles to execute the command, otherwise one
        int loopCount = foundSpace ? 2 : 1;

        // execute the command
        while (loopCount-- > 0 ) {
            //check for every 40 cycles
            if ((++cycle + 20) % 40 == 0)
                // save the current signal strength for the 20th, 60th, 100th, 140th and 180th cycle
                sum += x * cycle;


            // set the x position for the screen (part2 only)
            x_pos = (cycle - 1) % 40;
            // set the y position for the screen (part2 only)
            y_pos = (cycle - 1) / 40;
            // set the symbol for the screen (part2 only)
            current[x_pos][y_pos] = (x_pos == x-1 || x_pos == x || x_pos == x+1) ? '#' : ' ';
        }

        // if we found a space in this line, add the signal strength to the x (part1 only)
        if(foundSpace) {
            x += stoi(line.substr(line.find(' ')));
        }

    }
        // print the sum of the six signal strengths (solution for part1)
        std::cout << sum;

    // print the screen (solution for part2)
    for(int i = 0; i < 6; i++) {
        std::cout << std::endl;

        for(auto & j : current) {
            std::cout << j[i];
        }
    }
}
