#include "priority_queue.h"
#include "../airport_record/airport_record.h"

#include <utility>

PriorityQueue::PriorityQueue(std::vector<AirportRecord> vec) {
    this->keys = std::move(vec);
    heapify(0);
}

void PriorityQueue::increase_key(const AirportRecord& rec, int k) {
    auto location = std::find(this->keys.begin(), this->keys.end(), rec);

    if (k > location->altitude) {
        location->altitude = k;
    }
}

void PriorityQueue::insert(const AirportRecord& rec) {
    keys.push_back(rec);

    int i = this->get_size() - 1;
    while (i != 0 && this->keys[parent(i)].altitude < rec.altitude) {
        swap(i, PriorityQueue::parent(i));
        i = parent(i);
    }
}

std::tuple<AirportRecord, int> PriorityQueue::maximum() {
    AirportRecord rec = this->keys.front();
    return std::make_tuple(rec, rec.altitude);
}

std::tuple<AirportRecord, int> PriorityQueue::extract_max() {
    std::tuple<AirportRecord, int> max = this->maximum();

    this->keys[0] = this->keys.back();
    this->keys.pop_back();
    this->heapify(0);

    return max;
}

int PriorityQueue::get_size() {
    return this->keys.size();
}

void PriorityQueue::heapify(int i) {
    if (this->get_size() == 0) {
        return;
    }

    int left = PriorityQueue::left(i);
    int right = PriorityQueue::right(i);
    int largest = i;

 	if (left > 0 && left < this->get_size() && this->keys[left].altitude > this->keys[i].altitude) {
 	    largest = left;
    }

 	if (right > 0 && right < this->get_size() && this->keys[right].altitude > this->keys[largest].altitude) {
 	   largest = right;
    }

 	if (largest != i) {
 	   this->swap(i, largest);
 	   this->heapify(largest);
    }
}

void PriorityQueue::swap(int i, int j) {
    std::iter_swap(keys.begin() + i, keys.begin() + j);
}

int PriorityQueue::left(int i) {
    if (i == 0) {
        return -1;
    }

    return 2*i + 1;
}

int PriorityQueue::right(int i) {
    if (i == 0) {
        return -1;
    }

    return 2*i + 2;
}

int PriorityQueue::parent(int i) {
    if (i % 2 == 0) { // right child
        return (i - 2) / 2;
    } else { // left child
        return (i - 1) / 2;
    }
}

PriorityQueue::PriorityQueue() = default;
