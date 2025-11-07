#include <stdio.h>
#include "Key.c"
#include "FileManager.c"
// #include "ArrayListForStringSearcher.c"
#include "ArrayListV3.c"

void printWordByIndexes(char* contentOfFile, IntList* listOfIndex, Key key){
    int indexOfItem;

    for(int i = 0; i < getSize(listOfIndex); i++){
        indexOfItem = getElement(listOfIndex, i) - 1;
        printf("Element at index %d: ", indexOfItem);
        for(int j = (indexOfItem - key.howMuchBefore); j < (indexOfItem + key.toFind.size + key.howMuchAfter); j++){
            printf("%c", contentOfFile[j]);
        }
        printf("\n");
    }
    printf("\nTotal number of items found: %d", getSize(listOfIndex));
}

void findString(const char *filePath, Key key){
    // printf("\ngot the string: %s", key.toFind.charList);
    // printf("\n0");
    char *contentOfFile = getFileToCharList(filePath);

    IntList *indexListOfItemFound = malloc(sizeof(IntList));
    setupList(indexListOfItemFound);
    
    long sizeOfItem = key.toFind.size;
    char *item = key.toFind.charList;
    // printf("\ngot the item = %s", item);
    int count = 0;

    // printf("\ngot the string: %s", item);

    // printf("\n1");
    for(int i = 0; i < size(contentOfFile); i++){
        if(contentOfFile[i] == item[count] || (contentOfFile[i] + 32) == item[count]){
            // printf("\ncomparing %c == %c || %c == %c", contentOfFile[i], item[count], (contentOfFile[i] + 32), item[count]);
            count++;
        }else{
            count = 0;
        }

        if(count == sizeOfItem){
            // printf("\n2");
            add(indexListOfItemFound, (i - count + 2));
            count = 0;
        }
    }
    // printf("got to printWord\n size of list = %d", getSize(indexListOfItemFound));
    printWordByIndexes(contentOfFile, indexListOfItemFound, key);
}


int main(int argc, char *argv[]){
    char *filePath = malloc(50);
    printf("File where the item need to be found: ");
    scanf("%s", filePath);

    String *toFind = malloc(sizeof(String));

    setupString(toFind);

    char stringToFind[30];
    printf("\nElement to find (all smaller cases): ");
    scanf("%s", &stringToFind);

    addToStringAChar(toFind, stringToFind);

    // printf("\nHow much character before the item need to be harvested: ");
    // int elBefore;
    // scanf("%d", &elBefore);
    // printf("How much after: ");
    // int elAfter;
    // scanf("%d", &elAfter);


    Key *keyT1 = malloc(sizeof(Key));
    initKey(keyT1, *toFind, 0, 0);
    // initKey(&keyT1, toFind, elBefore, elAfter);

    // int verif = isAccessible(filePath);
    // printf("\ngot the verif: %d\n", verif);

    findString(filePath, *keyT1);


    //Other:
    // Key keyT1;
    // initKey(&keyT1, toFind, 0, 0);

    // const char *path;
    // path = "testItem.txt";

    // // printf("got to the print");
    // // printFile(path);

    // findString("en_us.json", keyT1);
}