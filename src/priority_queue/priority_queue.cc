#include "priority_queue.h"
#include "../airport_record/airport_record.h"

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
    keys.push_back(rec);

    int i = this->keys.size() - 1;
    while (i != 0 && this->keys[parent(i)] < rec) {
        swap(i, this->parent(i));
        i = parent(i);
    }
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

int get_size() {
    return this->keys.size();
}

void PriorityQueue::heapify(int i) {
    int left = this->left(i);
 	int right = this->right(i);
    int largest;

 	if (left <= this->keys.size() - 1 && this->keys[left] > this->keys[i]) {
 	    largest = left;
    } else {
        largest = i;
    }

 	if (right <= this->keys.size() - 1 && this->keys[right] > this->keys[largest]) {
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
    return 2*i + 1;
}

int PriorityQueue::right(int i) {
    return 2*i + 2;
}

int PriorityQueue::parent(int i) {
    if (i % 2 == 0) { // right child
        return (i - 2) / 2;
    } else { // left child
        return (i - 1) / 2;
    }
}
