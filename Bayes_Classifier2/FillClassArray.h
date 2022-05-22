/*
FillClassArray.c

PURPOSE

    This function creates a two dimentional class conditional probability array from the true classes and probabilities

INPUT ARGUMENTS

classarray: The empty array that will be filled in this function
trueClass: This is the integer true class array for each measurement
prob: This is the 1d float array of normalized probabilties for each class and measurment
cdim: This is the number of classes
dim: The number of measurements for each class
PERT: The perturbation
seed: The seed used for randomization

OUTPUT

A row-normalized two dimentional float class-conditional probability array

*/
#include "stdio.h"
#include "PrintFloatArray.h"
#include "common.h"

int TODEBUG;

void fillClassArray(float **classarray, int *trueClass, float *prob, int cdim, int ddim, float PERT, int seed){
    // Value used for perturbation
    float valP;
    // Sum used for normalization
    float sum;
    // Value being perturbed
    float temp;
    // Value after perturbation
    float newValP;

    // Filling class array

    for (int i=0; i<ddim; i++){
        // This for loop goes through all elements of the true class array and makes any measurement that is not it's true class 0
        for (int j=0; j<cdim; j++)
            classarray[j][i] = 0;
        // Fills the measurements with their respective true classes with the values from the probabilities array
        classarray[trueClass[i]-1][i] = prob[i];
    }
    // Randomizer is initialized
    srand((unsigned int)seed);
    for (int i=0; i<ddim; i++){
        // We get the value that is not 0
        temp = classarray[trueClass[i]-1][i];
        // We find the product of that value with the perturbation
        valP = PERT*temp;
        for (int j=0; j<cdim; j++){
            // We fill the column with the product divided by the number of classes
            newValP = valP/(cdim);
            classarray[j][i] = newValP;
        }
        newValP = valP;
        classarray[trueClass[i]-1][i] = temp-valP+valP/(cdim);
    }
    
    // Array is normalized
    for (int i=0; i<cdim; i++){
        // Sum starts at 0 for each row
        sum = 0;
        // Adds each value in the row to find the total sum
        for (int j=0; j<ddim; j++){
            sum+=classarray[i][j];
        }
        // Divides each value in the row by the sum so that the total is equal to 1
        for (int j=0; j<ddim; j++){
            classarray[i][j]/=sum;
        }
    }
    if (TODEBUG == 1){
        printf("conditional probability after perturbation of d given c P(d | c) c=1,2,...%d\n",cdim);
        printFloatArray(classarray,cdim, ddim);
        printf("\n");  
    }
}