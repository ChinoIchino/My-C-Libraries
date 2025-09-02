#define size(liste) \
    _Generic((liste[0]), short: shortListSize, unsigned short: unsignedShortListSize, int: intListSize, unsigned int: unsignedIntListSize, long: longListSize, unsigned long: unsignedLongListSize,  float: floatListSize, double: doubleListSize, long double: longDoubleListSize, char: charListSize, default: defaultExit)(liste)

//short
int shortListSize(short liste[]){
    int i = 0;
    int count = 0;
    while(liste[i] != '\0'){
        i++;
        count++;
    }
    return count;
}
int unsignedShortListSize(unsigned short liste[]){
    int i = 0;
    int count = 0;
    while(liste[i] != '\0'){
        i++;
        count++;
    }
    return count;
}

//int
int intListSize(int liste[]){
    int i = 0;
    int count = 0;
    while(liste[i] != '\0'){
        i++;
        count++;
    }
    return count;
}
int unsignedIntListSize(unsigned int liste[]){
    int i = 0;
    int count = 0;
    while(liste[i] != '\0'){
        i++;
        count++;
    }
    return count;
}

//long
int longListSize(long liste[]){
    int i = 0;
    int count = 0;
    while(liste[i] != '\0'){
        i++;
        count++;
    }
    return count;
}
int unsignedLongListSize(unsigned long liste[]){
    int i = 0;
    int count = 0;
    while(liste[i] != '\0'){
        i++;
        count++;
    }
    return count;
}

//float
int floatListSize(float liste[]){
    int i = 0;
    int count = 0;
    while(liste[i] != '\0'){
        i++;
        count++;
    }
    return count;
}

//double
int doubleListSize(double liste[]){
    int i = 0;
    int count = 0;
    while(liste[i] != '\0'){
        i++;
        count++;
    }
    return count;
}
int longDoubleListSize(long double liste[]){
    int i = 0;
    int count = 0;
    while(liste[i] != '\0'){
        i++;
        count++;
    }
    return count;
}

//char
int charListSize(char liste[]){
    int i = 0;
    int count = 0;
    while(liste[i] != '\0'){
        i++;
        count++;
    }
    return count;
}

//default
int defaultExit(){
    return -1;
}