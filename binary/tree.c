#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

node_t* new_node(int value){
  node_t* new_node = malloc(sizeof(node_t));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node_t* lookup(node_t* node, int value){
  if (node == NULL){
    return NULL;
  }

  printf("visiting %d\n",node->value);

  if(node->value == value){
    return node;
  }

  if(node->value > value){
    printf("moving left\n");
    return lookup(node->left, value);
  } else {
    printf("moving right\n");
    return lookup(node->right, value);
  }
}

node_t* insert(node_t* node, int value)
{
  if(node == NULL){
    return new_node(value);
  }

  if(node->value > value){
    node->left = insert(node->left, value);
  } else {
    node -> right = insert(node->right, value);
  }
  return node;
}

int size(node_t* tree){
  if(tree == NULL)
   return 0;

  return 1 + size(tree->left) + size(tree->right);
}

int max_depth(node_t* tree){
  if(tree == NULL)
    return 0;

  int l_depth = max_depth(tree->left);
  int r_depth = max_depth(tree->right);

  if(l_depth>=r_depth)
    return l_depth + 1;
  return r_depth + 1;
}

int min_value(node_t* tree){
  if(tree->left == NULL){
    return tree->value;
  }

  int temp = min_value(tree->left);
  if(temp < tree->value){
    return temp;
  } else {
    return tree->value;
  }
}

int max_value(node_t* tree){
  if(tree->right == NULL){
    return tree->value;
  }

  int temp = max_value(tree->right);
  if(temp > tree->value){
    return temp;
  } else {
    return tree->value;
  }
}

void print_tree(node_t* tree){
  if(tree == NULL)
    return;

  print_tree(tree->left);
  printf("%d ", tree->value);
  print_tree(tree->right);
}

void print_postorder(node_t* tree){
  if(tree == NULL)
    return;

  print_postorder(tree->left);
  print_postorder(tree->right);
  printf("%d ", tree->value);
}
