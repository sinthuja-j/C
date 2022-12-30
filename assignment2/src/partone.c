#include <stdio.h>
/*
 * Assignment 3: Arrays
 * Purpose: Perform different calculations with an array
 * Author: Sinthuja Jeevarajhan
 * Professor: Will Beldman
 * Date: October 14 2022
 */

//print function- to print the array and the values in each position to the user
void print(int num[], int numIntegers) {
    printf("Your array is: ");
    for (int i=0; i<numIntegers; i++) {
        //if it is the last element don't put a comma afterwards
        if (i == numIntegers-1) {
            printf("[%d] = %d\n", i, num[i]);
        }
        else {
            printf("[%d] = %d, ", i, num[i]);
        }

    }
}
//max function- print the largest value in the array
void max(int num[], int numIntegers) {
    int maxVal=0;
    for (int i=0; i< numIntegers; i++) {
        //if the value is bigger than the largest value, store that value
        if (num[i] > maxVal) {
            maxVal= num[i];
        }
    }
    //print the value to the user
    printf("The largest value in your array is: %d", maxVal);
}
//reverse function- print the elements of the array in reverse order
void reverse(int num[], int numIntegers) {
    printf("\nYour array in reverse is: ");
    //traverse the array backwards
    for (int i=numIntegers-1; i>=0; i--) {
        printf("%d ", num[i]);
    }
}
//sum function- add all the values in the array
void sum(int num[], int numIntegers) {
    int sumTotal=0;
    //add all the values in the array
    for (int i=0; i< numIntegers; i++) {
        sumTotal+= num[i];
    }
    printf("\nThe sum of all the values in your array is: %d", sumTotal);
}
//sort the array in ascneding order
void sorted(int num[], int numIntegers) {
    int tmp=0;
    int tmpArray[numIntegers];
    //store the values in a temporary array
    for (int i=0; i< numIntegers; i++) {
        tmpArray[i] = num[i];
    }
    //sort the order using inplace sorting and store it in the temporary array
    for (int i=0; i< numIntegers; i++) {
       for (int j= i+1; j< numIntegers; j++) {
            if(tmpArray[i] < tmpArray[j]) {
                tmp= tmpArray[i];
                tmpArray[i]= tmpArray[j];
                tmpArray[j]= tmp;
            }
       }
    }
    //output the array in sorted order
    printf("\nYour array in sorted order is: ");
    for (int i=0; i<numIntegers; i++) {
        printf("%d ", tmpArray[i]);
    }
}
//swap the first and last value in the array
void swap(int num[], int numIntegers) {
    int tmp[numIntegers];
    //copy the elments into a temporary array
    for (int i=0; i<numIntegers; i++) {
        tmp[i]= num[i];
    }
    //store the first and last element and swap them
    int first= num[0];
    int pos= numIntegers-1;
    int last= tmp[pos];
    tmp[0]= last;
    tmp[numIntegers-1]= first;

    printf("\nYour array with the first and last element switched is: ");
    //output the new array to the user
    for (int i=0; i<numIntegers; i++) {
        printf("%d ", tmp[i]);
    }

}
int main() {
    //iniatialize the variables
    int numIntegers;
    int flag=1;
    int result;
    int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12;
    //get the number of integers from the user
    do {
        printf("\nPlease enter the number of integers to process: ");
        scanf("%d", &numIntegers);
        //error checking
        if (numIntegers < 5 || numIntegers > 12) {
            printf("\nError: Please enter a number between 5-12");
        }
        //ensure the user enters an integer between 5 and 12
    } while (numIntegers < 5 || numIntegers > 12); //ask what to do if user enters float (check if float or neg then conver to number and loop switch) and validate integers for switch
    int a[numIntegers];
    //switch to create an array based on users specified size
    switch(numIntegers) {
        case 5:
            //ask the user to enter the values to input into the array and display the sizw
            printf("\nThere is enough room in your array for %d integers (%d bytes)", numIntegers, ((int) sizeof a));
            printf("\nPlease enter your integers seperated by spaces: ");
            scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);
            //initalize the values in the array
            a[0]= num1;
            a[1]= num2;
            a[2]= num3;
            a[3]= num4;
            a[4]= num5;
            break;
        case 6:
            //ask the user to enter the values to input into the array and display the sizw
            printf("\nThere is enough room in your array for %d integers (%d bytes)", numIntegers, ((int) sizeof a));
            printf("\nPlease enter your integers seperated by spaces: ");
            scanf("%d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6);
            //initalize the values in the array
            a[0]= num1;
            a[1]= num2;
            a[2]= num3;
            a[3]= num4;
            a[4]= num5;
            a[5]= num6;
            break;
        case 7:
            //ask the user to enter the values to input into the array and display the sizw
            printf("\nThere is enough room in your array for %d integers (%d bytes)", numIntegers, ((int) sizeof a));
            printf("\nPlease enter your integers seperated by spaces: ");
            scanf("%d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7);
            //initalize the values in the array
            a[0]= num1;
            a[1]= num2;
            a[2]= num3;
            a[3]= num4;
            a[4]= num5;
            a[5]= num6;
            a[6]= num7;
            break;
        case 8:
            //ask the user to enter the values to input into the array and display the sizw
            printf("\nThere is enough room in your array for %d integers (%d bytes)", numIntegers, ((int) sizeof a));
            printf("\nPlease enter your integers seperated by spaces: ");
            scanf("%d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8);
            //initalize the values in the array
            a[0]= num1;
            a[1]= num2;
            a[2]= num3;
            a[3]= num4;
            a[4]= num5;
            a[5]= num6;
            a[6]= num7;
            a[7]= num8;
            break;
        case 9:
            //ask the user to enter the values to input into the array and display the sizw
            printf("\nThere is enough room in your array for %d integers (%d bytes)", numIntegers, ((int) sizeof a));
            printf("\nPlease enter your integers seperated by spaces: ");
            scanf("%d %d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9);
            //initalize the values in the array
            a[0]= num1;
            a[1]= num2;
            a[2]= num3;
            a[3]= num4;
            a[4]= num5;
            a[5]= num6;
            a[6]= num7;
            a[7]= num8;
            a[8]= num9;
            break;
        case 10:
            //ask the user to enter the values to input into the array and display the sizw
            printf("\nThere is enough room in your array for %d integers (%d bytes)", numIntegers, ((int) sizeof a));
            printf("\nPlease enter your integers seperated by spaces: ");
            scanf("%d %d %d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10);
            //initalize the values in the array
            a[0]= num1;
            a[1]= num2;
            a[2]= num3;
            a[3]= num4;
            a[4]= num5;
            a[5]= num6;
            a[6]= num7;
            a[7]= num8;
            a[8]= num9;
            a[9]= num10;
            break;
        case 11:
            //ask the user to enter the values to input into the array and display the sizw
            printf("\nPlease enter your integers seperated by spaces: ");
            scanf("%d %d %d %d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11);
            //initalize the values in the array
            a[0]= num1;
            a[1]= num2;
            a[2]= num3;
            a[3]= num4;
            a[4]= num5;
            a[5]= num6;
            a[6]= num7;
            a[7]= num8;
            a[8]= num9;
            a[9]= num10;
            a[10]= num11;
            break;
        case 12:
            //ask the user to enter the values to input into the array and display the sizw
            printf("\nThere is enough room in your array for %d integers (%d bytes)", numIntegers, ((int) sizeof a));
            printf("\nPlease enter your integers seperated by spaces: ");
            scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12);
            //initalize the values in the array
            a[0]= num1;
            a[1]= num2;
            a[2]= num3;
            a[3]= num4;
            a[4]= num5;
            a[5]= num6;
            a[6]= num7;
            a[7]= num8;
            a[8]= num9;
            a[9]= num10;
            a[10]= num11;
            a[11]= num12;
            break;

    }
    print(a, numIntegers);
    max(a, numIntegers);
    reverse(a, numIntegers);
    sum(a, numIntegers);
    sorted(a, numIntegers);
    swap(a, numIntegers);
    return 0;
}
