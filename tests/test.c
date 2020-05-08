#include <stdio.h>
#include "../list.h"
#include "test.h"

int assert(int actual, int expected)
{
  return actual == expected;
}

void display_pass_or_fail(int status)
{
  status ? printf(PASS) : printf(FAIL);
  status ? PASSING_TESTS++ : FAILING_TESTS++;
}

void test_clear_list(List_ptr list)
{
  add_to_end(list, 1);

  PRINT_STRING("\nclear_list");

  int status = assert(clear_list(list), Success);
  status = status && assert(list->count, 0);
  display_pass_or_fail(status);
  PRINT_STRING("should clear the list and set to zero");

  status = assert(clear_list(list), Failure);
  status = status && assert(list->count, 0);
  display_pass_or_fail(status);
  PRINT_STRING("should not clear the list if it is an empty list");
}

void test_search_node(List_ptr list)
{
  add_to_end(list, 1);

  PRINT_STRING("\nsearch_node");

  int status = assert(search_position(list, 1), 0);
  display_pass_or_fail(status);
  PRINT_STRING("should give the position if the item is present in the list");

  status = assert(search_position(list, 2), -1);
  display_pass_or_fail(status);
  PRINT_STRING("should give -1 if the item is not present in the list");

  clear_list(list);
}

void test_add_to_end(List_ptr list)
{
  PRINT_STRING("\nadd_to_end");

  int status = assert(add_to_end(list, 1), Success);
  status = status && assert(search_position(list, 1), 0);
  status = status && assert(list->count, 1);
  display_pass_or_fail(status);
  PRINT_STRING("should add the given number at the beginning if list is empty of the list");

  status = assert(add_to_end(list, 2), Success);
  status = status && assert(search_position(list, 2), 1);
  status = status && assert(list->count, 2);
  display_pass_or_fail(status);
  PRINT_STRING("should add the given number at the end of the list");

  clear_list(list);
}

void test_add_to_start(List_ptr list)
{
  PRINT_STRING("\nadd_to_start");

  int status = assert(add_to_start(list, 1), Success);
  status = status && assert(search_position(list, 1), 0);
  status = status && assert(list->count, 1);
  display_pass_or_fail(status);
  PRINT_STRING("should add the given number at the beginning of the list and make both head and last points the same node if list is empty");

  status = assert(add_to_start(list, 0), Success);
  status = status && assert(search_position(list, 0), 0);
  status = status && assert(list->count, 2);
  display_pass_or_fail(status);
  PRINT_STRING("should add the given number at the beginning of the list and modify nodes next if list is not empty");

  clear_list(list);
}

void test_add_unique(List_ptr list)
{
  PRINT_STRING("\nadd_unique");

  int status = assert(add_unique(list, 1), Success);
  status = status && assert(search_position(list, 1), 0);
  status = status && assert(list->count, 1);
  display_pass_or_fail(status);
  PRINT_STRING("should add the given number in the list if not exists");

  status = assert(add_unique(list, 1), Failure);
  status = status && assert(search_position(list, 1), 0);
  status = status && assert(list->count, 1);
  display_pass_or_fail(status);
  PRINT_STRING("should not add the given number in the list if exists");

  clear_list(list);
}

void test_insert_at(List_ptr list)
{
  add_to_end(list, 1);
  add_to_end(list, 2);

  PRINT_STRING("\ninsert_at");

  int status = assert(insert_at(list, 3, 2), Success);
  status = status && assert(search_position(list, 3), 2);
  status = status && assert(list->count, 3);
  display_pass_or_fail(status);
  PRINT_STRING("should add the given number at the end of the list");

  status = assert(insert_at(list, 0, 0), Success);
  status = status && assert(search_position(list, 0), 0);
  status = status && assert(list->count, 4);
  display_pass_or_fail(status);
  PRINT_STRING("should add the given number at the beginning of the list");

  status = assert(insert_at(list, 6, 2), Success);
  status = status && assert(search_position(list, 6), 2);
  status = status && assert(list->count, 5);
  display_pass_or_fail(status);
  PRINT_STRING("should add the given number at the given position of the list");

  status = assert(insert_at(list, 9, 9), Failure);
  status = status && assert(search_position(list, 9), -1);
  status = status && assert(list->count, 5);
  display_pass_or_fail(status);
  PRINT_STRING("should not add the given number if the given position is below 0");

  status = assert(insert_at(list, 9, -9), Failure);
  status = status && assert(search_position(list, 9), -1);
  status = status && assert(list->count, 5);
  display_pass_or_fail(status);
  PRINT_STRING("should not add the given number if the given position is above list count");

  clear_list(list);
}

