#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

#define RING_BUFFER_SIZE 16U

typedef struct {
    float     data[RING_BUFFER_SIZE];
    uint8_t   head;
    uint8_t   tail;
    uint8_t   count;
} RingBuffer_t;

void  RingBuffer_Init(RingBuffer_t *rb);
bool  RingBuffer_Push(RingBuffer_t *rb, float value);
bool  RingBuffer_Pop(RingBuffer_t *rb, float *out);
bool  RingBuffer_IsFull(const RingBuffer_t *rb);
bool  RingBuffer_IsEmpty(const RingBuffer_t *rb);

#endif /* RING_BUFFER_H */
