#include "../../src/priority_queue/priority_queue.cc"
#include "../../src/airport_record/airport_record.cc"

#include <gtest/gtest.h>
#include <vector>

namespace {
    TEST(Insert, TEST1_EmptyHeap) {
        PriorityQueue *queue = new PriorityQueue();

        AirportRecord rec = {
            "",
            "",
            "",
            "",
            0, 0, 0,
            "",
            0, 0, 0,
            "",
            0
        }

        queue->insert(1);

        ASSERT_EQ("[1]", heap->toString());
        ASSERT_EQ(1, heap->get_size());
    }
}
