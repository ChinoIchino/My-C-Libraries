#include <stdio.h>
#include <stdbool.h>
#include "stringManager.c"

typedef struct Key Key;

struct Key{
    int howMuchBefore;
    int howMuchAfter;

    String toFind;
};

void initKey(Key *key, String toFind, int howMuchBefore, int howMuchAfter){
    if(howMuchAfter > 0){
        key->howMuchAfter = howMuchAfter;
    }else{
        key->howMuchAfter = 0;
    }
    
    if(howMuchBefore > 0){
        key->howMuchBefore = howMuchBefore;
    }else{
        key->howMuchBefore = 0;
    }

    key->toFind = toFind;
}

void printKey(Key key){
    printf("\nKey Informations:\nHowMuchBefore: %d\nHowMuchAfter: %d", key.howMuchBefore, key.howMuchAfter);
}

