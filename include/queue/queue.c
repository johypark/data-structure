// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#include <queue/queue.h>
#include <stdlib.h>

Queue* create_queue(size_t capacity) {
  Queue* queue = malloc(sizeof(Queue));

  queue->data = malloc(sizeof(Element) * capacity);
  queue->capacity = capacity;
  queue->size = 0;
  queue->front = queue->rear = capacity - 1;

  return queue;
}

void extend_queue(Queue* queue) {
  size_t old_capacity = queue->capacity;

  queue->capacity *= 2;
  queue->data = realloc(queue->data, sizeof(Element) * queue->capacity);

  for (size_t i = queue->front + 1; i < old_capacity; i++)
    queue->data[i + old_capacity] = queue->data[i];

  queue->front += old_capacity;
}

void free_queue(Queue* queue) {
  free(queue->data);
  free(queue);
}

bool is_queue_empty(Queue* queue) { return queue->size == 0; }

bool is_queue_full(Queue* queue) { return queue->size == queue->capacity; }

void check_queue_empty(Queue* queue) {
  if (is_queue_empty(queue)) {
    fprintf(stderr, "Queue is empty.\n");
    exit(EXIT_FAILURE);
  }
}

void en_queue(Queue* queue, Element element) {
  if (is_queue_full(queue)) extend_queue(queue);

  queue->size++;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->data[queue->rear] = element;
}

Element de_queue(Queue* queue) {
  check_queue_empty(queue);

  queue->size--;
  queue->front = (queue->front + 1) % queue->capacity;

  return queue->data[queue->front];
}

Element peek_queue(Queue* queue) {
  check_queue_empty(queue);

  return queue->data[(queue->front + 1) % queue->capacity];
}
