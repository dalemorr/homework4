#include "priority_queue.h"
#include "airport_record.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(const string &s, char delim);

int main() {
    ifstream input("./data/air16.txt");
    if (!input.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    string line;
    vector<string> lineElems;
    vector<AirportRecord> recs;

    getline(input, line);
    int size = stoi(line);

    for (int i = 0; i < size; i++) {
        getline(input, line);
        lineElems = split(line, ' ');
        recs.push_back(AirportRecord(
            lineElems[0],
            lineElems[1],
            lineElems[2],
            lineElems[3],
            stoi(lineElems[4]),
            stoi(lineElems[5]),
            stoi(lineElems[6]),
            lineElems[7],
            stoi(lineElems[8]),
            stoi(lineElems[9]),
            stoi(lineElems[10]),
            lineElems[11],
            stoi(lineElems[12])
        ));
    }

    for (AirportRecord rec: recs) {
        cout << rec << endl;
    }

    input.close();
    return 0;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    istringstream iss(s);
    string item;
    while (getline(iss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
