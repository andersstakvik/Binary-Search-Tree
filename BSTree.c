struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct tree {
    struct node* root;
    int size;
};

struct tree* new_tree();
struct node* new_node(int);
void add(struct tree*, int);
void remove(int);

int main() {
    return 0;
}

void add(struct tree* tree, int value) {
    boolean placed = false;
    struct node* current;
    struct node* correct_child;
    if (!tree->root) tree->root = new_node(value);
    else for (current = tree->root; !placed;) {
        correct_child = correct_node(current, value);
        if (correct_child) current = correct_child;
        else {
            correct_child = new_node(value);
            placed = true;
        }
    }
}

struct node* correct_node(struct node* parent, int value) {
    if (value > parent->value) return parent->left;
    return parent->right;
}

struct tree* new_tree() {
    struct tree* new_tree = malloc(sizeof(struct tree*));
    new_tree->node = NULL;
    return new_tree;
}

struct node* new_node(int value) {
    struct node* new_node = malloc(sizeof(struct node*));
    new_node->value = NULL;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
