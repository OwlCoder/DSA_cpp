#include "Algorithms.hpp"
#include <stdlib.h>
#include "utils.hpp"
#include <string>

using namespace std;
using namespace algortithms;

SortVec::SortVec(const SortVec::FVector& unsorted_vec):pivot_pos("end")
{
    size_vec=unsorted_vec.size();
    array=new FVector(unsorted_vec);
}

SortVec::~SortVec()
{
    delete array;
}

void SortVec::quickSort(int left_slider, int right_slider)
{
    // breaking condition for recursion   
    if (left_slider>=right_slider)
    {
        return;
    }
    else{
        // cout<<left_slider<<" "<<right_slider<<endl;
        utils::printVec<float>(*array);
    }

    int new_pivot_idx=partition(left_slider,right_slider);
    
    SortVec::quickSort(left_slider,new_pivot_idx-1);
    SortVec::quickSort(new_pivot_idx,right_slider);
}

int SortVec::partition(int left_slider, int right_slider)
{
    int new_pivot_idx;
    if (pivot_pos==string("mid"))
    {
        int pivot=(left_slider+right_slider)/2;
        float pivot_val=(*array)[pivot];
        
        while (left_slider<=right_slider)
        {
            while((*array)[left_slider]<pivot_val)
            {
                left_slider++;
            }
            while((*array)[right_slider]>pivot_val)
            {
                right_slider--;
            }
            if(left_slider<=right_slider)
            {
                utils::swapVec<float>(*array,left_slider,right_slider);
                left_slider++;
                right_slider--;
            } 
        }
        new_pivot_idx=left_slider;
    }
    else if(pivot_pos==string("end"))
    {
        int pivot=right_slider;
        float pivot_val=(*array)[pivot];

        int lo=left_slider;
        int hi=right_slider;

        left_slider=lo;
        for(right_slider=lo+1; right_slider<hi;++right_slider)
        {
            if((*array)[right_slider]<pivot_val)
            {
                left_slider++;
                utils::swapVec<float>(*array, left_slider,right_slider);
            }
        }
        left_slider++;
        utils::swapVec<float>(*array,pivot,left_slider);
        new_pivot_idx=left_slider;
    }
    else
    {
        //put the random pivot in the middle or at the end and do the same
    }
    
    return new_pivot_idx;
}