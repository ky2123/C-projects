#ifndef RESIZEABLEARRAY_GROWABLEARRAY_H_
#define RESIZEABLEARRAY_GROWABLEARRAY_H_

#include <stdbool.h>
#include <stddef.h>


struct GrowableArray {
    void** data; // an array of void*
    size_t size; // total actual elements
    size_t capacity; // total memory reserved by number of elements
    int (*cmp)(const void*, const void*); //comparison function
    void (*free_element)(void*); // function to delete an element (used in free_array)
    void* (*duplicate_element)(const void*); // function to duplicate an element
};

// Creates an array of elements with a comparison function, and a destruction function
struct GrowableArray* create_array(
    int (*cmp)(const void*, const void*),
    void (*free_element)(void*),
    void* (*duplicate_element)(const void*));

// free all associated data. You must free both the GrowableArray struct, and any
// data you allocated within it. Every malloc() needs a free()
// Additionally, you have to free_element() each pointer in the array
void free_array(struct GrowableArray* array);

// return true if the array contains a given Element
bool contains(const struct GrowableArray* array, const void* element);

// return largest element in the array
void* max_element(const struct GrowableArray* array);

// return smallest element in the array
void* min_element(const struct GrowableArray* array);

// return true if the two arrays have the same contents
bool equals(const struct GrowableArray* lhs, const struct GrowableArray* rhs);

// Appends element to end of array if size < capacity, doubles space if not.
// takes ownership of element
void append(struct GrowableArray* array, void* element);

// Removes and returns the last element in array.
//
// Caller takes ownership of returned pointer (must free it).
void* pop(struct GrowableArray* array);

// Creates and returns a copy of array with duplicated elements
struct GrowableArray* duplicate(const struct GrowableArray* array);

// Modifies array by appending all elements from additional to the end
//
// a1 = [a, b, c]
// a2 = [d, e]
// extend(a1, a2)
// Should end up with a1 == [a, b, c, d, e]
void extend(struct GrowableArray* array, const struct GrowableArray* additional);

// Returns a new array containing the elements of the two arrays together (+)
struct GrowableArray* concat(const struct GrowableArray* lhs, const struct GrowableArray* rhs);

#endif
