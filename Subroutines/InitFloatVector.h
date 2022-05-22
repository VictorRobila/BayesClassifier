
/*
InitFloatVector.c

PURPOSE

    This subroutine builds a vector that is filled with random floats and normalized such that the total sum of every term is equal to 1

INPUT ARGUMENTS

array: empty float vector. This is the array that will be filled in this function. 
dim: This will be the number of columns and is an integer.

OUTPUT

This function outputs a filled and normalized 1d float array. This array can then be called in other functions.

*/

// These two includes help make the randomizer work
#include <stdlib.h>
#include <time.h>
#include "PrintFloatVector.h"
#include <stdio.h>
#include "common.h"

int TODEBUG;

void initFloatVector(float * array, int dim, int seed){
    float sum=0;
    float sum1=0;
    // The sum of all the floats is 0 when the array is empty
    srand((unsigned int)seed);
    // This sets up the random function using the seed from the clock
    for (int i=0; i<dim; i++){
           array[i]=rand()%50+1;
            // Each element of the array is given a random value
           sum +=array[i];
            // Each of the values is added to the sum
    }
    
    for (int i=0; i<dim; i++){
        // Each value in the array is normalized by dividing the value over the total sum
           array[i]/=sum;
    }
   if (TODEBUG==1){
       printf("marginal probability of P(d) \n");
       printFloatVector(array,dim);    
   }
}