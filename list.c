#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void display(List_ptr list)
{
  printf("List is : ");
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    printf("%d ", p_walk->value);
    p_walk = p_walk->next;
  }
  printf("\n\n");
}

List_ptr create_list(void)
{
  List_ptr list = malloc(sizeof(List));
  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return list;
}

Node_ptr create_node(int value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

Status add_in_empty_list(List_ptr list, Node_ptr new_node)
{
  if (list->head == NULL)
  {
    list->head = new_node;
    list->last = new_node;
    return Success;
  }
  return Failure;
}

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (!add_in_empty_list(list, new_node))
  {
    list->last->next = new_node;
    list->last = new_node;
  }
  list->count++;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (!add_in_empty_list(list, new_node))
  {
    Node_ptr start_node = list->head;
    list->head = new_node;
    list->head->next = start_node;
  }
  list->count++;
  return Success;
}

Status insert_at(List_ptr list, int value, int position)
{
  if (position != 0)
  {
    Prev_Current_Pair pair = {NULL, list->head};
    int count = 0;
    while (count < list->count)
    {
      if (count == position)
      {
        Node_ptr new_node = create_node(value);
        pair.prev->next = new_node;
        new_node->next = pair.current;
        list->count++;
        return Success;
      }
      pair.prev = pair.current;
      pair.current = pair.current->next;
      count++;
    }
    if(position == count){
      return add_to_end(list, value);
    }
    return Failure;
  }
  return add_to_start(list, value);
}

Status add_unique(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  while (p_walk != NULL)
  {
    if (value == p_walk->value)
    {
      return Failure;
    }
    p_walk = p_walk->next;
  }
  return add_to_end(list, value);
}

Status remove_from_empty_list(Node_ptr node)
{
  if (node == NULL)
  {
    return Failure;
  }
  return Success;
}

Status remove_from_start(List_ptr list)
{
  if (remove_from_empty_list(list->head))
  {
    Node_ptr next_node = list->head->next;
    if (list->count == 1)
    {
      list->last = next_node;
    }
    list->head = next_node;
    list->count--;
    return Success;
  }
  return Failure;
}

Status remove_from_end(List_ptr list)
{
  if (list->count != 1 && list->count != 0)
  {
    int count = 1;
    Node_ptr p_walk = list->head;
    while (p_walk != NULL)
    {
      if (count == list->count - 1)
      {
        p_walk->next = NULL;
        list->last = p_walk;
        list->count--;
      }
      p_walk = p_walk->next;
      count++;
    }
    return Success;
  }
  return remove_from_start(list);
}

Status remove_number_at(List_ptr list, int position)
{
  Prev_Current_Pair pair = {NULL, list->head};
  int count = 0;
  while (count < list->count)
  {
    if (count == position)
    {
      pair.prev->next = pair.current->next;
      list->count--;
      return Success;
    }
    pair.prev = pair.current;
    pair.current = pair.current->next;
    count++;
  }
  return Failure;
}

Status remove_at(List_ptr list, int position)
{
  if (position == 0)
  {
    return remove_from_start(list);
  }
  if (position == list->count - 1)
  {
    return remove_from_end(list);
  }
  return remove_number_at(list, position);
}

int search_position(List_ptr list, int value)
{
  Node_ptr p_walk = list->head;
  int position = 0;
  while (p_walk != NULL)
  {
    if (p_walk->value == value)
    {
      return position;
    }
    p_walk = p_walk->next;
    position++;
  }
  return -1;
}

Status remove_first_occurrence(List_ptr list, int value)
{
  int position = search_position(list, value);
  if (position != -1)
  {
    return remove_at(list, position);
  }
  return Failure;
}

Status check_is_exist(List_ptr list, int value)
{
  int position = search_position(list, value);
  if (position != -1)
  {
    return Success;
  }
  return Failure;
}

Status remove_all_occurrences(List_ptr list, int value)
{
  int count = 0;
  int position;
  if (check_is_exist(list, value))
  {
    while (count < list->count)
    {
      position = search_position(list, value);
      remove_at(list, position);
      if (position == -1)
        return Success;
    }
  }
  return Failure;
}

Status clear_list(List_ptr list)
{
  if(list->head == NULL){
    return Failure;
  }
  
  Node_ptr p_walk = list->head;
  Node_ptr node_to_free = NULL;

  while(p_walk != NULL){
    node_to_free = p_walk;
    p_walk = p_walk->next;
    free(node_to_free);
  }

  list->head = NULL;
  list->last = NULL;
  list->count = 0;
  return Success;
}

void destroy_list(List_ptr list)
{
  Node_ptr p_walk = list->head;
  Node_ptr node_to_free = NULL;
  while (p_walk != NULL)
  {
    node_to_free = p_walk;
    p_walk = p_walk->next;
    free(node_to_free);
  }
  free(list);
}