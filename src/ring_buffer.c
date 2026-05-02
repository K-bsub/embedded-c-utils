#include "ring_buffer.h"

void RingBuffer_Init(RingBuffer_t *rb) {
    rb->head  = 0U;
    rb->tail  = 0U;
    rb->count = 0U;
}

bool RingBuffer_IsFull(const RingBuffer_t *rb) { return (rb->count == RING_BUFFER_SIZE); }

bool RingBuffer_IsEmpty(const RingBuffer_t *rb) { return (rb->count == 0U); }

bool RingBuffer_Push(RingBuffer_t *rb, float value) {
    if (RingBuffer_IsFull(rb)) {
        return false;
    }
    rb->data[rb->head] = value;
    rb->head           = (uint8_t)((rb->head + 1U) % RING_BUFFER_SIZE);
    rb->count++;
    return true;
}

bool RingBuffer_Pop(RingBuffer_t *rb, float *out) {
    if (RingBuffer_IsEmpty(rb)) {
        return false;
    }
    *out     = rb->data[rb->tail];
    rb->tail = (uint8_t)((rb->tail + 1U) % RING_BUFFER_SIZE);
    rb->count--;
    return true;
}
