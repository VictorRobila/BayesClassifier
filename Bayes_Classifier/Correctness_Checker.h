/*
Correctness_Checker.c

PURPOSE

    This function find the correctness percentage of the assigned classes.

INPUT ARGUMENTS

true: The true class one dimentional integer array
assign: The one dimentional integer assigned class array
dim1: The amount of measurements in each array

OUTPUT

A percent correctness value

*/
#include "stdio.h"

float Correctness_Checker (int *true, int *assign, int dim1){
    // Sum and totals are defined for the percent calculation
    float sum;
    float total;
    //printf("checking correctness");
    // They start out at 0
    total=0;
    sum=0;
    // A for loop goes through every term of the arrays
     for (int i=0; i<dim1; i++){
         total+=1;
       if (true[i]==assign[i]){
           // The sum and total are increased by 1 if the true class is equal to the assigned class
            sum += 1;
        }
        else{
            //printf("%d incorrect\n",i);
        }
     }
    // The percent is calculated and returned
    return sum/total * 100;

    
}