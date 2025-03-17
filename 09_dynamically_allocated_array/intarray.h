#ifndef DYNAMIC_INT_ARRAY_H_
#define DYNAMIC_INT_ARRAY_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

struct IntArray {
  int* data;
  size_t size;
};

// Create an array with the given size. Initialize all elements to 0.
struct IntArray* create_array(size_t size);
// free all associated data. You must free both the IntArray struct, and any
// data you allocated within it. Every malloc() needs a free()
void free_array(struct IntArray* array);
// return true if the array contains a given Element
bool contains(const struct IntArray* array, int elem);
// return largest element in the array
int max_element(const struct IntArray* array);
//   for(int i = 0; i < size
// return smallest element in the array
int min_element(const struct IntArray* array);

// return true if the two arrays have the same contents
bool equals(const struct IntArray* lhs, const struct IntArray* rhs);

// returns a new array as a result of applying func to all elements of array
struct IntArray* map_array(const struct IntArray* array, int (*func)(int));

#endif
