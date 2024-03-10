#include "priority_queue.h"
#include "airport_record.h"

#include <fstream>
#include <iostream>

int main() {
    std::ifstream input("./data/air16.txt");
    std::string line;
    if (input.is_open()) {
        while (getline(input, line)) {
            std::cout << line << std::endl;
        }
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
    input.close();

    return 0;
}
