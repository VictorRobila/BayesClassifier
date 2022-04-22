/*
PrintIntArray.c

PURPOSE

    This subroutine prints a 2 dimentional integer array

INPUT ARGUMENTS

array: 2 dimentional integer array. This is what will be printed.
dim1: The first dimension. This will be the number of columns and is an integer.
dim2: The second dimention. This will be the number of rows and is an integer.

OUTPUT

A printed version of the 2d integer array

*/

// This include is necessary for the print function

#ifndef _PRINTINTARR_H_
#define _PRINTINTARR_H_
#include <stdio.h>

void printIntArray(int ** array, int dim1, int dim2){
    // This for loop allows the function to get to each value in the array
    for (int i=0; i<dim1; i++){
        for (int j=0; j<dim2; j++)
            // Each value in the array is printed
           printf("%d\t",array[i][j]);
        // Each row in the array is printed in a new line
        printf("\n");
    }
}

#endif