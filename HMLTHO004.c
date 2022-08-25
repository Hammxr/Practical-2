#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "HMLTHO004"
#define YEAR "2022"

int main(void){ //driver function
    int num = 0; // initialising variables
    int rad = 0;
    printf("*****************************");
    printf("\n" TITLE);
    printf("\nWritten by: " AUTHOR);
    printf("\nDate: " YEAR);
    printf("\n*****************************");


    printf("\nEnter a decimal number: "); // if this input is not here, the while loop will not be initialised as num will essentially be undefined for the loop
    scanf("%d", &num);

    while(num >= 0){ // loop to make sure that an input from the user is continuously prompted

        printf("The number you have entered is %d\n", num);
        printf("Enter a radix for the converter between 2 and 16: "); // asking the user to input a radix
        scanf("%d", &rad);
        printf("The radix you have entered is %d\n", rad);
        printf("The log2 of the number is %.2f\n", log2(num)); // determining the log2() of the decimal input

        int quotient = 0;
        quotient = num/rad;
        printf("The integer result of the number divided by %d is %d\n",rad, quotient); // returning the quotient of the decimal divided by the radix

        int rem = 0;
        rem = num%rad; // modulus operator returns the remainder of the two values
        printf("The remainder is %d\n", rem); // printing the remainder


        printf("The radix-%d value is ", rad);
        Dec2RadixI(num, rad);  // calling upon the function defined below to print the converted radix-i

        printf("\nEnter a decimal number: "); // this will prompt a further decimal input from the user
        scanf("%d", &num);

    }
    printf("EXIT"); // this will print if the decimal entered is less than 0
    return 0;
}

void Dec2RadixI(int decValue, int radValue){

    int i = 0;  // initialise index to store the result
    char radix[100];
    int temp;  // variable to store a temporary value
    char val;  // char to hold a temporary char

    while(decValue > 0){  // ensures that whilst input decimal is greater than zero, the loop will still run

        temp=decValue%radValue;  // returns the remainder of decValue divided by radix input

        if (temp >= 0 && temp <= 9){  // assigning either a decimal or a letter depending on the size of the remainder
            val=(char)(temp + '0'); // if the remainder is between 0 and 9, an ascii value is assigned to it to determine the output value
        }
        else{
            val = (char)(temp - 10 +'A'); // if the remiander is greater than 9 an ascii value is assigned to it to determine the letter
        }
        radix[i++] = val; // assigning the value of the char to the array, count i is increased by 1
        decValue /= radValue;
    }
    radix[i] = '\0'; // this value is assigned to initialise a null space, this will uncomplicate in compiler errors
    int len = strlen(radix); // the length of the array is stored

    for (int j = len-1; j > 0; j--){ //for loop with j to implement half the string
        /* 1: storing the temporary char
        2: replace the array posistion witht the next increment given by len - j - 1,
        therefore radix[j] becomes radix[len - j -1]*/

        printf("%c", radix[j]); //the converted radix is returned to the driver function
    }
}














