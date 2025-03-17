#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct Node {
  int value;
  struct Node* next;
};

struct List {
  struct Node* head;
  struct Node* tail;
};


struct List* create_list(void) {
  struct List* list = malloc(sizeof *list);
  if (list == NULL){
    return NULL;
  }
  *list = (struct List){0};
  return list;
}

void free_list(struct List* list) {
  if (list == NULL) {
    return; 
  }
  struct Node* current = list->head;
  while (current != NULL) {
    struct Node* next = current->next;
    free(current);
    current = next;
  }
  list->head = NULL;
  list->tail = NULL;
  free(list);
}

int at(struct List* list, int index) {
  int i = 0;
  struct Node* current = list->head;
  while(index > i){
    current = current->next;
    ++i;
  }
  return current->value;
}

void append_back(struct List* list, int value) {
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->value = value;
  new_node->next = NULL;
  if (list->tail == NULL || list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

void append_front(struct List* list, int value) {
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->value = value;
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
    new_node->next = NULL;
  } else {
  new_node->next = list->head;
  list->head = new_node;
}
}

int pop_front(struct List* list){
 struct Node* temp = list->head->next; 
 int return_value = list->head->value;
  free(list->head);
  if(temp == NULL){
    list->tail = temp;
  }
  list->head = temp;
  return return_value;
}
int pop_back(struct List* list){
  int return_val = list->tail->value;
  if (list->head == list->tail){
    free(list->tail);
    list->tail = NULL; 
    list->head = NULL;
    return return_val;
}
  struct Node* current = list->head;
  while(current->next != list->tail) {
    current = current->next;
  }
  free(list->tail);
  list->tail = current;
  list->tail->next = NULL;
  return return_val;
}

struct List* duplicate(const struct List* list){
  struct List* a = create_list();
  struct Node* current = list->head; 
  while (current != NULL) {
    append_back(a, current->value);
    current = current->next;
}
  return a;
}
void insert(struct List* list, int index, int value){
  struct Node* new_node = malloc(sizeof(struct Node));
  new_node->value = value;
  new_node->next = NULL;
  if(list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
    return;
  }
  if(index == 0){
    new_node->next = list->head;
    list->head = new_node;
  } else {
  struct Node* current = list->head;
  int i = 0;
  while(current != NULL && i < index - 1) { 
    current = current->next;
    ++i;
  }
 new_node->next = current->next;
 current->next = new_node;
 } 
}

void remove_elem(struct List* list, int index){
  struct Node* current = list->head;
  struct Node* previous = NULL;
  int i = 0;
  if (index == 0){
    list->head = list->head->next;
    if(list->head == NULL){
      list->tail = NULL;
    }  
    free(current); 
    return;
  }   
  while(current != NULL && i < index) { 
    previous = current;
    current = current->next;
    ++i;
  }
  if(current == NULL){
   return;
  } 
  previous->next = current->next;
  free(current);
}

bool equals(struct List* lhs,struct List* rhs){
  struct Node* left_current = lhs->head;
  struct Node* right_current = rhs->head;
  while (left_current != NULL && right_current != NULL) {
    if (left_current->value != right_current->value) {
      return false;
    }
    left_current = left_current->next;
    right_current = right_current->next;
  }
  return left_current == NULL && right_current == NULL;
}

bool contains(struct List* list, int value){
  struct Node* current = list->head;
  while(current != NULL){
    if (current->value == value) {
      return true; 
    }
   current = current->next;
  }
  return false;
}

void for_each(struct List* list, void (*func)(int*)){
  struct Node* current = list->head;
  while (current != NULL) {
    func(&(current->value));
    current = current->next;
  }
}

struct List* map(struct List* list, void (*func)(int*)) {
  struct List* a = duplicate(list);
  for_each(a, func);
  return a;
}

struct List* filter(struct List* list, bool(*predicate)(int*)){
  struct List* a = create_list();
  struct Node* current = list->head;
  while (current != NULL) {
    if (predicate(&(current->value))) {
      append_back(a, current->value);
    }
    current = current->next;
  }
  return a;
}
