#include <stddef.h>
#include <stdbool.h>
struct BST;

struct BST* create_bst(void);

void free_bst(struct BST* bst);

void insert(struct BST* bst, const char* str, int value);

int* get_value(struct BST* bst, const char* key);

bool contains(const struct BST* bst, const char* str); 

void remove_node(struct BST* bst, const char* str);

struct BST* duplicate(const struct BST* bst);

void in_order(const struct BST* bst, void(*func)(char*, int*));

bool equals(const struct BST* lhs, const struct BST* rhs);

void write_tree_to_file(const char* filename, struct BST* bst);
