#include <stdio.h>
#include <stdlib.h>

int isAccessible(const char *filePath){
    FILE *file = NULL;

    if((file = fopen(filePath, "r")) == NULL){
        return 1;
    }else{
        return 0;
    }
}

char* getFileToCharList(const char *filePath){
    FILE *file = NULL;
    
    if((file = fopen(filePath, "r")) == NULL){
        printf("\nERROR: Unable to access to the file. Check if the file path is correct And if you have permission to access it.");
    }

    fseek(file, 0L, SEEK_END);
    long sizeOfFile = ftell(file);

    char *listReturn = malloc(sizeOfFile);

    fseek(file, 0L, 0);

    char currChar;
    long index = 0;
    while((currChar = fgetc(file)) != EOF){
        listReturn[index] = currChar;
        index++;
    }

    fclose(file);

    return listReturn;
}

void printFile(const char *filePath){
    FILE *file = NULL;

    if((file = fopen(filePath, "r")) == NULL){
        printf("\nERROR: Unable to access to the file. Check if the file path is correct And if you have permission to access it.");
    }

    char currChar;
    while((currChar = fgetc(file)) != EOF){
        printf("%c", currChar);
    }

    fclose(file);
}

int sizeOfFile(const char *filePath){
    FILE *file = NULL;

    if((file = fopen(filePath, "r")) == NULL){
        printf("\nERROR: Unable to access to the file. Check if the file path is correct And if you have permission to access it.");
    }

    fseek(file, 0L, SEEK_END);
    long sizeOfFile = ftell(file);

    fclose(file);

    return sizeOfFile;
}

// int main(int argc, char *argv[]){
//     // printFile("testItem.txt");

//     // long size = sizeOfFile("testItem.txt");
//     // printf("The size of the file: %d", size);

//     // char *list = getFileToCharList("testItem.txt");
//     // printf("Got: \n%s", list);
// }