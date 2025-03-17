#include "bst.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

void print_node(char* key, int* value) {
  printf("%s: %d\n", key, *value);
}
void read_from_file(const char* filename, struct BST* bst){
   FILE *fptr = fopen(filename, "r");
   char buffer[256];
   while(fscanf(fptr, "%255s", buffer) == 1){
     if(!contains(bst, buffer)){
    insert(bst, buffer, 1 );
   }else{
   int* val = get_value(bst, buffer);
    (*val)++;
   }
}

   fclose(fptr);
   } 

int main(){ 

  {
  struct BST* bst = create_bst();
  insert(bst, "b", 22); 
  insert(bst, "dinner", 1);
  insert(bst, "turkey", 23);
  insert(bst, "beans", 21);
  insert(bst, "wings", 25);
  insert(bst, "bird", 1);
//  printf("%d\n", contains(bst, "d"));
//  in_order(bst, print_node);
  remove_node(bst, "b");
  assert(!contains(bst, "b"));
 // printf("%d\n", contains(bst, "b"));
  struct BST* bst2 = duplicate(bst);
 // printf("%d\n", contains(bst2, "d"));
 // printf("%d\n", contains(bst2 ,"b"));
  write_tree_to_file("text2.txt", bst2);
  free_bst(bst);
  free_bst(bst2);  
  struct BST* fbst = create_bst();
  struct BST* rbst = create_bst();
  read_from_file("text2.txt", rbst);
  read_from_file("text.txt", fbst); 
 // in_order(rbst, print_node);
 // in_order(fbst, print_node); 
  free_bst(fbst);
  free_bst(rbst);
  }
  {
    
    struct BST* bst = create_bst();
    read_from_file("text.txt", bst);
    assert(contains(bst, "apple"));
    assert(contains(bst, "oranges"));
    assert(contains(bst, "calculus"));
    insert(bst, "ethics", 1);
    insert(bst, "computing", 1);
    insert(bst, "profession", 1);
    write_tree_to_file("text3.txt", bst);
    free_bst(bst);
    printf("Test 1 was successful.\n");

  }
  {
    struct BST* bst = create_bst();
    read_from_file("text2.txt", bst);
    struct BST* dupe = duplicate(bst);
    assert(equals(bst, dupe)); 
    insert(dupe, "atari", 87);
    assert(!equals(bst, dupe));
    free_bst(dupe);
    free_bst(bst);
    printf("Duplication and equals test was successful.\n");

}
{
  struct BST* bst = create_bst();
  insert(bst, "In order test", 1);
  insert(bst, "did", 2);
  insert(bst, "infact", 3);
  insert(bst, "work", 14);
  in_order(bst, print_node);
  int* value = get_value(bst, "work");
  printf("Value for work is : %d\n", *value);
  
  free_bst(bst);
}
{
  printf("The read_from_file test.\n");
  struct BST* bst = create_bst();
  read_from_file("count.txt", bst);
  in_order(bst, print_node);
  free_bst(bst);
}  
  
}
