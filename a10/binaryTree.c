#include <stdlib.h>
#include <stdio.h>
struct bstnode {
    int item;
    struct bstnode *left, *right;
};
struct bst {
    struct bstnode *root;
    int count;
};
struct bst* bst_create(void) {
    return calloc(1, sizeof(struct bst));
}
void destroy(struct bstnode* node) {
    if (node) destroy(node->left), destroy(node->right), free(node);
}
void bst_destroy(struct bst* t) {
    destroy(t->root), free(t);
}
void print(struct bstnode* node) {
    if (node) print(node->left), printf("%d ", node->item), print(node->right);
}
void bst_print(struct bst* t) {
    if (t->root) print(t->root), printf("\n");
}
int bst_search(struct bst *t, int val) {
    struct bstnode* node = t->root;
    while (node) {
        if (node->item == val) return 1;
        node = node->item < val ? node->right : node->left;
    }
    return 0;
}
struct bstnode* insert(struct bstnode* node, int num) {
    if (!node) node = calloc(1, sizeof *node), node->item = num;
    if (node->item < num) node->right = insert(node->right, num);
    else if(node->item > num) node->left = insert(node->left, num);
    return node;
}
void bst_insert(int num, struct bst *t) {
    t->count += !bst_search(t, num), t->root = insert(t->root, num);
}
int bst_min(struct bst *t) {
    struct bstnode* node = t->root;
    while (node->left) node = node->left;
    return node->item;
}
int bst_max(struct bst *t) {
    struct bstnode* node = t->root;
    while (node->right) node = node->right;
    return node->item;
}
int height(struct bstnode *node) {
    if (!node) return 0;
    int lh = height(node->left), rh = height(node->right);
    return 1 + (lh > rh ? lh : rh);
}
int bst_height(struct bst *t) {
    return height(t->root) - 1;
}