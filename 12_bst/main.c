#include "bst.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

void printer(struct Node* baller){ 
  if (baller == NULL){
    printf("Node is NULL\n");
    return;
  }
  printf("%d\n", baller->key);
}

void print_tree(struct Node* root ){
  if(root == NULL){
    return;
  }
  printf("%d\n", root->key);
  print_tree(root->left);
  print_tree(root->right);
}
void double_value(int val){
  printf("%d\n", val * 2);
}
int main(){
  
  struct BST* steve = create_bst(); 
  
  insert(steve, 500);
  insert(steve, 2000);
  insert(steve, 100);
  insert(steve, 2200);
  remove_node(steve, 500);
  free_bst(steve);
}
