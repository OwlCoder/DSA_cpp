#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace algortithms
{
class SortVec
{
    //public variables
    public:
        typedef vector<float> FVector;
    
    //public functions
    public:
        //constructor
        SortVec(const FVector& unsorted_vec);

        //destructor: deleting anything on heap is necessary
        ~SortVec();

        /*
        quick sort: choose pivot element randomly
        @param left_slider: points to the first element of the section of the unsorted array
        @param right_slider: points to the last element of the section of the unsorted array 
        @return sorted_vec: stored in array (pvt var) itself
        */
        void quickSort(int left_slider, int right_slider);

        //merge sort
        //heap sort

    //private variables
    private:
        FVector* array;
        int size_vec;
        std::string pivot_pos;

    //private functions
    private:
        int partition(int left_slider, int right_slider);
        
        
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