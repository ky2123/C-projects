#include "newlinkedlist.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
void print_value(int* value) {
    printf("%d\n", *value);
}
void double_value(int* value) {
  *value *= 2; 
 }
bool is_even(int* value) {
 return *value % 2 == 0; 
}
int main() {
  struct List* atlist = create_list();
  append_front(atlist, 23);
  printf("%d\n", at(atlist, 0));
  append_back(atlist, 22);
  append_back(atlist, 9);
  printf("%d\n", at(atlist,0)); 
  printf("%d\n", at(atlist,1));


  struct List* poplist = duplicate(atlist);
  free_list(atlist);
  for_each(poplist, print_value);
  pop_back(poplist);
  pop_back(poplist);
  pop_front(poplist);
  append_back(poplist, 25);


  struct List* mainlist = create_list(); 
  free_list(poplist);
  insert(mainlist, 0, 60);
  printf("%d\n", at(mainlist,0));
  append_front(mainlist, 790);
  append_back(mainlist, 200);
  append_front(mainlist, 1000);
  append_back(mainlist, 3000);
  append_front(mainlist, 5999);
  append_back(mainlist, 808); // these 808 and 707 should not appear
  append_front(mainlist, 707);
  pop_front(mainlist);
  pop_back(mainlist);
  for_each(mainlist, print_value);
  free_list(mainlist);
  

  struct List* lista = create_list();
  append_front(lista, 202);

  struct List* listb = duplicate(lista);
  free_list(lista);
  printf("LIST B:");
  insert(listb, 1, 2002);
  insert(listb, 0, 9001);
  insert(listb, 3, 7005);
  for_each(listb, print_value);
  remove_elem(listb, 4);
  remove_elem(listb, 0);
  printf("listb.2 \n");
  remove_elem(listb, 1);
  for_each(listb, print_value);
  remove_elem(listb, 0);
  remove_elem(listb, 0);



  struct List* listc = duplicate(listb);  
  free_list(listb);
  append_front(listc, 200);
  append_back(listc, 3000); 
  remove_elem(listc, 1);
  remove_elem(listc, 0);
  append_back(listc, 100);
   
  
  struct List* listd = duplicate(listc);
  printf("%d\n", equals(listc, listd));
  append_back(listc, 700);
  append_back(listd, 700);
  printf("%d\n", equals(listc, listd));
  append_back(listc, 200);
  append_back(listd, 200);
  printf("%d\n", equals(listc, listd));
  pop_back(listc);
  printf("%d\n", equals(listc, listd));
  append_back(listd, 124097);
  append_back(listd, 12465320);
  printf("%d\n", equals(listc, listd)); 
  
  free_list(listc);
  free_list(listd);

  struct List* liste = create_list();
  struct List* listf = create_list();
  printf("%d\n", equals(liste, listf));
  for_each(liste, print_value);
  append_back(liste, 606);
  append_back(listf, 707);
  printf("%d\n", equals(liste, listf)); 
  append_back(liste, 638);
  append_back(listf, 723);
  printf("%d\n", equals(liste, listf));
  append_back(liste, 694);
  append_back(listf, 783);
  printf("%d\n", equals(liste, listf));
  struct List* emptylist = create_list();
  printf("%d\n", equals(liste, emptylist));

  printf("the contains method: \n");
  printf("%d\n", contains(liste, 606));
  printf("%d\n", contains(liste, 638));
  printf("%d\n", contains(liste, 694));
  printf("%d\n", contains(emptylist, 707));
  printf("%d\n", contains(listf, 606));
  
  free_list(liste);
  free_list(listf);
  free_list(emptylist);
  printf("the map methods: \n"); 
  struct List* dog = create_list();
  append_back(dog, 2);
  struct List* cat = map(dog, double_value);
  for_each(cat, print_value);
  append_back(cat, 3);
  struct List* dolphin = map(cat, double_value);
  for_each(dolphin, print_value);
  append_back(dolphin, 10);
  struct List* monkey = map(dolphin, double_value);
  for_each(monkey, print_value);
  free_list(dog);
  free_list(cat);
  free_list(dolphin);
  free_list(monkey);

  struct List* alpha = create_list();
  struct List* beta = map(alpha, double_value);
  for_each(beta, print_value);
  printf("two more contains: ");
  append_back(beta,7);
  printf("%d ", contains(beta,7));
  printf("%d  \n", contains(beta, 8)); 
  printf("filter testing: \n"); 
  struct List* charlie = filter(beta, is_even);  
  for_each(charlie, print_value);
  append_back(beta, 200);
  append_back(charlie, 2);
  struct List* delta = filter(beta, is_even);
  for_each(delta, print_value);
  append_back(delta,3);
  struct List* edward = filter(delta, is_even);
  for_each(edward, print_value);
  append_back(edward, 8);
  struct List* freddy = filter(edward, is_even);
  for_each(freddy, print_value);
  printf("filter testing part two\n");
  struct List* zed = create_list();
  append_back(zed, 10);
  append_back(zed, 13);
  append_back(zed, 12);
  append_back(zed, 14);
  append_back(zed, 19);
  struct List* yan = filter(zed, is_even);
  for_each(yan, print_value);

  
  free_list(zed);
  free_list(yan); 
  free_list(alpha);
  free_list(beta);
  free_list(charlie);
  free_list(delta);
  free_list(edward);
  free_list(freddy);
}

