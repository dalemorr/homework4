#pragma once

#include "airport_record.h"

#include <tuple>
#include <vector>

class PriorityQueue {
private:
    std::vector<AirportRecord> keys;

    void heapify(int i);
    void swap(int i, int j);
    static int left(int i);
    static int right(int i);
    static int parent(int i);
public:
    PriorityQueue();
    explicit PriorityQueue(std::vector<AirportRecord> vec);
    void insert(const AirportRecord& rec);
    std::tuple<AirportRecord, int> maximum();
    std::tuple<AirportRecord, int> extract_max();
    void increase_key(const AirportRecord& rec, int k);
    int get_size();
};
