#include <stdio.h>
#include <stdlib.h>
#define __avl_tree__
#include "week9.h"
// #include <week9.h>
#ifndef __avl_tree__
typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t avl_t;
#endif


// Write your code here
// ** Note that the print_tree() function
// has been implemented already and
// included in the week9.h header
// ...


int height(avl_t *t) {
    if (t == NULL)
        return 0;

    return t->height;
}

int max(int a, int b) {
    return a > b ? a : b;
}

void update_height(avl_t *t) {
    if (t == NULL)
        return;

    t->height = 1 + max(height(t->left), height(t->right));
}

int balance_factor(avl_t *t) {
    if (t == NULL)
        return 0;

    return height(t->left) - height(t->right);
}

avl_t *rotate_right(avl_t *y) {

    avl_t *x = y->left;
    avl_t *temp = x->right;

    // rotation
    x->right = y;
    y->left = temp;

    // update height
    update_height(y);
    update_height(x);

    return x;
}

avl_t *rotate_left(avl_t *x) {

    avl_t *y = x->right;
    avl_t *temp = y->left;

    // rotation
    y->left = x;
    x->right = temp;

    // update height
    update_height(x);
    update_height(y);

    return y;
}
avl_t *rebalance(avl_t *t) {

    if (t == NULL)
        return NULL;

    update_height(t);

    int balance = balance_factor(t);

    // LEFT heavy
    if (balance > 1) {

        // LR case
        if (balance_factor(t->left) < 0) {
            t->left = rotate_left(t->left);
        }

        // LL case
        return rotate_right(t);
    }

    // RIGHT heavy
    if (balance < -1) {

        // RL case
        if (balance_factor(t->right) > 0) {
            t->right = rotate_right(t->right);
        }

        // RR case
        return rotate_left(t);
    }

    return t;
}


avl_t *insert(avl_t *t, int data) {

    // normal BST insertion
    if (t == NULL) {

        avl_t *new_node = malloc(sizeof(avl_t));

        new_node->data = data;
        new_node->height = 1;
        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
    }

    if (data < t->data) {
        t->left = insert(t->left, data);
    }
    else if (data > t->data) {
        t->right = insert(t->right, data);
    }
    else {
        // duplicate
        return t;
    }

    // fix AVL
    return rebalance(t);
}


avl_t *find_min(avl_t *t) {

    while (t->left != NULL) {
        t = t->left;
    }

    return t;
}

avl_t *delete(avl_t *t, int data) {

    if (t == NULL)
        return NULL;

    // search
    if (data < t->data) {
        t->left = delete(t->left, data);
    }
    else if (data > t->data) {
        t->right = delete(t->right, data);
    }

    // found node
    else {

        // case 1 no child
        if (t->left == NULL && t->right == NULL) {
            free(t);
            return NULL;
        }

        // case 2 only right child
        if (t->left == NULL) {
            avl_t *temp = t->right;
            free(t);
            return temp;
        }

        // case 3 only left child
        if (t->right == NULL) {
            avl_t *temp = t->left;
            free(t);
            return temp;
        }

        // case 4 two children
        avl_t *temp = find_min(t->right);

        t->data = temp->data;

        t->right = delete(t->right, temp->data);
    }

    return rebalance(t);
}



int main(void) {
    avl_t *t = NULL;
    int n, i;
    int command, data;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &command);
        switch (command) {
            case 1:
                scanf("%d", &data);
                t = insert(t, data);
            break;
            case 2:
                scanf("%d", &data);
                t = delete(t, data);
                break;
            case 3:
                print_tree(t);
                break;
        }
    }
    return 0;
}