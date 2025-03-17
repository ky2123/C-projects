#include "growable_array.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

struct GrowableArray* create_array(
int(*cmp)(const void*, const void*),
void(*free_element)(void*),
void*(duplicate_element)(const void*)) {
  struct GrowableArray* array = malloc(sizeof *array);
  array->capacity = 2;
  array->size = 0;
  array->data = malloc(array->capacity * sizeof *array->data);
  array->cmp = cmp;
  array->free_element = free_element;
  array->duplicate_element = duplicate_element;
  return array;
} 

void free_array(struct GrowableArray* array){
  for(size_t i = 0; i < array->size; ++i){
    array->free_element(array->data[i]);
  }
  free(array->data);
  free(array);
}
bool contains(const struct GrowableArray* array, const void* element){
  for(size_t i = 0; i < array->size; ++i) {
    if(array->cmp(array->data[i], element) == 0) {
      return true;
    }
  }
  return false;
}
void* max_element(const struct GrowableArray* array){
  void* max = array->data[0];
  for(size_t i = 0; i < array->size; ++i) {
    if(array->cmp(array->data[i], max) > 0) {
     max = array->data[i];
    }
  }
 return max; 
}
void* min_element(const struct GrowableArray* array){
  void* min = array->data[0];
  for(size_t i = 0; i < array->size; ++i) {
   if(array->cmp(array->data[i], min) < 0) {
    min = array->data[i];
   }
  }
 return min;
}
bool equals(const struct GrowableArray* lhs, const struct GrowableArray* rhs){
  if(lhs->size != rhs->size){
    return false;
  }
  for(size_t i = 0; i < lhs->size; ++i){
    if(lhs->cmp(lhs->data[i], rhs->data[i]) != 0) {
      return false;
    }
  }
  return true;
}

void append(struct GrowableArray* array, void* element){
  assert(array->size <= array->capacity);
  if(array->size == array->capacity){
    array->capacity = array->capacity * 2;
    void** new_data = malloc(array->capacity * sizeof *array->data);
    for (size_t i = 0; i < array->size; ++i) {
      new_data[i] = array->data[i];
       
    }
    free(array->data);
    array->data = new_data;
  }
  array->data[array->size] = element;
  ++array->size;
}
void* pop(struct GrowableArray* array){
  assert(array->size != 0);
  --array->size;
  return array->data[array->size];
}

struct GrowableArray* duplicate(const struct GrowableArray* array){
  struct GrowableArray* dupe = create_array(array->cmp, array->free_element, array->duplicate_element);
  extend(dupe, array); 
  dupe->size = array->size;
  return dupe;
}

void extend(struct GrowableArray* array, const struct GrowableArray* additional){
  for(size_t i = 0; i < additional->size; ++i){
    append(array, array->duplicate_element(additional->data[i]));
  }
}

struct GrowableArray* concat(const struct GrowableArray* lhs, const struct GrowableArray* rhs){
  struct GrowableArray* new_array = duplicate(lhs);
  extend(new_array, rhs);
  return new_array;
}

