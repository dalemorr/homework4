#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <tuple>

class PriorityQueue {
    private:
        Node *head;
    public:
        void insert(AirportRecord *x);
        std::tuple<AirportRecord*, int> maximum();
        std::tuple<AirportRecord*, int> extractMax();
        void increaseKey(AirportRecord *x, int k);
};

class Node {
    private:
        Node *parent;
        Node *left;
        Node *right;
        AirportRecord* key;
};

#endif // PRIORITY_QUEUE_H
