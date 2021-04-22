// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#include <list/list.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  size_t add_first, remove_last;

  printf("Enter add first count: ");
  scanf("%zu", &add_first);

  printf("Enter remove last count: ");
  scanf("%zu", &remove_last);

  List* list = create_list();

  for (int i = 1; i <= add_first; i++) {
    add_list_node_at_first(list, i);
    printf("add %d\n", i);
  }

  for (size_t i = 0; i < remove_last; i++)
    printf("remove %d\n", remove_list_node_at_last(list));

  free_list(list);
}
