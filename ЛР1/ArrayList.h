#ifndef ARRAYLIST_H
#define ARRAYLIST_H

struct ArrayList {
    int* array;
    int size;
    int capacity;
};

void initializeArrayList(struct ArrayList* list);
void add(struct ArrayList* list, int item);
void insert(struct ArrayList* list, int index, int item);
int size(const struct ArrayList* list);
void removeItem(struct ArrayList* list, int index);
void set(struct ArrayList* list, int index, int item);
int get(const struct ArrayList* list, int index);
void freeArrayList(struct ArrayList* list);

#endif
