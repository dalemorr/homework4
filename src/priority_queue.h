#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "airport_record.h"

#include <tuple>

class PriorityQueue {
    private:
        class Node {
            Node *parent;
            Node *left;
            Node *right;
            AirportRecord* key;
        };

        Node *head;
    public:
        void insert(AirportRecord *rec);
        std::tuple<AirportRecord*, int> maximum();
        std::tuple<AirportRecord*, int> extractMax();
        void increaseKey(AirportRecord *rec, int k);
};

#endif // PRIORITY_QUEUE_H
