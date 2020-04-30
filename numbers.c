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

void read_option(char *option);
void getting_options(List_ptr list);
void do_operation();

void do_operation(List_ptr list, char option)
{
}

void read_option(char *option)
{
  printf("%s", MAIN_MENU);
  scanf("%c", option);
}

void getting_options(List_ptr list)
{
  char option;
  read_option(&option);
  while (option != 'm')
  {
    do_operation(list, option);
    read_option(&option);
  }
}

int main(void)
{
  List_ptr list = create_list();
  getting_options(list);
  return 0;
}