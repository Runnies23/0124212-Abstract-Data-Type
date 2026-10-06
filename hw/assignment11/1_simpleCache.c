#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int data;
    int mem_addr;
} cell_t;

typedef struct hash {
    cell_t *table;
    int cache_size;
} hash_t;

typedef hash_t cache_t;
typedef int memory_t;

memory_t *init_memory(int size) {
    memory_t *memory = (memory_t *)malloc(sizeof(memory_t)*size);
    int i = 0;

    // Randomly assign integers to memory
    for (i=0; i<size; i++)
        memory[i] = rand();
    return memory;
}

// ==============================
// Write your code here
// ...

cache_t *init_cache(int size){
    //list of the 
    cache_t *hash_table = (cache_t*)malloc(sizeof(cache_t));
    
    hash_table->cache_size = size;
    hash_table->table = (cell_t*)malloc(sizeof(cell_t) * size);

    for(int i = 0;i < size;i++){
        hash_table->table[i].data = 0;
        hash_table->table[i].mem_addr = -1;
    }

    return hash_table;
}


void get_data(int addr, memory_t *m, cache_t *c){

    int index = addr % c->cache_size;

    if(c->table[index].mem_addr == addr){

        printf("Address %d is loaded\n", addr);
        printf("Data: %d\n", c->table[index].data);

        return;
    }

    if(c->table[index].mem_addr != -1){
        printf("Index: %d is used\n", index);
    }

    printf("Load from memory\n");

    c->table[index].data = m[addr];
    c->table[index].mem_addr = addr;

    printf("Data: %d\n", m[addr]);

    return;
}



// ==============================

int main(void) {
    memory_t *memory = NULL;
    cache_t *cache = NULL;
    int memory_size, cache_size;
    int i, n, addr;
    scanf("%d %d %d", &memory_size, &cache_size, &n);
    memory = init_memory(memory_size);
    cache = init_cache(cache_size);
    for (i=0; i<n; i++) {
        printf("Load address: ");
        scanf("%d", &addr);
        get_data(addr, memory, cache);
    }
    return 0;
}