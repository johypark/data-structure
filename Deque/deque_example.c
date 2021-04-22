// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#include <deque/deque.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  size_t capacity, push_front_count, pop_back_count;

  printf("Enter deque capacity: ");
  scanf("%zu", &capacity);

  printf("Enter push front count: ");
  scanf("%zu", &push_front_count);

  printf("Enter pop back count: ");
  scanf("%zu", &pop_back_count);

  Deque* deque = create_deque(capacity);

  for (int i = 1; i <= push_front_count; i++) {
    push_deque_front(deque, i);
    printf("Endeque %d, Capacity: %zu\n", i, deque->capacity);
  }

  for (size_t i = 0; i < pop_back_count; i++)
    printf("Dedeque %d\n", pop_deque_back(deque));

  free_deque(deque);
}
