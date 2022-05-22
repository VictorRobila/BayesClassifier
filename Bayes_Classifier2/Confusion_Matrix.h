/*
Bayes_Rule.c

PURPOSE

    Thus subroutine uses bayes rule to guess the class of each measurement using the class conditional probability arrays and assigns each measurement a class

INPUT ARGUMENTS

class_conditional: This is the float two dimentional class conditional array
cifd: An empty two dimensional float array for use in classification
assign: An empty integer one dimentional array that will be filled with the assigned classes
cdim: The number of classes
ddim: The number of measurements in all of the arrays

OUTPUT

An array with all the assigned classes

*/
#include "stdio.h"
#include "math.h"
#include "common.h"
#include "printFloatArray.h"


void Confusion_Matrix (float **cifd, int *assign, float **conf_mat, int cdim, int ddim){
    
    // zero out the confusion matrix
    for (int i=0; i<cdim; i++)
        for (int j=0; j<cdim; j++)
            conf_mat[i][j]=0;
    
    // fill in the confusion matrix
    for (int i=0; i<cdim; i++){
        for (int j=0; j<ddim; j++){
            conf_mat[i][assign[j]-1]+=cifd[i][j];
        }
    }
    if (TODEBUG==1){
        printf("confusion matrix\n");
        printFloatArray(conf_mat,cdim,cdim);
        printf("\n");
    }
}