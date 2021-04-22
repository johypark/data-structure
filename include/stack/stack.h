// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#ifndef STACK_STACK_H_
#define STACK_STACK_H_

#include <stdbool.h>
#include <stdio.h>

typedef int Element;

typedef struct {
  Element* data;
  size_t capacity;
  size_t size;
} Stack;

Stack* create_stack(size_t capacity);
void extend_stack(Stack* stack);
void free_stack(Stack* stack);

bool is_stack_empty(Stack* stack);
bool is_stack_full(Stack* stack);
void check_stack_empty(Stack* stack);

void push_stack(Stack* stack, Element element);
Element pop_stack(Stack* stack);
Element peek_stack(Stack* stack);

#endif  // STACK_STACK_H_
