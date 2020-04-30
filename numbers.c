#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define MAIN_MENU "Main Menu\n\
---------\n\
(a) add a number to the end of the list\n\
(b) add a number to the start of the list\n\
(c) insert a number at a given position in the list\n\
(d) add a unique item on the list at the end(if it already exists, do not insert)\n\
(e) remove a number from the beginning of the list\n\
(f) remove a number from the end of the list\n\
(g) remove a number from a given position in the list\n\
(h) remove first occurrence of a number\n\
(i) remove all occurrences of a number\n\
(j) clear the whole list\n\
(k) check if a number exists in the list\n\
(l) display the list of numbers\n\
(m) exit\n\n\
Please enter the alphabet of the operation you would like to perform\n"
#define INPUT_TEXT_FOR_VALUE "Please enter a number:"

void read_option(char *option);
void do_operation_by_getting_option(List_ptr list);
void do_operation(List_ptr list, char option);
void read_value(char *text, int *value);
void display_result(unsigned int status);

void read_value(char *text, int *value)
{
  printf("%s\n", text);
  scanf("%d", value);
}

void do_operation(List_ptr list, char option)
{
  int value = 0;
  unsigned int status;
  switch (option)
  {
  case 'a':
    read_value(INPUT_TEXT_FOR_VALUE, &value);
    status = add_to_end(list, value);
    break;
  case 'b':
    read_value(INPUT_TEXT_FOR_VALUE, &value);
    status = add_to_start(list, value);
    break;
  }
  display_result(status);
  display(list);
}

void display_result(unsigned int status)
{
  if (status == 1)
  {
    printf("Completed\n\n");
  }
  else
  {
    printf("Failed\n\n");
  }
}

void read_option(char *option)
{
  printf("%s", MAIN_MENU);
  *option = getchar();
}

void do_operation_by_getting_option(List_ptr list)
{
  char option;
  read_option(&option);
  while (option != 'm')
  {
    do_operation(list, option);
    while ((getchar()) != '\n')
      ;
    read_option(&option);
  }
}

int main(void)
{
  List_ptr list = create_list();
  do_operation_by_getting_option(list);
  return 0;
}