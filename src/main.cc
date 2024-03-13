#include "priority_queue.h"
#include "airport_record.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string &s, char delim);

int main() {
    std::ifstream input("./data/air16.txt");
    if (!input.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::string> lineElems;
    std::vector<AirportRecord> recs;

    std::getline(input, line);
    int size = std::stoi(line);

    for (int i = 0; i < size; i++) {
        std::getline(input, line);
        lineElems = split(line, ' ');
        recs.push_back(AirportRecord(
            lineElems[0],
            lineElems[1],
            lineElems[2],
            lineElems[3],
            std::stoi(lineElems[4]),
            std::stoi(lineElems[5]),
            std::stoi(lineElems[6]),
            lineElems[7],
            std::stoi(lineElems[8]),
            std::stoi(lineElems[9]),
            std::stoi(lineElems[10]),
            lineElems[11],
            std::stoi(lineElems[12])
        ));
    }

    for (AirportRecord rec: recs) {
        std::cout << rec << std::endl;
    }

    input.close();
    return 0;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
