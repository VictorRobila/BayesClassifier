/*
TrueClassArrayPerc.c

PURPOSE

    This subroutine creates the true class array. The goal of this program is to generate an array with the length measuremnts*cdim with an equal number of each class.

INPUT ARGUMENTS

array: An empty integer array that will be filled with the classes. 
samples: The number of elements in the measurement space for each class
cdim: The number of classes 


OUTPUT

An array filled with classes from 0-cdim-1 that can be called in another function.

*/

#include "PrintFloatVector.h"
#include "PrintIntVector.h"
#include "common.h"
#include <stdio.h>


void trueClassArrayPerc(int * array, float *percentages, float *pc, int ddim, int cdim){
    int countdone = 0;
    int * classcount = (int *)malloc(cdim*sizeof(int));
    float percsum = 0;
    int n;
    for (int i=0; i<cdim; i++)
        percsum+=percentages[i];
    if (fabs(100-percsum)>0.000001){
        printf("Percentage sum too far from 100");
        exit(0);
    }
    if (TODEBUG == 1){
        printf("p(c): \n");
            printFloatVector(percentages,cdim);   

    }
    //printf("Percentages for each class: \n");
    //printFloatVector(percentages,cdim);    
    // This for loop fills the array with a proportional number of each class
    
    for (int i=0; i<cdim; i++){
        classcount[i]=0;
        n=percentages[i]/100.0*(float)ddim+0.5;
        for (int j=0; j<n; j++){
            array[countdone]=i+1;
            classcount[i]++;
            countdone++;
        }
    }
    //printf("%d\n",countdone);
    if (countdone > ddim){
        printf("Generated too many samples!\n");
        exit(0);
    }
    while (countdone<ddim){
        array[countdone]=1;
        classcount[0]++;
        countdone++;
    }   
 
    for (int i=0; i<cdim; i++)
        pc[i]=classcount[i]/(float)ddim;

    if (TODEBUG == 1){
        printf("p(c): \n");
        printFloatVector(percentages,cdim);   
        printf("\n");
        printf("true class\n");
        printIntVector(array,ddim);
        printf("\n");
    }
}