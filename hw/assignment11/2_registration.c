#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 100000
#define MAX_NAME 50

typedef struct Node {
    char *name;
    int next_number;
    struct Node *next;
} Node;

Node *table[TABLE_SIZE];

unsigned long hash_function(const char *str) {
    unsigned long hash = 5381;

    while (*str) {
        hash = ((hash << 5) + hash) + (unsigned char)*str;
        str++;
    }

    return hash % TABLE_SIZE;
}

Node *find_node(const char *name) {
    unsigned long index = hash_function(name);
    Node *current = table[index];

    while (current != NULL) {
        if (strcmp(current->name, name) == 0)
            return current;

        current = current->next;
    }

    return NULL;
}

Node *insert(const char *name) {
    unsigned long index = hash_function(name);

    Node *node = malloc(sizeof(Node));
    node->name = malloc(strlen(name) + 1);
    strcpy(node->name, name);

    node->next_number = 1;
    node->next = table[index];

    table[index] = node;

    return node;
}

void split_name(
    const char *input,
    char *base,
    int *number,
    int *has_number
) {
    int len = strlen(input);

    int pos = len - 1;

    // Find where trailing digits begin
    while (pos >= 0 && isdigit((unsigned char)input[pos])) {
        pos--;
    }

    if (pos == len - 1) {
        // No number at the end
        strcpy(base, input);
        *number = 0;
        *has_number = 0;
        return;
    }
    
    // is a number at the end
    int base_len = pos + 1;

    strncpy(base, input, base_len);
    base[base_len] = '\0';

    *number = atoi(input + base_len);
    *has_number = 1;
    
}


int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char input[MAX_NAME];
        char base[MAX_NAME];
        char new_name[MAX_NAME];

        scanf("%s", input);

        if (find_node(input) == NULL) {
            insert(input);
            printf("OK\n");
            continue;
        }

        int number;
        int has_number;

        split_name(input, base, &number, &has_number);

        int next = 1;

        while (1) {
            sprintf(new_name, "%s%d", base, next);

            if (find_node(new_name) == NULL)
                break;

            next++;
        }

        insert(new_name);

        printf("Change to %s\n", new_name);
    }

    return 0;
}