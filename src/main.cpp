#include "airport_record.h"
#include "priority_queue.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string &s, char delim);

int main() {
    std::ifstream input("../data/air16.txt");
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
        recs.emplace_back(
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
        );
    }

    // TESTS

    { // insert tests
        PriorityQueue queue;

        queue = PriorityQueue();

        queue.insert(recs[0]);
        queue.insert(recs[1]);
        queue.insert(recs[2]);

        auto expected = recs[1].altitude;
        auto actual = std::get<1>(queue.maximum());
        if (expected == actual) {
            std::cout << "Insert1 PASS" << std::endl;
        } else {
            std::cout << "Insert1 FAIL: Expected " << expected << " got " << actual << std::endl;
            return 1;
        }
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
