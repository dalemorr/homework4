#include "priority_queue.h"
#include "airport_record.h"

#include <algorithm>

PriorityQueue::PriorityQueue(std::vector<AirportRecord> vec) {
    this->keys = vec;
    heapify(0);
}

void PriorityQueue::increaseKey(AirportRecord rec, int k) {
    auto location = std::find(this->keys.begin(), this->keys.end(), rec);

    if (k > location->altitude) {
        location->altitude = k;
    }
}

void PriorityQueue::insert(AirportRecord rec) {
    this->keys.push_back(rec);
    this->heapify(0);
}

std::tuple<AirportRecord, int> PriorityQueue::maximum() {
    AirportRecord rec = this->keys.front();
    return std::make_tuple(rec, rec.altitude);
}

std::tuple<AirportRecord, int> PriorityQueue::extractMax() {
    std::tuple<AirportRecord, int> max = this->maximum();

    this->keys[0] = this->keys.back();
    this->keys.pop_back();
    this->heapify(0);

    return max;
}

void PriorityQueue::heapify(int i) {
    AirportRecord max = this->keys.front();
    int left = this->left(i);
    int right = this->right(i);
}

void PriorityQueue::swap(int i, int j) {
    AirportRecord temp = this->keys[i];
    this->keys[i] = this->keys[j];
    this->keys[j] = temp;
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
