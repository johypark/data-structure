// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#include <stack/stack.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  size_t capacity, push_count, pop_count;

  printf("Enter stack capacity: ");
  scanf(" %zu", &capacity);

  printf("Enter push count: ");
  scanf(" %zu", &push_count);

  printf("Enter pop count: ");
  scanf(" %zu", &pop_count);

  Stack* stack = create_stack(capacity);

  for (int i = 1; i <= push_count; i++) {
    push_stack(stack, i);
    printf("Push %d, Capacity: %zu\n", i, stack->capacity);
  }

  for (size_t i = 0; i < pop_count; i++) printf("Pop %d\n", pop_stack(stack));

  free_stack(stack);
}
