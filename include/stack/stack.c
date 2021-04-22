// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#include <stack/stack.h>
#include <stdlib.h>

Stack* create_stack(size_t capacity) {
  Stack* stack = malloc(sizeof(Stack));

  stack->data = malloc(sizeof(Element) * capacity);
  stack->capacity = capacity;
  stack->size = 0;

  return stack;
}

void extend_stack(Stack* stack) {
  stack->capacity *= 2;
  stack->data = realloc(stack->data, sizeof(Element) * stack->capacity);
}

void free_stack(Stack* stack) {
  free(stack->data);
  free(stack);
}

bool is_stack_empty(Stack* stack) { return stack->size == 0; }

bool is_stack_full(Stack* stack) { return stack->size == stack->capacity; }

void check_stack_empty(Stack* stack) {
  if (is_stack_empty(stack)) {
    fprintf(stderr, "Stack is empty.\n");
    exit(EXIT_FAILURE);
  }
}

void push_stack(Stack* stack, Element element) {
  if (is_stack_full(stack)) extend_stack(stack);

  stack->data[stack->size++] = element;
}

Element pop_stack(Stack* stack) {
  check_stack_empty(stack);

  return stack->data[--stack->size];
}

Element peek_stack(Stack* stack) {
  check_stack_empty(stack);

  return stack->data[stack->size - 1];
}
