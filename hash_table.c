#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

/// @brief instantiate an hash table item, allocates chunk of memory of size ht_item
/// @param k key value, pointer to a char
/// @param v value, pointer to a char
/// @return pointer to hashtable item
static ht_item* ht_new_item(const char* k, const char* v){
  ht_item* i = malloc(sizeof(ht_item));
  i->key = strdup(k);
  i->value = strdup(v);
  return i; 
}
/// @brief creates an hashtable, allocates memory, sets size and count, allocs with null values memory array equal to size of hastable item and for size times length
/// @param size 
/// @return 
ht_hash_table* ht_new(int size){
  ht_hash_table* hashTable = malloc(sizeof(ht_hash_table));
  hashTable->size = size;
  hashTable->count = 0;
  hashTable->items = calloc((size_t)hashTable->size, sizeof(ht_item*));
  return hashTable;
}

static void ht_delete_item(ht_item* i){
  free(i->key);
  free(i->value);
  free(i);
}

void ht_del_hash_table(ht_hash_table* ht){
  for(int i=0; i<ht->size; i++){
    ht_item* item = ht->items[i];
    if(item != NULL){
      ht_delete_item(item);
    }
  }
  free(ht->items);
  free(ht);
}