#include "airport_record.h"
#include "priority_queue.h"

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

    { // maximum tests
        PriorityQueue queue;

        queue = PriorityQueue(recs);

        auto expected = recs[1].altitude;
        auto actual = std::get<1>(queue.maximum());
        if (expected == actual) {
            std::cout << "Maximum1 PASS" << std::endl;
        } else {
            std::cout << "Maximum1 FAIL: Expected " << expected << " got " << actual << std::endl;
            return 1;
        }

        std::vector<AirportRecord> vec1{recs[2], recs[3], recs[4]};

        queue = PriorityQueue(vec1);

        expected = vec1[1].altitude;
        actual = std::get<1>(queue.maximum());
        if (expected == actual) {
            std::cout << "Maximum2 PASS" << std::endl;
        } else {
            std::cout << "Maximum2 FAIL: Expected " << expected << " got " << actual << std::endl;
            return 1;
        }
    }

    { // extract maximum tests
        PriorityQueue queue;

        queue = PriorityQueue(recs);

        auto expected1 = recs[1].altitude;
        auto actual1 = std::get<1>(queue.extract_max());
        auto expected2 = recs[0].altitude;
        auto actual2 = std::get<1>(queue.extract_max());
        if (expected1 == actual1 && expected2 == actual2) {
            std::cout << "ExtractMax1 PASS" << std::endl;
        } else {
            std::cout << "ExtractMax1 FAIL: Expected " << expected1 << ", " << expected2 << " got " << actual1 << ", " << actual2 << std::endl;
            return 1;
        }

        std::vector<AirportRecord> vec1{recs[2], recs[3], recs[4]};

        queue = PriorityQueue(vec1);

        auto expected = vec1[1].altitude;
        auto actual = std::get<1>(queue.maximum());
        if (expected == actual) {
            std::cout << "ExtractMax2 PASS" << std::endl;
        } else {
            std::cout << "ExtractMax2 FAIL: Expected " << expected << " got " << actual << std::endl;
            return 1;
        }
    }

    { // insert tests
        PriorityQueue queue;

        queue = PriorityQueue();

        queue.insert(recs[2]);
        queue.insert(recs[3]);
        queue.insert(recs[4]);

        auto expected = recs[3].altitude;
        auto actual = std::get<1>(queue.maximum());
        if (expected == actual) {
            std::cout << "Insert1 PASS" << std::endl;
        } else {
            std::cout << "Insert1 FAIL: Expected " << expected << " got " << actual << std::endl;
            return 1;
        }

        queue = PriorityQueue();

        queue.insert(recs[0]);
        queue.insert(recs[1]);
        queue.insert(recs[2]);

        expected = recs[1].altitude;
        actual = std::get<1>(queue.maximum());
        if (expected == actual) {
            std::cout << "Insert2 PASS" << std::endl;
        } else {
            std::cout << "Insert2 FAIL: Expected " << expected << " got " << actual << std::endl;
            return 1;
        }
    }

    { // increase key tests
        PriorityQueue queue;

        queue = PriorityQueue();

        queue.insert(recs[0]);
        queue.insert(recs[1]);
        queue.insert(recs[2]);

        queue.increase_key(recs[1], 5000);

        auto expected = 5000;
        auto actual = std::get<1>(queue.maximum());
        if (expected == actual) {
            std::cout << "IncreaseKey1 PASS" << std::endl;
        } else {
            std::cout << "IncreaseKey2 FAIL: Expected " << expected << " got " << actual << std::endl;
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
