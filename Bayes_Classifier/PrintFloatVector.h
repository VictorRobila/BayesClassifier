/*
PrintFloatVector.c

PURPOSE

    This subroutine prints an float vector

INPUT ARGUMENTS

vector: This is the vector that will be printed
dim1: The first dimension. This will be the number of columns and is an float.


OUTPUT

A printed version of the float vector

*/

// This include is necessary for the print function
#ifndef _PRINTFLOATVECT_H_
#define _PRINTFLOATVECT_H_

#include <stdio.h>

void printFloatVector(float * vector, int dim1){
    // This for loop allows us to get each term in the vector
    for (int i=0; i<dim1; i++){
        // Each term in the vector is printed
        printf("%.5f\t",vector[i]);
    }
    // A new line is added
    printf("\n");
}

#endif