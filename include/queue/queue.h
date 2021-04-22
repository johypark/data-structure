// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#ifndef QUEUE_QUEUE_H_
#define QUEUE_QUEUE_H_

#include <stdbool.h>
#include <stdio.h>

typedef int Element;

typedef struct {
  Element* data;
  size_t capacity;
  size_t size;
  size_t front, rear;
} Queue;

Queue* create_queue(size_t capacity);
void extend_queue(Queue* queue);
void free_queue(Queue* queue);

bool is_queue_empty(Queue* queue);
bool is_queue_full(Queue* queue);
void check_queue_empty(Queue* queue);

void en_queue(Queue* queue, Element element);
Element de_queue(Queue* queue);
Element peek_queue(Queue* queue);

#endif  // QUEUE_QUEUE_H_
