
/*
InitFloatArray.c

PURPOSE

    This subroutine builds a 2 dimentional array that is filled with random floats and normalized such that the total sum of every term is equal to 1

INPUT ARGUMENTS

array: 2 dimentional empty float array. This is the array that will be filled in this function. 
dim1: The first dimension. This will be the number of columns and is an integer.
dim2: The second dimension. This will be the number of rows and is an integer.

OUTPUT

This function outputs a filled and normalized 2d float array. This array can then be called in other functions.

*/

// These two includes help make the randomizer work
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "common.h"

void initFloatArray(float ** array, int dim1, int dim2, int seed){
    float sum=0;
    // The sum of all the floats is 0 when the array is empty
    srand((unsigned int)seed);
    // This sets up the random function using the seed from the clock
    for (int i=0; i<dim1; i++)
        // This for loop sets up the columns
        for (int j=0; j<dim2; j++){
            // This for loop sets up the rows
           array[i][j]=rand()%50+1;
            // Each element of the array is given a random value
           sum +=array[i][j];
            // Each of the values is added to the sum
        }
    

    for (int i=0; i<dim1; i++){
        for (int j=0; j<dim2; j++){
            // Each value in the array is normalized by dividing the value over the total sum
           array[i][j]/=sum;
           
        }
    }
}