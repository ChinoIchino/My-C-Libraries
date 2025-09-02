#include "stringManager.c"

int getYearFromSeconds(long unsigned int second){
    int year = 1970;

    while(second >= 31536000){
        second -= 31536000;
        year++;
    }

    return year;
}

int getDaysFromSeconds(long unsigned int second){
    int day = 0;

    while(second >= 86400){
        second -= 86400;
        day++;
    }

    return day;
}

int getMonthFromDays(int unsigned day){
    if(day <= 31){
        return 1;
    }
    else if(day > 31 && day <= 59){
        return 2;
    }
    else if(day > 59 && day <= 90){
        return 3;
    }
    else if(day > 90 && day <= 120){
        return 4;
    }
    else if(day > 120 && day <= 151){
        return 5;
    }
    else if(day > 151 && day <= 181){
        return 6;
    }
    else if(day > 181 && day <= 212){
        return 7;
    }
    else if(day > 212 && day <= 243){
        return 8;
    }
    else if(day > 243 && day <= 273){
        return 9;
    }
    else if(day > 273 && day <= 304){
        return 10;
    }
    else if(day > 304 && day <= 334){
        return 11;
    }
    else{
        return 12;
    }
}

int getDayDate(int month, int days){
    switch (month){
        case 1:
            return days;
            break;
        case 2:
            return days - 31;
            break;
        case 3:
            return days - 59;
            break;
        case 4:
            return days - 90;
            break;
        case 5:
            return days - 120;
            break;
        case 6:
            return days - 151;
            break;
        case 7:
            return days - 181;
            break;
        case 8:
            return days - 212;
            break;
        case 9:
            return days - 243;
            break;
        case 10:
            return days - 273;
            break;
        case 11:
            return days - 304;
            break;
        case 12: 
            return days - 334;
            break;
        default:
            return -1;
            break;
    }
}

String getFullDateString(long unsigned seconds){
    int year = getYearFromSeconds(seconds);
    int day = getDaysFromSeconds(seconds);

    int leapYearDeCount = 2;
    while(day >= 365 || (leapYearDeCount == 0 && day == 366)){
        if(leapYearDeCount != 0){
            day -= 365;
            leapYearDeCount--;
        }else{
            day -= 366;
            leapYearDeCount = 3;
        }
        //printf("Got the day in the loop : %d", day);
    }

    int month = getMonthFromDays(day);
    day = getDayDate(month, day) + 1;

    printf("\n\n%d / %d / %d\nStarting Doing A String...\n", day, month, year);

    String dateString;
    setupString(&dateString);

    if(day <= 9){
        addToStringAChar(&dateString, "0");
        addToStringAInt(&dateString, day);
    }else{
        addToStringAInt(&dateString, day);
    }

    addToStringAChar(&dateString, "_");

    if(month <= 9){
        addToStringAChar(&dateString, "0");
        addToStringAInt(&dateString, month);
    }else{
        addToStringAInt(&dateString, month);
    }

    addToStringAChar(&dateString, "_");
    addToStringAInt(&dateString, year);
    
    printString(dateString);
    return dateString;
}