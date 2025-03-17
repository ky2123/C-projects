#include <stddef.h>
#include <stdbool.h>

struct Node {
  int key;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
};

struct BST {
  struct Node* root;
};

struct BST* create_bst(void);

void free_bst(struct BST* bst);

void insert(struct BST* bst, int n);

bool contains(const struct BST* bst, int n);

void remove_node(struct BST* bst, int n);

struct BST* duplicate(const struct BST* bst);

void in_order(const struct BST* bst, void(*func)(int));

bool equals(const struct BST* lhs, const struct BST* rhs);
