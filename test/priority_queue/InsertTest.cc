#include <gtest/gtest.h>
#include "../../src/priority_queue/priority_queue.cc"


namespace {
    TEST (Insert, TEST1_EmptyHeap) {
        auto queue = new PriorityQueue();

        AirportRecord rec = {
            "",
            "",
            "",
            "",
            0, 0, 0,
            "",
            0, 0, 0,
            ""
        }
        queue->insert(rec);

        ASSERT_EQ("[1]", queue->toString());
        ASSERT_EQ(1, queue->get_size());
    }
}
