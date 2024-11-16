#include <iostream>
#include <stdio.h> 

typedef struct {
    int day;
    int month;
    int year;
} ZodiacDate;

int getZodiacSign(ZodiacDate date) {
    if ((date.month == 1 && date.day >= 22) || (date.month == 2 && date.day < 22)) {
        return 0; // Rat
    } else if ((date.month == 2 && date.day >= 22) || (date.month == 3 && date.day < 22)) {
        return 1; // Ox
    } else if ((date.month == 3 && date.day >= 22) || (date.month == 4 && date.day < 22)) {
        return 2; // Tiger
    } else if ((date.month == 4 && date.day >= 22) || (date.month == 5 && date.day < 22)) {
        return 3; // Rabbit
    } else if ((date.month == 5 && date.day >= 22) || (date.month == 6 && date.day < 22)) {
        return 4; // Dragon
    } else if ((date.month == 6 && date.day >= 22) || (date.month == 7 && date.day < 22)) {
        return 5; // Snake
    } else if ((date.month == 7 && date.day >= 22) || (date.month == 8 && date.day < 22)) {
        return 6; // Horse
    } else if ((date.month == 8 && date.day >= 22) || (date.month == 9 && date.day < 22)) {
        return 7; // Goat/Sheep
    } else if ((date.month == 9 && date.day >= 22) || (date.month == 10 && date.day < 22)) {
        return 8; // Monkey
    } else if ((date.month == 10 && date.day >= 22) || (date.month == 11 && date.day < 22)) {
        return 9; // Rooster
    } else if ((date.month == 11 && date.day >= 22) || (date.month == 12 && date.day < 22)) {
        return 10; // Dog
    } else {
        return 11; // Pig
    }
}

const char* getZodiacAnimal(int zSign) {
    switch(zSign) {
        case 0: return "Rat";
        case 1: return "Ox";
        case 2: return "Tiger";
        case 3: return "Rabbit";
        case 4: return "Dragon";
        case 5: return "Snake";
        case 6: return "Horse";
        case 7: return "Goat/Sheep";
        case 8: return "Monkey";
        case 9: return "Rooster";
        case 10: return "Dog";
        case 11: return "Pig";
        default: return "Invalid Zodiac Sign"; 
    }
}

int isCompatibleZodiac(int zodiac1, int zodiac2) {
    int diff = (zodiac1 - zodiac2 + 12) % 12;
    return (diff == 0 || diff == 4 || diff == 8);

} 

int main() {
    ZodiacDate myDate, friendDate;

    // Get user's birthdate
    printf("Please write your birth month (a number between 1 and 12): ");
    scanf_s("%d", &myDate.month);
    printf("Please write your birth day: ");
    scanf_s("%d", &myDate.day);
    printf("Please write your birth year: ");
    scanf_s("%d", &myDate.year);

    // Get friend's birthdate
    printf("Please write your friend's birth month (a number between 1 and 12): ");
    scanf_s("%d", &friendDate.month);
    printf("Please write your friend's birth day: ");
    scanf_s("%d", &friendDate.day);
    printf("Please write your friend's birth year: ");
    scanf_s("%d", &friendDate.year);

    // Determine zodiac signs
    int myZSign = getZodiacSign(myDate);
    int friendZSign = getZodiacSign(friendDate);

    // Get zodiac animals
    const char* myZAnimal = getZodiacAnimal(myZSign);
    const char* friendZAnimal = getZodiacAnimal(friendZSign);

    // results gives your and your friends chinese zodiac 
    printf("Your Chinese Zodiac Animal is: %s\n", myZAnimal);
    printf("Your friend's Chinese Zodiac Animal is: %s\n", friendZAnimal);

    // Check compatibility
   //  if (myZSign == friendZSign) {
   //     printf("You are compatible!\n");
   // } else {
    //printf("You are not compatible.\n");
   // }


    // Check compatibilty (A-Grade) 
    if (isCompatibleZodiac(myZSign , friendZSign)) {
        printf("You are compatible.\n", myZSign, friendZSign);
    }
    else {
        printf("You are NOT compatible.\n", myZSign, friendZSign);
    }

 

    return 0;
}
