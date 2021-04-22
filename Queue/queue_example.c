// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#include <queue/queue.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  size_t capacity, enqueue_count, dequeue_count;

  printf("Enter queue capacity: ");
  scanf(" %zu", &capacity);

  printf("Enter enqueue count: ");
  scanf(" %zu", &enqueue_count);

  printf("Enter dequeue count: ");
  scanf(" %zu", &dequeue_count);

  Queue* queue = create_queue(capacity);

  for (int i = 1; i <= enqueue_count; i++) {
    en_queue(queue, i);
    printf("Enqueue %d, Capacity: %zu\n", i, queue->capacity);
  }

  for (size_t i = 0; i < dequeue_count; i++)
    printf("Dequeue %d\n", de_queue(queue));

  free_queue(queue);
}
