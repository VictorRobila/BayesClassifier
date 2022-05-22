/*
Shuffle.c

PURPOSE

    This subroutine randomly shuffles the one dimentional integer array that it is given

INPUT ARGUMENTS

array: This is an integer array. In Bayes_Classifer2.c it is the true class array.
size: The first dimension. This will be the number elements in the array.
seed: The user inputed seed for randomization

OUTPUT

A randomly shuffled one dimentional integer array

*/

// These includes are necessary for the randomization function.
#include <stdlib.h>
#include <time.h>
#include "PrintFloatVector.h"
#include "common.h"
#include <stdio.h>

void shuffle(int * arr, int size, int seed){
    // Initializes the randomization
    srand((unsigned int)seed);
    for (int i = 0; i < size; i++) {
        // Takes a random index from the array
        int j = rand() % size;
        // Sets the value to be moved
        int t = arr[i];
        // Moves the value to another position and replaces the other one
        arr[i] = arr[j];
        arr[j] = t;
    }
    if (TODEBUG == 1){
        printf("true class shuffled\n");
        printIntVector(arr,size);
        printf("\n");
    }
}
