// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#ifndef LIST_LIST_H_
#define LIST_LIST_H_

#include <stdbool.h>
#include <stdio.h>

typedef int Element;

typedef struct ListNode {
  Element data;
  struct ListNode *prev, *next;
} ListNode;

typedef struct List {
  ListNode *head, *tail;
  size_t size;
} List;

List* create_list();
void free_list(List* list);

bool is_list_empty(List* list);
void check_list_empty(List* list);

ListNode* find_list_node(List* list, size_t index);

void add_list_node_at_first(List* list, Element element);
void add_list_node_at_last(List* list, Element element);
void add_list_node(List* list, size_t index, Element element);

Element remove_list_node_at_first(List* list);
Element remove_list_node_at_last(List* list);
Element remove_list_node(List* list, size_t index);

#endif  // LIST_LIST_H_
