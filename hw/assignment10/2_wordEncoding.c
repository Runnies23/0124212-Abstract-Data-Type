#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20
#define MAX_CODE 100

typedef struct node {
    struct node *left;
    struct node *right;
    char string[MAX_LENGTH];
    int priority;
} node_t;

typedef struct heap_d {
    node_t *data;
    int last_index;
} heap_t;

void log_print(heap_t *h)
{
    printf("==========logging==========\n");

    for (int i = 0; i < h->last_index; i++) {
        printf("%s | %d\n",
               h->data[i].string,
               h->data[i].priority);
    }

    printf("\n");
}

void insert(heap_t *h, node_t node)
{
    int idx = h->last_index;

    h->data[idx] = node;
    h->last_index++;

    while (idx > 0) {
        int parent_idx = (idx - 1) / 2;

        if (h->data[parent_idx].priority <=
            h->data[idx].priority) {
            break;
        }

        node_t temp = h->data[idx];
        h->data[idx] = h->data[parent_idx];
        h->data[parent_idx] = temp;

        idx = parent_idx;
    }
}

node_t delete_min(heap_t *h)
{
    node_t returning_data = h->data[0];

    h->last_index--;

    if (h->last_index == 0) {
        return returning_data;
    }

    h->data[0] = h->data[h->last_index];

    int idx = 0;

    while (1) {
        int left_child = 2 * idx + 1;
        int right_child = 2 * idx + 2;

        if (left_child >= h->last_index) {
            break;
        }

        int smaller_child = left_child;

        if (right_child < h->last_index &&
            h->data[right_child].priority <
            h->data[left_child].priority) {
            smaller_child = right_child;
        }

        if (h->data[idx].priority <=
            h->data[smaller_child].priority) {
            break;
        }

        node_t temp = h->data[idx];
        h->data[idx] = h->data[smaller_child];
        h->data[smaller_child] = temp;

        idx = smaller_child;
    }

    return returning_data;
}

void generate_codes(node_t *root, char *code, int depth)
{
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        code[depth] = '\0';
        printf("%s: %s\n", root->string, code);
        return;
    }

    if (root->left != NULL) {
        code[depth] = '0';
        generate_codes(root->left, code, depth + 1);
    }

    if (root->right != NULL) {
        code[depth] = '1';
        generate_codes(root->right, code, depth + 1);
    }
}


int main()
{
    int n;
    scanf("%d", &n);

    char string[MAX_LENGTH];
    int priority;

    heap_t *heap = malloc(sizeof(heap_t));
    heap->data = malloc(sizeof(node_t) * n);
    heap->last_index = 0;

    for (int i = 0; i < n; i++) {
        scanf("%19s %d", string, &priority);

        node_t node;

        node.left = NULL;
        node.right = NULL;
        node.priority = priority;

        strcpy(node.string, string);

        insert(heap, node);
    }

    while (heap->last_index > 1) {
        node_t least1 = delete_min(heap);
        node_t least2 = delete_min(heap);

        node_t *combine_heap = malloc(sizeof(node_t));

        combine_heap->left = malloc(sizeof(node_t));
        combine_heap->right = malloc(sizeof(node_t));

        *(combine_heap->left) = least1;
        *(combine_heap->right) = least2;

        combine_heap->priority =
            least1.priority + least2.priority;

        strcpy(combine_heap->string, "");

        insert(heap, *combine_heap);

        free(combine_heap);
    }

    node_t *root = &heap->data[0];

    char code[MAX_CODE];

    generate_codes(root, code, 0);

    return 1;
}