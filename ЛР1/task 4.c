#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"


void initializeArrayList(struct ArrayList* list) {
    list->array = NULL;
    list->size = 0;
    list->capacity = 0;
}



void add(struct ArrayList* list, int item) {
    if (list->size == list->capacity) {
        // Подвоєння ємності, якщо масив заповнений
        list->capacity = (list->capacity == 0) ? 1 : list->capacity * 2;
        list->array = realloc(list->array, list->capacity * sizeof(int));
    }

    list->array[list->size++] = item;
}



void insert(struct ArrayList* list, int index, int item) {
    if (index < 0 || index > list->size) {
        printf("Error: Index out of bounds\n");
        return;
    }

    if (list->size == list->capacity) {
        // Подвоєння ємності, якщо масив заповнений
        list->capacity = (list->capacity == 0) ? 1 : list->capacity * 2;
        list->array = realloc(list->array, list->capacity * sizeof(int));
    }

    for (int i = list->size; i > index; --i) {
        list->array[i] = list->array[i - 1];
    }

    list->array[index] = item;
    list->size++;
}



int size(const struct ArrayList* list) {
    return list->size;
}



void removeItem(struct ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Error: Index out of bounds\n");
        return;
    }

    for (int i = index; i < list->size - 1; ++i) {
        list->array[i] = list->array[i + 1];
    }

    list->size--;

    // Зменшити масив, якщо розмір менше половини ємності
    if (list->size <= list->capacity / 2) {
        list->capacity /= 2;
        list->array = realloc(list->array, list->capacity * sizeof(int));
    }
}



void set(struct ArrayList* list, int index, int item) {
    if (index < 0 || index >= list->size) {
        printf("Error: Index out of bounds\n");
        return;
    }

    list->array[index] = item;
}



int get(const struct ArrayList* list, int index) {
    if (index < 0 || index >= list->size) {
        printf("Error: Index out of bounds\n");
        return -1; // Повернути значення за замовчуванням або належним чином обробити помилку
    }

    return list->array[index];
}



void freeArrayList(struct ArrayList* list) {
    free(list->array);
    list->array = NULL;
    list->size = 0;
    list->capacity = 0;
}




int main() {
    struct ArrayList list;
    initializeArrayList(&list);

    add(&list, 1);
    add(&list, 2);
    add(&list, 3);

    printf("Size: %d\n", size(&list));

    insert(&list, 1, 10);

    for (int i = 0; i < size(&list); ++i) {
        printf("%d ", get(&list, i));
    }
    printf("\n");

    removeItem(&list, 2);

    for (int i = 0; i < size(&list); ++i) {
        printf("%d ", get(&list, i));
    }
    printf("\n");

    set(&list, 0, 100);

    for (int i = 0; i < size(&list); ++i) {
        printf("%d ", get(&list, i));
    }
    printf("\n");

    freeArrayList(&list);

    return 0;
}
