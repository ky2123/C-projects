#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <assert.h>
#include <string.h>

struct Node {
  char* key;
  int value;
  struct Node* left;
  struct Node* right;
  struct Node* parent;

};
struct BST { 
  struct Node* root;
};

static struct Node* create_node(const char* str, struct Node* parent, int value) {
  struct Node* node = malloc(sizeof *node);
  size_t len = strlen(str) + 1;
  node->key = malloc(len);
  strcpy(node->key, str);
  node->parent = parent;
  node->left = node->right = NULL;
  node->value = value;
  return node;
}
static void free_node(struct Node* node){
  free(node->key);
  free(node);
}

struct Node* insert_impl(struct Node* root,const char* str, struct Node* parent, int value) {
  if (root == NULL) {
    root = create_node(str, parent, value);
  } if (strcmp(str, root->key) == 0){
      root->value = value;
    } 
     else if (strcmp(str, root->key) < 0) {
    root->left = insert_impl(root->left, str, root, value);
  } else if (strcmp(str, root->key) > 0) {
      root->right = insert_impl(root->right, str, root, value);
    }
  return root;
}

struct BST* create_bst(void) {
  struct BST* bst = malloc(sizeof *bst);
  bst->root = NULL;
  return bst;
}

static void free_bst_impl(struct Node* root) {
  if (root == NULL) {
    return;
  }
  free_bst_impl(root->left);
  free_bst_impl(root->right);
  free_node(root);
  }

void free_bst(struct BST* bst){
  if (bst == NULL){
    return;
  }
  free_bst_impl(bst->root);
  free(bst);
} 

void insert(struct BST* bst, const char* str, int value){
  bst->root = insert_impl(bst->root, str, NULL, value);
}
// maybe change contains to also have to search for value
bool contains_impl(const struct Node* root, const char* str) {
  if (root == NULL) {
   return false;
  }
  if (strcmp(str, root->key) == 0) { 
    return true;
  }
  return contains_impl(strcmp(str, root->key) < 0 ? root->left : root->right, str);
}


bool contains(const struct BST* bst, const char* n) {
  return contains_impl(bst->root, n);
}

static struct Node* find_node_impl(struct Node* root, const char* str){
  if (strcmp(str, root->key) == 0) {
    return root;
  }
  if (strcmp(str, root->key) > 0) {
    return find_node_impl(root->right, str);
  } else {
    return find_node_impl(root->left, str);
  }
}
struct Node* find_node(const struct BST* bst, const char* str){
 return find_node_impl(bst->root, str);
}

static bool is_left_child(const struct Node* n) {
  return n->parent && n->parent->left == n;
}
static bool is_right_child(const struct Node* n) {
  return n->parent && n->parent->right == n;
}

static bool has_one_child(const struct Node* n) {
  return !(n->left != NULL && n->right != NULL) && (n->left != NULL || n->right != NULL);
}

static bool has_no_children(const struct Node* n) {
  return n->left == NULL && n->right == NULL;
}

static struct Node** get_pointer_to(struct BST* bst, const struct Node* n) {
  if (is_left_child(n)) {
    return &n->parent->left;
  } else if (is_right_child(n)) {
    return &n->parent->right;
  } else {
    return &bst->root;
  }
}




static void pluck(struct BST* bst, struct Node* to_remove) {
  if (has_no_children(to_remove)) {
    // no children
    *get_pointer_to(bst, to_remove) = NULL;
  } else if (has_one_child(to_remove)) {
    struct Node* only_child = to_remove->left ? to_remove->left : to_remove->right;
    *get_pointer_to(bst, to_remove) = only_child;
    only_child->parent = to_remove->parent;
  } else if (to_remove->right != NULL && to_remove->left != NULL) {
    struct Node* replacement = to_remove->right;
    while (replacement->left != NULL){
      replacement = replacement->left;
    }
    pluck(bst, replacement);
    replacement->left = to_remove->left;
    replacement->right = to_remove->right;
    replacement->parent = to_remove->parent;
    *get_pointer_to(bst, to_remove) = replacement;
    if (replacement->left != NULL) {
      replacement->left->parent = replacement;
    }
    if (replacement->right != NULL) {
      replacement->right->parent = replacement;
    }
  }
}

void remove_node(struct BST* bst, const char* str){
  struct Node* to_remove = find_node(bst, str);
  assert(to_remove != NULL);
  pluck(bst, to_remove);
  to_remove->left = to_remove->right = to_remove->parent = NULL;
  free_node(to_remove);
}

struct Node* duplicate_impl(const struct Node* src, struct Node* dest_parent){
  if (src == NULL){
    return NULL;
  }
  struct Node* dest = create_node(src->key, dest_parent, src->value);
  dest->left = duplicate_impl(src->left, dest);
  dest->right = duplicate_impl(src->right, dest);
  return dest;
}
struct BST* duplicate(const struct BST* bst){
  struct BST* copy = create_bst();
  copy->root = duplicate_impl(bst->root, NULL);
  return copy;
} 
void in_order_impl(struct Node* root, void(*func)(char*, int*)){
  if(root == NULL){    
    return;
  }
  in_order_impl(root->left, func);
  func(root->key, &root->value);
  in_order_impl(root->right, func);
      
}

void in_order(const struct BST* bst, void(*func)(char*, int*)){
  in_order_impl(bst->root, func);
}
static void write_node_to_file(struct Node* root, FILE* fptr){
  if (root == NULL) {
    return;
  }
 write_node_to_file(root->left, fptr); 
 fprintf(fptr, "%s : %d\n", root->key, root->value);
 write_node_to_file(root->right, fptr);
}
void write_tree_to_file(const char* filename, struct BST* bst) {
 FILE *fptr = fopen(filename, "w");
 write_node_to_file(bst->root, fptr);
 fclose(fptr);
}
 
static const struct Node* first_node(const struct BST* bst){
  const struct Node* current = bst->root;
  while (current != NULL && current->left != NULL){
    current = current->left;
  }
  return current;
}
static const struct Node* next_node(const struct Node* current){
  if (current->right != NULL) {
    current = current->right;
  while(current->left != NULL) {
    current = current->left;
  }
} else if (is_left_child(current)){
    current = current->parent;
} else if (is_right_child(current)){
    while(is_right_child(current)){
      current = current->parent;
  }
    current = current->parent;
  }

  return current;
}
bool equals(const struct BST* lhs, const struct BST* rhs){
  const struct Node* n1 = first_node(lhs);
  const struct Node* n2 = first_node(rhs);
  while (n1 != NULL && n2 != NULL) {
    if (strcmp(n1->key, n2->key) != 0 || (n1->value != n2->value)) {
      return false;
    }
    n1 = next_node(n1);
    n2 = next_node(n2);
  }
  return n1 == NULL && n2 == NULL;
}

int* get_value(struct BST* bst, const char* key){
 struct Node* node = find_node(bst, key);
 return &node->value; 
}

