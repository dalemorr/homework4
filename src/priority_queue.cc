#include "priority_queue.h"
#include "airport_record.h"

#include <algorithm>

PriorityQueue::PriorityQueue(std::vector<AirportRecord> vec) {
    this->keys = vec;
    heapify();
}

void PriorityQueue::increaseKey(AirportRecord rec, int k) {
    auto location = find(this->keys.begin(), this->keys.end(), rec);

    if (k > location->altitude) {
        location->altitude = k;
    }
}

void PriorityQueue::insert(AirportRecord rec) {
    this->keys.push_back(rec);
    this->heapify();
}

std::tuple<AirportRecord, int> PriorityQueue::maximum() {
    AirportRecord rec = this->keys.front();
    return std::make_tuple(rec, rec.altitude);
}

std::tuple<AirportRecord, int> PriorityQueue::extractMax() {
    auto max = this->maximum();

    this->keys.erase(this->keys.begin());
    this->heapify();

    return max;
}

void PriorityQueue::heapify() {

}

int PriorityQueue::left(int i) {
    return 2*i + 1;
}

int PriorityQueue::right(int i) {
    return 2*i + 2;
}

int PriorityQueue::parent(int i) {
    if (i % 2 == 0) { // left child
        return (i - 1) / 2;
    } else { // right child
        return (i - 2) / 2;
    }
}
