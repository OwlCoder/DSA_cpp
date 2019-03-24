#include "Vector.hpp"
#include <stdlib.h>
#include "utils.hpp"
#include <string>

using namespace std;
using namespace DSA;

Vector::Vector(const FVector& unsorted_vec):pivot_pos("end")
{
    size_vec=unsorted_vec.size();
    array=new FVector(unsorted_vec);
}

Vector::~Vector()
{
    delete array;
}

void Vector::initSortVec(const Vector::FVector& unsorted_vec)
{
    array->clear();
    size_vec=unsorted_vec.size();
    for(int push_iter=0; push_iter<size_vec; ++push_iter)
    {
        array->push_back(unsorted_vec[push_iter]);
    }
}

void Vector::quickSort(int left_slider, int right_slider)
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
    
    Vector::quickSort(left_slider,new_pivot_idx-1);
    Vector::quickSort(new_pivot_idx,right_slider);
    
}

void Vector::mergeSort(int left_slider, int right_slider)
{
    // breaking condition for recursion
    if (left_slider>=right_slider)
    {
        return;
    }

    // find the middle point to divide the array into two halves
    int mid=left_slider+(right_slider-left_slider)/2;
    // Call mergeSort for first half
    Vector::mergeSort(left_slider,mid);
    // Call mergeSort for second half
    Vector::mergeSort(mid+1, right_slider);
    // Merge the two halves by sorting
    Vector::sortNmerge(left_slider, mid, right_slider);
    // print after sorting
    utils::printVec<float>(*array);
}
//private functions

int Vector::partition(int left_slider, int right_slider)
{
    int new_pivot_idx;
    if (pivot_pos==string("mid"))
    {
        int pivot=left_slider + (right_slider-left_slider)/2;
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


void Vector::sortNmerge(int left_idx, int mid_idx, int right_idx)
{
    // we will need three iterators for subarray1, subarray2 and the original array
    int sub1_iter, sub2_iter, orig_iter;
    sub1_iter=0;
    sub2_iter=0;
    orig_iter=left_idx;
    // let's also see the length of each subarray
    int len_sub1, len_sub2;
    len_sub1=mid_idx-left_idx+1;
    len_sub2=right_idx-mid_idx;
    // make two temp subarrays (this is where space complexity comes up)
    // TO DO: make them fixed lengths since we already know the length of each subarr
    // TO DO: copy partial contents of one vector to another more efficiently?
    FVector subarr1, subarr2;
    for(sub1_iter=0; sub1_iter<len_sub1; ++sub1_iter)
    {
        subarr1.push_back((*array)[left_idx+sub1_iter]);
    }
    for(sub2_iter=0; sub2_iter<len_sub2; ++sub2_iter)
    {
        subarr2.push_back((*array)[mid_idx+1+sub2_iter]);
    }
    
    //re-intialize the iterators
    sub1_iter=0;
    sub2_iter=0;

    // sort them trivially
    while (sub1_iter<len_sub1 && sub2_iter<len_sub2)
    {
        if(subarr1[sub1_iter]<subarr2[sub2_iter])
        {
            (*array)[orig_iter]=subarr1[sub1_iter];
            sub1_iter++;
        }
        else
        {
            (*array)[orig_iter]=subarr2[sub2_iter];
            sub2_iter++;
        }
        orig_iter++;
    }

    //copy the remaining elements of sub1 or sub2
    while(sub1_iter<len_sub1)
    {
        (*array)[orig_iter]=subarr1[sub1_iter];
        sub1_iter++;
        orig_iter++;
    }
    while(sub2_iter<len_sub2)
    {
        (*array)[orig_iter]=subarr2[sub2_iter];
        sub2_iter++;
        orig_iter++;
    }

}

