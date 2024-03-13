#pragma once

#include "airport_record.h"

#include <tuple>
#include <vector>

class PriorityQueue {
    private:
        std::vector<AirportRecord> keys;

        void heapify();
    public:
        PriorityQueue(std::vector<AirportRecord> vec);
        void insert(AirportRecord rec);
        std::tuple<AirportRecord, int> maximum();
        std::tuple<AirportRecord, int> extractMax();
        void increaseKey(AirportRecord rec, int k);
};
