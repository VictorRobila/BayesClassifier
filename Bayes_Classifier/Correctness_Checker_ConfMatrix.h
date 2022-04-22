/*
Correctness_Checker.c

PURPOSE

    This function find the correctness percentage of the assigned classes.

INPUT ARGUMENTS

conf_mat: This is the confusion matrix generated in another function
cdim: Number of classes

OUTPUT

A percent correctness value

*/
#include "stdio.h"

float Correctness_Checker_ConfMatrix (float ** conf_mat, int cdim){
    // Sum and totals are defined for the percent calculation
    float sum;
    // They start out at 0
    sum=0;
    // A for loop goes through every term of the arrays
     for (int i=0; i<cdim; i++){
         // Finds sum of the diagonal of the confusion matrix which is the probability of correct identification
         sum+=conf_mat[i][i];
     }
    return sum* 100;    
}