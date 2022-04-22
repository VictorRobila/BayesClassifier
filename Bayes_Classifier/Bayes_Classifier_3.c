/*
Bayes_Chassifier_3.c

PURPOSE

    This Program uses Bayes rule to classify random measurements into 2 classes.

INPUT ARGUMENTS

A file in this format:
Number of Measurements
Number of repetitions
A random seed

OUTPUT

The percent correctness for each trial

*/


// These are needed to print and choose random numbers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// These are all the subroutines
#include "Bayes_Rule.h"
#include "Confusion_Matrix.h"
#include "Correctness_Checker.h"
#include "Correctness_Checker_ConfMatrix.h"
#include "FillClassArray.h"
#include "InitFloatArray.h"
#include "InitFloatVector.h"
#include "PrintFloatVector.h"
#include "PrintIntArray.h"
#include "PrintIntVector.h"
#include "Shuffle.h"
#include "TrueClassArray.h"
#include "TrueClassArrayPerc.h"
#include "common.h"

// define the file that the user edits
#define dataFile "testData.dat"
#define plotDataFile "plotData.csv"

// define the debug feature

int TODEBUG=1;

int main(){
    // used for for loops
    int i,j,k; 
    // 2 dimentional class conditional probabilities array
    float *probabilities;
    // One dimentional true class array
    int *true_class;
    // Class conditional probability arrays
    float **classarray;
    // Two arrays needed for the bayes rule
    float **cifd;
    // Confusion matrix
    float **conf_mat;
    // The assigned class array
    int *assign;
    // Percentages of each class
    float *percentages;
    // Correctness value
    float *pc;
    float correctness;
    // Averaged correctness
    float avgcorecnetss;
    // Percentage in the percentages array
    float percentage, percsum;
    // Data entered by the user into the file
    int trials, ddim, cdim, seed, samples;
    float PERT=1;
    
    // File is opened and read
    FILE *fp;

    fp = fopen(dataFile, "r");
    if (fp == NULL){
        printf("ERROR! File %s not found\n",dataFile);
        exit(1);
    }
    int read_items = 0;
    
    //Malloc for percentages

    
    //class count initialized to an impossible value
    cdim = 0;
    // Add ability to put debug in the input file
    // Each of the data values are scanned
    read_items+=fscanf(fp,"%d",&trials);
    read_items+=fscanf(fp,"%d",&cdim);
    read_items+=fscanf(fp,"%d",&ddim);
    read_items+=fscanf(fp,"%d",&seed);
    percentages =(float *) malloc(cdim*sizeof(float));
    percsum=0;
    for (int i=0; i < cdim; i++){
        read_items+=fscanf(fp,"%f", &percentage);
        percentages[i]=percentage;
    }
    
    
    // Checks if user input is incorrect
    if (cdim>0 && read_items != 4+cdim){
        printf("File %s was found but data could not be read properly\n",dataFile);
        exit(1);
    }

    printf("Read %d %d %d %d\n",trials,cdim, ddim, seed);
    printFloatVector(percentages,cdim);

    // Calculates ddim from the values entered by the user
    //ddim=samples*cdim;

    // Read File closed
    fclose(fp);
    
    // Exits if the plotDataFile is broken
    fp = fopen(plotDataFile, "w");
    if (fp == NULL){
        printf("ERROR! File %s could not be written\n",plotDataFile);
        exit(1);
    }


    // Allocate Memory for arrays
    probabilities =(float *) malloc(ddim*sizeof(float));
    pc= (float *) malloc(ddim*sizeof(float));
    classarray = (float **) malloc(cdim*sizeof(float*));
    for (i=0;i<cdim;i++)
        classarray[i]=(float *) malloc(ddim*sizeof(float));

    cifd = (float **) malloc(cdim*sizeof(float*));
    for (i=0;i<cdim;i++)
        cifd[i]=(float *) malloc(ddim*sizeof(float));

    conf_mat = (float **) malloc(cdim*sizeof(float*));
    for (i=0;i<cdim;i++)
        conf_mat[i]=(float *) malloc(cdim*sizeof(float));

    true_class= (int *) malloc(ddim*sizeof(int));
    assign= (int *) malloc(ddim*sizeof(int));

    //for(float myPERT=PERT; myPERT >=0; myPERT-=0.05){
        // Average correctness starts at 0
        avgcorecnetss = 0;

        //fprintf(fp,"%0.2f",1-myPERT);
        
        // For loop that runs for the number of trials
        for (int round=1; round <= trials; round++){
            // True class array is formed and shuffled
            trueClassArrayPerc(true_class,percentages, ddim,cdim);
            shuffle(true_class,ddim,seed);

            // Probabilities array is filled with random floats that add up to 1
            initFloatVector(probabilities,ddim, seed);

            // Class conditional probability arrays are fileld
            fillClassArray(classarray, true_class, probabilities, cdim, ddim, 1-1 ,seed);

            // Bayes rule is used to assign a class to each measurement
            Bayes_Rule(classarray,cifd, assign, percentages, cdim, ddim);

            Confusion_Matrix(cifd, assign, conf_mat, cdim, ddim);

            // Correctness is evaluated and averaged
            //correctness=Correctness_Checker(true_class,assign,ddim);

            // Correctness is evaluated and averaged
            correctness=Correctness_Checker_ConfMatrix(conf_mat,cdim);

            avgcorecnetss += correctness;

            // debugging if something goes wrong
            if (TODEBUG == 1){

            printf("p(c): \n");
            printFloatVector(percentages,cdim);    


            printf("true class\n");
            printIntVector(true_class,ddim);
            printf("\n");
        
            printf("\n");
            printf("marginal probability of P(d) \n");
            printFloatVector(probabilities,ddim);
            printf("\n");
            printf("conditional probability after perturbation of d given c P(d | c) c=1,2,...%d\n",cdim);
            printFloatArray(classarray,cdim, ddim);
            printf("\n");
            printf("P(c,d)\n");
            printFloatArray(cifd,cdim,ddim);
            printf("\n");
            printf("assigned class\n");
            printIntVector(assign, ddim);
            printf("\n");
            printf("confusion matrix\n");
            printFloatArray(conf_mat,cdim,cdim);
            printf("\n");


        
            }

            // The round seed, correctness is printed for each trial
            //printf("Round %d seed %u correctness %.5f\n",round,(unsigned int)seed, correctness);
            fprintf(fp,",%0.3f",correctness);
            seed = seed + 234;
        }
        fprintf(fp,"\n",correctness);


        // The average correctness is printed
        printf("PERT: %0.3f - Ran %d runs using %d measurements in the measurement space and averaged %.3f accuracy\n",1-1,trials,ddim,avgcorecnetss/trials);
    //}

    // Memory is freed
    for (i=0;i<cdim;i++){
        free(classarray[i]);
        free(cifd[i]);
        free(conf_mat[i]);
    }
    free(probabilities);
    free(true_class);
    free(classarray);
    free(cifd);
    free(conf_mat);
    free(assign);
    free(pc);

    // Write File closed
    fclose(fp);

    return 0;
}

