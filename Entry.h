#ifndef ENTRY_H
#define ENTRY_H

typedef struct Entry {
    char *key;
    char *value;
} Entry;

Entry entry_constructor(void *key,int key_size, void *value, int value_size);
void entry_destructor(Entry *entry);

#endif // ENTRY_H