// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#include <deque/deque.h>
#include <stdlib.h>

Deque* create_deque(size_t capacity) {
  Deque* deque = malloc(sizeof(Deque));

  deque->data = malloc(sizeof(Element) * capacity);
  deque->capacity = capacity;
  deque->size = 0;
  deque->front = deque->rear = capacity - 1;

  return deque;
}

void extend_deque(Deque* deque) {
  size_t old_capacity = deque->capacity;

  deque->capacity *= 2;
  deque->data = realloc(deque->data, sizeof(Element) * deque->capacity);

  for (size_t i = deque->front + 1; i < old_capacity; i++)
    deque->data[i + old_capacity] = deque->data[i];

  deque->front += old_capacity;
}

void free_deque(Deque* deque) {
  free(deque->data);
  free(deque);
}

bool is_deque_empty(Deque* deque) { return deque->size == 0; }

bool is_deque_full(Deque* deque) { return deque->size == deque->capacity; }

void check_deque_empty(Deque* deque) {
  if (is_deque_empty(deque)) {
    fprintf(stderr, "Deque is empty\n");
    exit(EXIT_FAILURE);
  }
}

void push_deque_front(Deque* deque, Element element) {
  if (is_deque_full(deque)) extend_deque(deque);

  deque->size++;
  deque->data[deque->front] = element;

  if (deque->front == 0)
    deque->front = deque->capacity - 1;
  else
    deque->front--;
}

void push_deque_back(Deque* deque, Element element) {
  if (is_deque_full(deque)) extend_deque(deque);

  deque->size++;
  deque->rear = (deque->rear + 1) % deque->capacity;
  deque->data[deque->rear] = element;
}

Element pop_deque_front(Deque* deque) {
  check_deque_empty(deque);

  deque->size--;
  deque->front = (deque->front + 1) % deque->capacity;

  return deque->data[deque->front];
}

Element pop_deque_back(Deque* deque) {
  check_deque_empty(deque);

  size_t old_rear = deque->rear;

  deque->size--;
  if (deque->rear == 0)
    deque->rear = deque->capacity - 1;
  else
    deque->rear--;

  return deque->data[old_rear];
}

Element peek_deque_front(Deque* deque) {
  check_deque_empty(deque);

  return deque->data[(deque->front + 1) % deque->capacity];
}

Element peek_deque_back(Deque* deque) {
  check_deque_empty(deque);

  return deque->data[deque->rear];
}
