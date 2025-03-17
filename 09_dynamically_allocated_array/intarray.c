#include "intarray.h"

#include <stdlib.h>
#include <stdbool.h>
struct IntArray* create_array(size_t size) {
  struct IntArray* a = malloc(sizeof *a);
  a->size = size;
  a->data = malloc(size *sizeof *a->data);

  return a;
}

void free_array(struct IntArray* array) {
  free(array -> data);
  free(array);
}
bool contains(const struct IntArray* array, int elem) {
  for(size_t i = 0; i < array->size; ++i) {
    if (array->data[i] == elem) {
      return true;
    }
  }
  return false;
}
int max_element(const struct IntArray* array) {
  int max = array->data[0];
  for(size_t i = 0; i < array->size; ++i) {
    if(array->data[i] > max) {
      max = array->data[i]; 
    }
  }
  return max; 
}
int min_element(const struct IntArray* array) {
  int min = array->data[0]; 
  for(size_t i = 0; i < array->size; ++i){
    if(array->data[i] < min) {
      min = array->data[i];
    }
  }
  return min;
}
bool equals(const struct IntArray* lhs, const struct IntArray* rhs) {
  if(lhs->size != rhs->size) {
   return false;
  }
 for(size_t i = 0; i < lhs->size; ++i){
    if(lhs->data[i] != rhs->data[i]){
      return false;
    }
  }
 return true;
}
struct IntArray* map_array(const struct IntArray* array, int(*func)(int)){
  struct IntArray* mapped_array = create_array(array->size);
  for(size_t i = 0; i < array->size; ++i){
    mapped_array->data[i] = func(array->data[i]);
  }
  return mapped_array;
}
