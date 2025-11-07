// #include "stringManager.c"
#include <stdlib.h>
#include <stdio.h>
#include "listManagerVanilla.c"

typedef struct String String;

struct String{
    char *charList;
    size_t size;
};

void setupString(String *string){
    string->size = 0;
    string->charList = malloc(1);
}

//Adding a element into a string
int addToStringAChar(String *string, char listToAdd[]){
    int index = 0;

    int oldSize = string->size;
    int newSize = string->size + size(listToAdd);

    string->size = newSize;
    
    // printf("\nListSize = %d // Oldsize = %d // NewSize = %d", size(listToAdd), oldSize, newSize);

    char *newCharList = realloc(string->charList, newSize);

    if(newCharList == NULL){
        printf("Error: reallocation of memory failed for the string");
        return 0;
    }

    string->charList = newCharList;
    // printf("\nGot the memory reallocated!");

    // printf("\ngot the oldSize: %d; newSize = %d", oldSize, newSize);
    for(int i = oldSize; i < newSize; i++){
        // printf("\nadding the letter: %c", listToAdd[index]);
        string->charList[i] = listToAdd[index];
        // printf("\nAdded the element : %c", string->charList[i]);
        index++;
    }

    return 0;
}

int addToStringAString(String *string, String stringToAdd){
    int index = 0;

    int oldSize = string->size;
    int newSize = string->size + stringToAdd.size;

    string->size = newSize;

    char *newCharList = realloc(string->charList, newSize);

    if(newCharList == NULL){
        printf("Error: reallocation of memory failed for the string");
        return 0;
    }

    string->charList = newCharList;

    for(int i = oldSize; i < newSize; i++){
        string->charList[i] = stringToAdd.charList[index];
        index++;
    }

    return 0;
}

int addToStringAInt(String *string, long long unsigned numberToAdd){
    int sizeOfCharList = 1;
    char *charListMem = malloc(sizeOfCharList);

    while(numberToAdd > 9){
        char *reallocMemory = realloc(charListMem, sizeOfCharList);
        charListMem = reallocMemory;

        charListMem[sizeOfCharList] = '0' + (numberToAdd % 10);
        numberToAdd /= 10;

        sizeOfCharList++;
    }

    charListMem[sizeOfCharList] = '0' + numberToAdd;

    char *reallocMemory = realloc(charListMem, sizeOfCharList);
    charListMem = reallocMemory;

    char revCharList[sizeOfCharList];
    int index = 0;

    for(int i = sizeOfCharList; i > 0; i--){
        revCharList[index] = charListMem[i];
        index++;
    }

    index = 0;
    int oldSize = string->size;
    int newSize = string->size + sizeOfCharList;

    string->size = newSize;

    char *charListRealloc = realloc(string->charList, newSize);

    if(charListRealloc == NULL){
        printf("Error: reallocation of memory failed for the string");
        return 0;
    }
    
    string->charList = charListRealloc;

    for(int i = oldSize; i < newSize; i++){
        string->charList[i] = revCharList[index];
        index++;
    }

    return 0;
}

int concatenateWithChar(String *string, char listeToAdd[]){
    int index = 0;
    
    int oldSize = string->size;
    int newSize = string->size + size(listeToAdd);

    char *charListRealloc = realloc(string->charList, newSize);

    if(charListRealloc == NULL){
        printf("Error: reallocation of memory failed for the string");
        return 0;
    }

    string->charList = charListRealloc;
    string->size = newSize;

    for(int i = oldSize; i < newSize; i++){
        string->charList[i] = listeToAdd[index];
        index++;
    }

    return 0;
}

int printString(String string){
    for(int i = 0; i < string.size; i++){
        printf("%c", string.charList[i]);
    }

    return 0;
}