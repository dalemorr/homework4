#include "priority_queue.h"
#include "airport_record.h"

#include <algorithm>

using namespace std;

PriorityQueue::PriorityQueue(vector<AirportRecord> vec) {
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

tuple<AirportRecord, int> PriorityQueue::maximum() {
    AirportRecord rec = this->keys.front();
    return make_tuple(rec, rec.altitude);
}

tuple<AirportRecord, int> PriorityQueue::extractMax() {
    auto max = this->maximum();

    this->keys.erase(this->keys.begin());
    this->heapify();

    return max;
}

void PriorityQueue::heapify() {

}
