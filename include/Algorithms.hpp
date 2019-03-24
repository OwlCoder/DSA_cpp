#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace algorithms
{
//TO DO: make a class that sorts a vector of any type (use template)
class SortVec
{
    //public variables
    public:
        typedef vector<float> FVector;
    
    //public functions
    public:
        //constructor
        SortVec();

        //destructor: deleting anything on heap is necessary
        ~SortVec();

        // initializing the vector with unsorted vector to call on another sorting method
        void init(const FVector& unsorted_vec);
        
        /*
        quick sort
        @param left_slider: points to the first element of the section of the unsorted array
        @param right_slider: points to the last element of the section of the unsorted array 
        @return sorted_vec: stored in array (pvt var) itself
        TO DO: return the sorted vec rather than just printing it
        */
        void quickSort(int left_slider, int right_slider);

        /*
        merge sort
        stable sorting algorithm
        */
        void mergeSort(int left_slider, int right_slider);

        /*
        insertion sort
        */
        //heap sort

    //private variables
    private:
        FVector* array;
        int size_vec;
        std::string pivot_pos;

    //private functions
    private:
        /*
        calculates index of the partition between lower than and greater than sub-arrays wrt pivot
        */
        int partition(int left_slider, int right_slider);
        /*
        merge two sub arrays : intended for merge sort
        First subarray is arr[1...m]
        Second subarray is arr[m+1...r]
        */
        void sortNmerge(int left_idx, int mid_idx, int right_idx);
        
        
};//end class sortvec

class SearchVec
{
    //public variables
    public:

    //public functions
    public:

    //private variables
    private:

    //private functions
    private:

};

}//end ns algorithms