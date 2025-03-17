#include <stdbool.h>
#include <stddef.h>

struct List* create_list(void);

void free_list(struct List* list);

int at(struct List* list, int index);

void append_back(struct List* list, int element);

void append_front(struct List* list, int element);

void pop_front(struct List* list); 

void pop_back(struct List* list); 

struct List* duplicate(const struct List* list); 

void insert(struct List* list, int index, int value);

void remove_elem(struct List* list, int index);

bool equals(struct List* lhs, struct List* rhs);

bool contains(struct List* list, int val);  

void for_each(struct List* list, void (*func)(int*));

struct List* map(struct List* list, void (*func)(int*));

struct List* filter(struct List* list, bool(*predicate)(int*));


