#include <gtest/gtest.h>
#include "../../src/priority_queue/priority_queue.cc"


namespace {
    TEST (Insert, TEST1_EmptyHeap) {
        auto queue = new PriorityQueue();

        AirportRecord *rec = new AirportRecord(
            "",
            "",
            "",
            "",
            0, 0, 0,
            "",
            0, 0, 0,
            "",
            10
        );
        queue->insert(*rec);

        ASSERT_EQ(10, queue->maximum());
        ASSERT_EQ(1, queue->get_size());
    }
}
