typedef struct node{
  int value;
  struct node *left;
  struct node *right;
} node_t;

node_t* new_node(int value);
node_t* lookup(node_t* node, int value);
node_t* insert(node_t* node, int value);
int size(node_t* tree);
int max_depth(node_t* tree);
int min_value(node_t* tree);
int max_value(node_t* tree);
void print_tree(node_t* tree);
void print_postorder(node_t* tree);
int has_path_sum(node_t* tree, int sum);
void print_paths(node_t* tree);
