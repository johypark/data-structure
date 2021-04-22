// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#ifndef DEQUE_DEQUE_H_
#define DEQUE_DEQUE_H_

#include <stdbool.h>
#include <stdio.h>

typedef int Element;

typedef struct {
  Element* data;
  size_t capacity;
  size_t size;
  size_t front, rear;
} Deque;

Deque* create_deque(size_t capacity);
void extend_deque(Deque* deque);
void free_deque(Deque* deque);

bool is_deque_empty(Deque* deque);
bool is_deque_full(Deque* deque);
void check_deque_empty(Deque* deque);

void push_deque_front(Deque* deque, Element element);
void push_deque_back(Deque* deque, Element element);
Element pop_deque_front(Deque* deque);
Element pop_deque_back(Deque* deque);
Element peek_deque_front(Deque* deque);
Element peek_deque_back(Deque* deque);

#endif  // DEQUE_DEQUE_H_
