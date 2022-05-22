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

void Bayes_Rule (float **class_conditional, float **cifd, int *assign, float *percentages, int cdim, int ddim ){
    // Finds the probability of each class
    float pc = 1/(float)cdim;
    // Initially the best probability is 0
    int bestPos = 0;
    // Value used later
    int k;
    // Sum used for normalization
    float sum;
    
    for (int i=0; i<ddim; i++){
        // Denominator of bayes rule is generated
        float denominator=0;  
        for (int j=0; j<cdim; j++){
            denominator += class_conditional[j][i]*pc;
        }
        //Finds the best value for each measurement and assigns it's class to the measurement
        int best=0;
        float bestval=-1;
        
        for (int j=0; j<cdim; j++){
            cifd[j][i]=class_conditional[j][i]*pc/denominator;
            if (bestval<cifd[j][i]){
                best=j;
                bestval=cifd[j][i];
            }
        }
        assign[i]=best+1;
    }
    // Sum starts at 0
    sum = 0;
    // P(c,d) is normalized to add up to 1
    for (int i=0; i<cdim; i++){
        for (int j=0; j<ddim; j++){
            sum+=cifd[i][j];
        }
    }
    for (int i=0; i<cdim; i++){
        for (int j=0; j<ddim; j++){
            cifd[i][j]/=sum;
        }
    }
}