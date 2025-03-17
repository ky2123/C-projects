#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <assert.h>

struct BST* create_bst(void) {
  struct BST* bst = malloc(sizeof *bst);
  bst->root = NULL;
  return bst;
}

void free_bst_impl(struct Node* root) {
  if (root == NULL) {
    return;
  }
  free_bst_impl(root->left);
  free_bst_impl(root->right);
  free(root);
  }

void free_bst(struct BST* bst){
  if (bst == NULL){
    return;
  }
  free_bst_impl(bst->root);
  free(bst);
} 
struct Node* create_node(int val, struct Node* parent) {
  struct Node* node = malloc(sizeof *node);
  node->key = val;
  node->left = node->right = NULL;
  node->parent = parent;
  return node;
}
struct Node* insert_impl(struct Node* root,int n, struct Node* parent) {
  if (root == NULL) {
    root = create_node(n, parent);
    return root;
  }else if (n < root->key) {
    root->left = insert_impl(root->left, n, root);
  } else if (n > root->key) {
      root->right = insert_impl(root->right, n, root);
    }
  return root;
}

void insert(struct BST* bst, int n){
  bst->root = insert_impl(bst->root, n, NULL);
}

bool contains_impl(const struct Node* root, int n) {
  if (root == NULL) {
    return false;
  }
  if (root->key == n) { 
    return true;
  }
  return contains_impl(root->key > n ? root->left : root->right, n);
}


bool contains(const struct BST* bst, int n) {
  return contains_impl(bst->root, n);
}

static struct Node* find_node_impl(struct Node* root, int n){
  if (n == root->key) {
    return root;
  }
  if (n > root->key) {
    return find_node_impl(root->right, n);
  } else {
    return find_node_impl(root->left, n);
  }
}
struct Node* find_node(const struct BST* bst, int n){
 return find_node_impl(bst->root, n);
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
  return n->left != NULL && n->right != NULL;
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

/*
void remove_node_impl(struct Node* root, int n){

  if (n < root->key) {
    remove_node_impl(root->left, n);
  }
  else if ( n > root->key) {
   remove_node_impl(root->right, n);
  } else { 
  if (root->left == NULL && root->right == NULL){
    if(root->parent){
      if(root->parent->right == root){
        root->parent->right = NULL;
      }else{ 
        root->parent->left = NULL;
      }
    }
    free(root);
    return;

  }else if(root->left != NULL && root->right == NULL) { 
    if(root->parent->left == root) {
    root->parent->left = root->left;
  } else {
    root->parent->right = root->right;
  }
    root->left->parent = root->parent;
    free(root);
    return;
  }
  else if(root->right != NULL && root->left == NULL){
    if(root->parent->right == root) {
      root->parent->right = root->right;
    }else{
      root->parent->left = root->left;
    }
    root->right->parent = root->parent;
    free(root);
    return;
}
  else if(root->right != NULL && root->left != NULL){
    struct Node* temp = root->right;
    while (temp->left != NULL){
      temp = temp->left;
    }
    if (temp->parent->left == temp){
      temp->parent->left = temp->right;
    }else{
     temp->parent->right = temp->right;
    } 
    if (temp->right != NULL){
      temp->right->parent = temp->parent;
    }
    temp->left = root->left;
    temp->right = root->right;
    if (root->left != NULL) {
      root->left->parent = temp;
    }
    if(root->right != NULL && root->right != temp){
      root->right->parent = temp;
    }
    temp->parent = root->parent;
    if(root->parent != NULL) {
      if(root->parent->right == root){
        root->parent->right = temp;
      }else{
        root->parent->left = temp;
      }
    }
    free(root);
    return;
   }
 }
}
*/
void remove_node(struct BST* bst, int n){
  struct Node* to_remove = find_node(bst, n);
  assert(to_remove != NULL);
  pluck(bst, to_remove);
  free(to_remove);
}

struct Node* duplicate_impl(const struct Node* src, struct Node* dest_parent){
  if (src == NULL){
    return NULL;
  }
  struct Node* dest = malloc(sizeof *dest);
  *dest = (struct Node) {
    .key = src->key,
    .parent = dest_parent,
  };
  dest->left = duplicate_impl(src->left, dest);
  dest->right = duplicate_impl(src->right, dest);
  return dest;
}
struct BST* duplicate(const struct BST* bst){
  struct BST* copy = create_bst();
  copy->root = duplicate_impl(bst->root, NULL);
  return copy;
}

void in_order_impl(struct Node* root, void(*func)(int)){
  if(root == NULL){    
    return;
  }
  in_order_impl(root->left, func);
  func(root->key);
  in_order_impl(root->right, func);
      
}
void in_order(const struct BST* bst, void(*func)(int)){
  in_order_impl(bst->root, func);
}
 
void collect_keys(struct Node* root, int* array, int* index){
  if(root == NULL) {
    return;
  }
  collect_keys(root->left, array, index);
  array[*index] = root->key;
  (*index)++;
  collect_keys(root->right, array, index);
}

int comparison(const void* a, const void* b){
  return(*(int*)a - *(int*)b);
}
/*
bool equals(const struct BST* lhs, const struct BST* rhs){
  const struct Node* n1 = first_node(lhs);
  const struct Node* n2 = first_node(rhs);
  while (n1 != NULL && n2 != NULL) {
    if (n1->key != n2->key) {
      return false;
    }
    n1 = next_node(n1);
    n2 = next_node(n2);
  }
  return n1 == NULL && n2 == NULL;
}
*/
