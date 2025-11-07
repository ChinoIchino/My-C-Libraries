//A Library striped of all functions that wasn't used in the StringFinder.c 

#include <stdio.h>
#include <stdlib.h>

typedef struct IntList IntList;

struct IntList{
    int *object;
    struct IntList *adresseToNext;
};

int isEmpty(IntList list){
    if(list.object == NULL){
        return 1;
    }
    return 0;
}

int getSize(IntList *list) {
    int count = 0;
    while (list != NULL && list->object != NULL) {
        count++;
        list = list->adresseToNext;
    }

    return count;
}

int getElement(IntList *list, unsigned int index){
    if(index < getSize(list)){
        for(int i = 0; i < index; i++){
            list = list->adresseToNext;
        }

        return *list->object;
    }else{
        printf("\nIntList\\Error: Index \"%d\" out of range || Returning -1", index);
        return -1;
    }
}

void setupList(IntList *list){
    list->object = NULL;
    list->adresseToNext = NULL;
}


void add(IntList *list, int element){
    if (isEmpty(*list)){
        list->object = malloc(sizeof(int));
        *list->object = element;

        list->adresseToNext = NULL;
        // printf("added the element %d", element);
    } else {
        if (list->adresseToNext == NULL) {
            list->adresseToNext = malloc(sizeof(IntList));
            setupList(list->adresseToNext);
        }
        add(list->adresseToNext, element);
    }
}