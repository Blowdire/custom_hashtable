typedef struct{
  char* key;
  char* value;
}ht_item;

typedef struct{
  int size;
  int count;
  ht_item** items; //pointer to a pointer?
}ht_hash_table;