void test_remove_from_end(List_ptr list)
{
  add_to_end(list, 1);
  add_to_end(list, 2);

  PRINT_STRING("\nremove_from_end");

  int status = assert(remove_from_end(list), Success);
  status = status && assert(list->count, 1);
  display_pass_or_fail(status);
  PRINT_STRING("should remove the last item from the list");

  status = assert(remove_from_end(list), Success);
  status = status && assert(list->count, 0);
  display_pass_or_fail(status);
  PRINT_STRING("should remove the first item from the list if there is only one item");

  status = assert(remove_from_end(list), Failure);
  status = status && assert(list->count, 0);
  display_pass_or_fail(status);
  PRINT_STRING("should not remove the item from the list if the list is empty");

  clear_list(list);
}

void test_remove_from_start(List_ptr list)
{
  add_to_end(list, 1);

  PRINT_STRING("\nremove_from_start");

  int status = assert(remove_from_end(list), Success);
  status = status && assert(list->count, 0);
  display_pass_or_fail(status);
  PRINT_STRING("should remove the first item from the list");

  status = assert(remove_from_end(list), Failure);
  status = status && assert(list->count, 0);
  display_pass_or_fail(status);
  PRINT_STRING("should not remove the item from the list if the list is empty");

  clear_list(list);
}

void test_remove_at(List_ptr list)
{
  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 4);
  add_to_end(list, 5);

  PRINT_STRING("\nremove_at");

  int status = assert(remove_at(list, 4), Success);
  status = status && assert(list->count, 4);
  display_pass_or_fail(status);
  PRINT_STRING("should remove the given number at the end of the list");

  status = assert(remove_at(list, 0), Success);
  status = status && assert(list->count, 3);
  display_pass_or_fail(status);
  PRINT_STRING("should remove the given number at the beginning of the list");

  status = assert(remove_at(list, 1), Success);
  status = status && assert(list->count, 2);
  display_pass_or_fail(status);
  PRINT_STRING("should remove the given number at the given position of the list");

  status = assert(remove_at(list, 9), Failure);
  status = status && assert(list->count, 2);
  display_pass_or_fail(status);
  PRINT_STRING("should not remove the given number if the given position is below 0");

  status = assert(remove_at(list, -9), Failure);
  status = status && assert(list->count, 2);
  display_pass_or_fail(status);
  PRINT_STRING("should not remove the given number if the given position is above list count");

  clear_list(list);
}

void test_remove_first_occurrence(List_ptr list)
{
  add_to_end(list, 1);
  add_to_end(list, 2);

  PRINT_STRING("\nremove_first_occurrence");

  int status = assert(remove_first_occurrence(list, 1), Success);
  status = status && assert(search_position(list, 1), -1);
  status = status && assert(list->count, 1);
  display_pass_or_fail(status);
  PRINT_STRING("should remove first occurrence of the given number in the list if exists");

  status = assert(remove_first_occurrence(list, 1), Failure);
  status = status && assert(search_position(list, 1), -1);
  status = status && assert(list->count, 1);
  display_pass_or_fail(status);
  PRINT_STRING("should not remove first occurrence of the given number in the list if not exists");

  clear_list(list);
}

void test_remove_all_occurrences(List_ptr list)
{
  add_to_end(list, 1);
  add_to_end(list, 2);
  add_to_end(list, 3);
  add_to_end(list, 1);

  PRINT_STRING("\nremove_all_occurrences");

  int status = assert(remove_all_occurrences(list, 1), Success);
  status = status && assert(search_position(list, 1), -1);
  status = status && assert(list->count, 2);
  display_pass_or_fail(status);
  PRINT_STRING("should remove all occurrences of the given number in the list if exists");

  status = assert(remove_all_occurrences(list, 1), Failure);
  status = status && assert(search_position(list, 1), -1);
  status = status && assert(list->count, 2);
  display_pass_or_fail(status);
  PRINT_STRING("should not remove all occurrences of the given number in the list if not exists");

  clear_list(list);
}

int main(void)
{
  List_ptr list = create_list();
  if (list == NULL)
  {
    PRINT_STRING("Memory_Not_Available");
    return 0;
  }

  test_clear_list(list);
  test_search_node(list);

  test_add_to_end(list);
  test_add_to_start(list);
  test_add_unique(list);
  test_insert_at(list);

  test_remove_from_end(list);
  test_remove_from_start(list);
  test_remove_at(list);

  test_remove_first_occurrence(list);
  test_remove_all_occurrences(list);

  printf(GREEN "\n%d passing" RESET, PASSING_TESTS);
  printf(RED "\n%d failing\n" RESET, FAILING_TESTS);

  return 0;
}