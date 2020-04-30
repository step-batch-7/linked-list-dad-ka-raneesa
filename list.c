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

Status add_to_end(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
  {
    list->head = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->count++;
  return Success;
}

Status add_to_start(List_ptr list, int value)
{
  Node_ptr new_node = create_node(value);
  if (list->head == NULL)
  {
    list->head = new_node;
    list->last = new_node;
  }
  else
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
  Node_ptr first_node = NULL;
  Node_ptr second_node = list->head;
  int count = 0;

  while (count <= list->count)
  {
    if (count == position - 1)
    {
      if (position != 1)
      {
        Node_ptr new_node = create_node(value);
        first_node->next = new_node;
        new_node->next = second_node;
        list->count++;
      }
      else
      {
        add_to_start(list, value);
      }
      return Success;
    }
    first_node = second_node;
    second_node = second_node->next;
    count++;
  }
  return Failure;
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