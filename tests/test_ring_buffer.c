#include <stdio.h>
#include <assert.h>
#include "ring_buffer.h"

static void test_init_is_empty(void) {
    RingBuffer_t rb;
    RingBuffer_Init(&rb);
    assert(RingBuffer_IsEmpty(&rb) == true);
    assert(RingBuffer_IsFull(&rb)  == false);
    printf("PASS: test_init_is_empty\n");
}

static void test_push_pop(void) {
    RingBuffer_t rb;
    RingBuffer_Init(&rb);
    float out = 0.0f;

    assert(RingBuffer_Push(&rb, 1.5f) == true);
    assert(RingBuffer_Push(&rb, 2.5f) == true);
    assert(RingBuffer_Pop(&rb, &out)  == true);
    assert(out == 1.5f);
    assert(RingBuffer_Pop(&rb, &out)  == true);
    assert(out == 2.5f);
    printf("PASS: test_push_pop\n");
}

static void test_full_rejects_push(void) {
    RingBuffer_t rb;
    RingBuffer_Init(&rb);

    for (uint8_t i = 0U; i < RING_BUFFER_SIZE; i++) {
        assert(RingBuffer_Push(&rb, (float)i) == true);
    }
    assert(RingBuffer_IsFull(&rb)       == true);
    assert(RingBuffer_Push(&rb, 99.0f)  == false);
    printf("PASS: test_full_rejects_push\n");
}

static void test_empty_rejects_pop(void) {
    RingBuffer_t rb;
    float out = 0.0f;
    RingBuffer_Init(&rb);
    assert(RingBuffer_Pop(&rb, &out) == false);
    printf("PASS: test_empty_rejects_pop\n");
}

int main(void) {
    test_init_is_empty();
    test_push_pop();
    test_full_rejects_push();
    test_empty_rejects_pop();
    printf("\nAll tests passed.\n");
    return 0;
}
