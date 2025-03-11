#include <stdio.h>
/*
 * Assignment 1: Part One; Converter Program
 * Purpose: Convert the user's input into different metric types that they prefer
 * Author: Sinthuja Jeevarajhan (251241418)
 * CS 2211; Professor Beldman
 * Date: Sep 29 2022
 */

int main() {
    int selection; //variable to store what type of conversion the user wishes to complete
    int flag = 1; //variable to create an infinite loop, only exit if user enters 5 to quit the program
    char choice; //choice of which way they would like the conversion to take place
    float conversionValue; //value the user wishes to convert
    double calculatedValue; //return value of the converted value
    while (flag) {
        //Welcome message, to display the conversion options
        printf("\nHi! Which conversion would you like to complete today? Please enter a number from (1-5)\n(1) Conversion between kilograms and pounds\n(2) Conversion between Hectares and Acres\n(3) Conversion between Litres and Gallons\n(4)Conversion between Kilometers and Miles\n(5)Quit\n");
        //Prompt the user to enter a number to indicate which conversion they wishes to take place
        printf("Please enter your selection: ");
        scanf("%d", &selection);

        //Another prompt if user input was incorrect, keeps prompting user for input until they enter desired input (1-5)
        while ((selection < 0) || (selection > 5)) {
            printf("\nHi! Which conversion would you like to complete today? Please enter a number from (1-5)\n(1) Conversion between kilograms and pounds\n(2) Conversion between Hectares and Acres\n(3) Conversion between Litres and Gallons\n(4)Conversion between Kilometers and Miles\n(5)Quit\n");
            printf("Please enter your selection: ");
            scanf("%d", &selection);

        }
        //if their choice is 5 quit the program
        if (selection == 5)
            return 0;

        //switch statement; has 4 different options for different conversions that can take place
        switch (selection) {
            case 1:
                do {
                    //display type of conversion and prompt user to enter which way they would like the conversion to take place
                    printf("If you would like to convert from Kilograms to Pounds enter K\nOtherwise enter P to convert from Pounds to Kilograms: ");
                    scanf(" %c", &choice);
                } while ((choice != 'K') && (choice != 'P')); //keep asking user until they enter correct input

                //if choice if kilograms to pounds
                if (choice == 'K') {
                    printf("Please enter a value for the number of Kilograms: ");
                    scanf("%f", &conversionValue);
                    //calculate the converted value
                    calculatedValue = conversionValue * 2.20462;
                    //display the converted value back to the user
                    printf("Your conversion is: %lf", calculatedValue);
                }
                //if choice is pounds to kilograms
                if (choice == 'P') {
                    printf("Please enter a value for the number of Pounds: ");
                    scanf("%f", &conversionValue);
                    //calculate the converted value
                    calculatedValue = conversionValue / 2.20462;
                    //display the converted value back to the user
                    printf("Your conversion is: %lf", calculatedValue);
                }
                break;
            case 2:
                do {
                    //display type of conversion and prompt user to enter which way they would like the conversion to take place
                    printf("If you would like to convert from Hectares to Acres enter H \nOtherwise enter A to convert from Acres to Hectares: ");
                    scanf(" %c", &choice);
                } while ((choice != 'H') && (choice != 'A')); //keep asking user until they enter correct input
                //if the choice is hectares to acres
                if (choice == 'H') {
                    printf("Please enter a value for the number of Hectares: ");
                    scanf("%f", &conversionValue);
                    //calculate the converted value
                    calculatedValue = conversionValue * 2.47105;
                    //display the converted value back to the user
                    printf("Your conversion is: %lf", calculatedValue);
                }
                //if the choice is acres to hectares
                if (choice == 'A') {
                    printf("Please enter a value for the number of Acres: ");
                    scanf("%f", &conversionValue);
                    //calculate the converted value
                    calculatedValue = conversionValue / 2.47105;
                    //display the converted value back to the user
                    printf("Your conversion is: %lf", calculatedValue);
                }
                break;
            case 3:
                do {
                    //display type of conversion and prompt user to enter which way they would like the conversion to take place
                    printf("If you would like to convert from Litres to Gallons enter L \nOtherwise enter G to convert from Gallons to Litres: ");
                    scanf(" %c", &choice);
                } while ((choice != 'L') && (choice != 'G')); //keep asking user until they enter correct input
                //if the choice is liters to gallon
                if (choice == 'L') {
                    printf("Please enter a value for the number of Litres: ");
                    scanf("%f", &conversionValue);
                    //calculate the converted value
                    calculatedValue = conversionValue * 0.264172;
                    //display the converted value back to the user
                    printf("Your conversion is: %lf", calculatedValue);
                }
                //if the choice is gallons to liters
                if (choice == 'G') {
                    printf("Please enter a value for the number of Gallons: ");
                    scanf("%f", &conversionValue);
                    //calculate the converted value
                    calculatedValue = conversionValue * 3.78541;
                    //display the converted value back to the user
                    printf("Your conversion is: %lf", calculatedValue);
                }
                break;
            case 4:
                do {
                    //display type of conversion and prompt user to enter which way they would like the conversion to take place
                    printf("If you would like to convert from Kilometers to Miles enter K\nOtherwise enter M to convert from Miles to Kilometers: ");
                    scanf(" %c", &choice);
                } while ((choice == 'K') && (choice == 'P')); //keep asking user until they enter correct input
                //if the choice is kilometers to miles
                if (choice == 'K') {
                    printf("Please enter a value for the number of Kilometers: ");
                    scanf("%f", &conversionValue);
                    //calculate the converted value
                    calculatedValue = conversionValue * 0.621371;
                    //display the converted value back to the user
                    printf("Your conversion is: %lf", calculatedValue);
                }
                //if the choice is miles to kilometers
                if (choice == 'M') {
                    printf("Please enter a value for the number of Miles: ");
                    scanf("%f", &conversionValue);
                    //calculate the converted value
                    calculatedValue = conversionValue * 1.60934;
                    //display the converted value back to the user
                    printf("Your conversion is: %lf", calculatedValue);
                }
                break;
        }

    }
    return 0;

}
