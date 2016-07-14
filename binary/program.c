#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  /* code */
 node_t* tree =  insert(NULL,4);
 tree = insert(tree, 2);
 tree = insert(tree, 5);
 tree = insert(tree, 1);
 tree = insert(tree, 3);


 printf("Inorder\n");
 print_tree(tree);
 printf("\n");
 printf("Postorder\n");
 print_postorder(tree);
 printf("\n");
 printf("Size:%d\n",size(tree));
 printf("Max depth:%d\n", max_depth(tree));
 printf("Min Value:%d\n", min_value(tree));
 printf("Max Value:%d\n", max_value(tree));

 int sum = atoi(argv[1]);
 printf("Has Path Sum %d: %d\n", sum, has_path_sum(tree,sum));

 print_paths(tree);
 //lookup(tree, atoi(argv[1]));

 return 0;
}
