/*
TrueClassArray.c

PURPOSE

    This subroutine creates the true class array. The goal of this program is to generate an array with the length measuremnts*cdim with an equal number of each class.

INPUT ARGUMENTS

array: An empty integer array that will be filled with the classes. 
samples: The number of elements in the measurement space for each class
cdim: The number of classes 


OUTPUT

An array filled with classes from 0-cdim-1 that can be called in another function.

*/

void trueClassArray(int * array, int samples, int cdim){
    
    // This for loop fills the array with an equal number of each class.
    for (int j=0; j<cdim; j++){
        for (int i=0; i<samples; i++){
            array[j*samples+i]=j+1;
        }
    }   
}