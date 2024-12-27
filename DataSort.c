//-- Program to sort different types of data
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//-----------------------------------------------------------------------------
#define ARRAYSIZE 5

//-- Define typedefs for a pointer to an integer, an array of five integers, an array of five pointers to integers
typedef int* intPointer;
typedef int fiveIntArray[ARRAYSIZE];
typedef intPointer pointerArray[ARRAYSIZE];
//-----------------------------------------------------------------------------
//-- Function to initialize integer array and pointer array (pointer array points at
//-- integer arrays values)
void initialize(fiveIntArray intArray, pointerArray pointArray) {

//-- Seed random number generation
    srand(getpid());
//-- Populate intArray with random numbers
    for(int i = 0; i < 5; ++i) {
        intArray[i] = rand();
//-- Populate the pointArray to point to the intArray elements
        pointArray[i] = &intArray[i];
    }

}
//-- Function to print out integer array values
void printIntArray(fiveIntArray intArray) {
    for(int i = 0; i < 5; ++i) {
        printf(" %d : %10d\n", i, intArray[i]);
    }
}

//-- Function to print out pointer array values (values it points to)
void printPointerArray(pointerArray pointArray) {
    for(int i = 0; i < 5; ++i) {
        printf(" %d : %10d\n", i, *pointArray[i]);
    }
}

//-- Function to bubble sort integer array
void bubbleSortIntArray(fiveIntArray intArray) {

//-- Declare temp variable for swapping and i and j variables for the for loops
    int temp;
    int i;
    int j;
//-- bubble sort
    for (i = 0; i < ARRAYSIZE - 1; ++i) {
        for (j = 0; j < ARRAYSIZE - i - 1; ++j) {
            if (intArray[j] > intArray[j+1]) {
                temp = intArray[j];
                intArray[j] = intArray[j+1];
                intArray[j+1] = temp;
            }
        }
    }

}

//-- Function to bubble sort pointer array
void bubbleSortPointerArray(pointerArray pointArray) {

//-- Declare temp variable for swapping and i and j variables for the for loops
    intPointer temp;
    int i;
    int j;
//-- bubble sort
    for (i = 0; i < ARRAYSIZE - 1; ++i) {
        for (j = 0; j < ARRAYSIZE - i - 1; ++j) {
            if (*pointArray[j] > *pointArray[j+1]) {
                temp = pointArray[j];
                pointArray[j] = pointArray[j+1];
                pointArray[j+1] = temp;
            }
        }
    }

}



int main(void) {

//-- Declare Arrays
    fiveIntArray intArray;
    pointerArray pointArray;

//-- Initialize integer array and pointer array 
    initialize(intArray,pointArray);

//-- Call function to print out integer array
    printf("---- Initialized array of integers ----\n");
    printIntArray(intArray);

//-- Bubble sort pointer array
    bubbleSortPointerArray(pointArray);
    
//-- Call function to print out integers pointed to by pointer array
    printf("---- Sorted array of pointers ----\n");
    printPointerArray(pointArray);

//-- Bubble sort integer array
    bubbleSortIntArray(intArray);

//-- Call function to print out sorted integer array
    printf("---- Sorted array of integers ----\n");
    printIntArray(intArray);

//-- Call function to print out integers pointed to by pointer array
    printf("---- Array of pointers ----\n");
    printPointerArray(pointArray);

    return(EXIT_SUCCESS);

}