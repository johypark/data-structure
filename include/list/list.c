// Copyright 2021 Johy. All rights reserved.
// Licensed under the MIT License.
// See LICENSE file in the project root for license information.

#include <list/list.h>
#include <stdlib.h>

List* create_list() {
  List* list = malloc(sizeof(List));

  list->size = 0;
  list->head = list->tail = NULL;

  return list;
}

void free_list(List* list) {
  ListNode* node = list->head;
  ListNode* prev_node;

  while (node != NULL) {
    prev_node = node;
    node = node->next;
    free(prev_node);
  }

  free(list);
}

bool is_list_empty(List* list) { return list->size == 0; }

void check_list_empty(List* list) {
  if (is_list_empty(list)) {
    fprintf(stderr, "List is empty.\n");
    exit(EXIT_FAILURE);
  }
}

ListNode* find_list_node(List* list, size_t index) {
  ListNode* node;

  if (index < list->size / 2) {
    node = list->head;
    for (size_t i = 0; i < index; i++) node = node->next;
  } else {
    node = list->tail;
    for (size_t i = list->size - 1; i > index; i--) node = node->prev;
  }

  return node;
}

void add_list_node_at_first(List* list, Element element) {
  ListNode* node = malloc(sizeof(ListNode));

  node->data = element;
  node->prev = NULL;
  node->next = list->head;

  if (is_list_empty(list))
    list->tail = node;

  else
    list->head->prev = node;

  list->head = node;
  list->size++;
}

void add_list_node_at_last(List* list, Element element) {
  ListNode* node = malloc(sizeof(ListNode));

  node->data = element;
  node->prev = list->tail;
  node->next = NULL;

  if (is_list_empty(list))
    list->head = node;
  else
    list->tail->next = node;

  list->tail = node;
  list->size++;
}

void add_list_node(List* list, size_t index, Element element) {
  if (index > list->size) {
    fprintf(stderr, "Wrong Index\n");
    exit(EXIT_FAILURE);
  }

  if (index == 0) {
    add_list_node_at_first(list, element);
  } else if (index == list->size) {
    add_list_node_at_last(list, element);
  } else {
    ListNode* node = malloc(sizeof(ListNode));

    node->data = element;
    node->prev = find_list_node(list, index - 1);
    node->next = node->prev->next;

    node->prev->next = node;
    node->next->prev = node;

    list->size++;
  }
}

Element remove_list_node_at_first(List* list) {
  check_list_empty(list);

  ListNode* old_head = list->head;
  Element element = old_head->data;

  list->head = list->head->next;
  list->size--;

  if (is_list_empty(list))
    list->tail = NULL;
  else
    list->head->prev = NULL;

  free(old_head);
  return element;
}

Element remove_list_node_at_last(List* list) {
  check_list_empty(list);

  ListNode* old_tail = list->tail;
  Element element = old_tail->data;

  list->tail = list->tail->prev;
  list->size--;

  if (is_list_empty(list))
    list->head = NULL;
  else
    list->tail->next = NULL;

  free(old_tail);
  return element;
}

Element remove_list_node(List* list, size_t index) {
  if (index >= list->size) {
    fprintf(stderr, "Wrong Index.\n");
    exit(EXIT_FAILURE);
  }

  if (index == 0) {
    return remove_list_node_at_first(list);
  } else if (index == list->size - 1) {
    return remove_list_node_at_last(list);
  } else {
    ListNode* node = find_list_node(list, index);
    Element element = node->data;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    list->size--;

    free(node);
    return element;
  }
}
