#include <stdio.h>
/*
 * Assignment 1: Part Two; Integer to Word in English
 * Purpose: Convert the user's integer input into the English word
 * Author: Sinthuja Jeevarajhan (251241418)
 * CS 2211; Professor Beldman
 * Date: Sep 29 2022
 */


int main() {
    //Declare the variables that store the value of each numerical digit
    int inputValue, hundred, ten, one;
    //Get the input from the user
    do {
        printf("\nPlease enter a value (1-999, 0 to quit): ");
        scanf("%d", &inputValue);
        //if they enter 0- quit the program
        if (inputValue == 0) {
            return 0;
        }
        //Begin the output message
        printf("You entered the number ");
        //calculate the value for the number of hundreds, tens and ones
        hundred = inputValue / 100;
        ten = (inputValue - (hundred * 100)) / 10;
        one = (inputValue - (hundred * 100) - (ten * 10));

        //output the correct english word of the number of hundreds
        if (hundred > 0) {
            switch (hundred) {
                case 9:
                    printf("nine hundred ");
                    break;
                case 8:
                    printf("eight hundred ");
                    break;
                case 7:
                    printf("seven hundred ");
                    break;
                case 6:
                    printf("six hundred ");
                    break;
                case 5:
                    printf("five hundred ");
                    break;
                case 4:
                    printf("four hundred ");
                    break;
                case 3:
                    printf("three hundred ");
                    break;
                case 2:
                    printf("two hundred ");
                    break;
                case 1:
                    printf("one hundred ");
                    break;
            }
        }

        //output the correct english word of the number of tens
        if (ten != 1) {
            switch (ten) {
                case 9:
                    printf("ninety ");
                    break;
                case 8:
                    printf("eighty ");
                    break;
                case 7:
                    printf("seventy ");
                    break;
                case 6:
                    printf("sixty ");
                    break;
                case 5:
                    printf("fifty ");
                    break;
                case 4:
                    printf("forty ");
                    break;
                case 3:
                    printf("thirty ");
                    break;
                case 2:
                    printf("twenty ");
                    break;
            }
            //output the correct english word of the number of ones
            if (one > 0) {
                switch (one) {
                    case 9:
                        printf("nine ");
                        break;
                    case 8:
                        printf("eight ");
                        break;
                    case 7:
                        printf("seven ");
                        break;
                    case 6:
                        printf("six ");
                        break;
                    case 5:
                        printf("five ");
                        break;
                    case 4:
                        printf("four ");
                        break;
                    case 3:
                        printf("three ");
                        break;
                    case 2:
                        printf("two ");
                        break;
                    case 1:
                        printf("one ");
                        break;
                }
            } else {
                printf("\n");
            }
            //output the correct english word of the number of ones if number is in the teens
        } else {
            if (one > 0) {
                switch (one) {
                    case 9:
                        printf("nineteen");
                        break;
                    case 8:
                        printf("eighteen");
                        break;
                    case 7:
                        printf("seventeen");
                        break;
                    case 6:
                        printf("sixteen");
                        break;
                    case 5:
                        printf("fifteen");
                        break;
                    case 4:
                        printf("fourteen");
                        break;
                    case 3:
                        printf("thirteen");
                        break;
                    case 2:
                        printf("twelve");
                        break;
                    case 1:
                        printf("eleven");
                        break;
                }
            } else {
                printf("Ten\n");
            }
        }

    }
    while (inputValue != 0); //terminate loop if the input value equals 0
    return 0;
}
