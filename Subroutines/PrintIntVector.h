/*
PrintIntVector.c

PURPOSE

    This subroutine prints an integer vector

INPUT ARGUMENTS

vector: This is the vector that will be printed
dim1: The first dimension. This will be the number of columns and is an integer.


OUTPUT

A printed version of the integer vector

*/

// This include is necessary for the print function

#ifndef _PRINTINTVECT_H_
#define _PRINTINTVECT_H_

#include <stdio.h>

void printIntVector(int * vector, int dim1){
    // This for loop allows us to get each term in the vector
    for (int i=0; i<dim1; i++){
        // Each term in the vector is printed
        printf("%d\t",vector[i]);
    }
    // A new line is added
    printf("\n");
}

#endif
