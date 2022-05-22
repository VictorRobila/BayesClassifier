/*
Bayes_Rule.c

PURPOSE

    Thus subroutine uses bayes rule to guess the class of each measurement using the class conditional probability arrays and assigns each measurement a class

INPUT ARGUMENTS

class_conditional: This is the float two dimentional class conditional array
cifd: An empty two dimensional float array for use in classification
assign: An empty integer one dimentional array that will be filled with the assigned classes
dim2: The number of classes
dim1: The number of measurements in all of the arrays

OUTPUT

An array with all the assigned classes

*/
#include "stdio.h"
#include "math.h"

void Bayes_Rule (float **class_conditional, float **cifd, int *assign, int dim2, int dim1){
    // These are the P(c1) and P(c2) in the bayes rule
    float p1 = 0.5;
    float p2=1-p1;
    int bestPos = 0;
    int k;
    float d1;
    for (int i=0; i<dim1; i++){
        bestPos = 0;
        for (int j=1; j<dim2; j++){
            k = bestPos;
            // Bayes rule is used for each class using the class conditional probabilities and the P(c1) and P(c2) values.
            cifd[j][i]= (class_conditional[j][i]*p1)/((class_conditional[j][i]*p1)+(class_conditional[k][i]*p2));       
            cifd[k][i]= (class_conditional[k][i]*p2)/((class_conditional[k][i]*p2)+(class_conditional[j][i]*p1));
           // The class is assigned based on which one has a higher probability of being true.
           if (cifd[k][i] > cifd[j][i]){
                bestPos=k;
            }
            else {
                bestPos = j;
                /*
                if (cifd[k][i] == cifd[j][i]){
                    printf("Equality\n");
                } 
                */
            }
        }
        assign[i]=bestPos+1;
    }
}