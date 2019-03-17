#include "Algorithms.hpp"
#include <stdlib.h>
#include "utils.hpp"

using namespace std;
using namespace algortithms;

SortVec::SortVec(const SortVec::FVector& unsorted_vec)
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
    //selecting pivot randomly between left and right slider
    // int pivot=left_slider + (rand() % static_cast<int>(right_slider - left_slider + 1));
    if (left_slider>=right_slider)
    {
        return;
    }
    else{
        cout<<left_slider<<" "<<right_slider<<endl;
        utils::printVec<float>(*array);
    }

    int pivot=(left_slider+right_slider)/2;
    float pivot_val=(*array)[pivot];
    //sort them
    int beg_idx=left_slider;
    int end_idx=right_slider;
    while (left_slider<right_slider)
    {       
        
        while((*array)[left_slider]<pivot_val)
        {
            left_slider++;
        }
        while((*array)[right_slider]>pivot_val)
        {
            right_slider--;
        }
        if((*array)[left_slider]>=(*array)[right_slider])
        {
            utils::swapVec<float>(*array,left_slider,right_slider);
            left_slider++;
            right_slider--;
        } 
        cout<<"l="<<left_slider<<" r="<<right_slider<<endl;
        
        // utils::printVec<float>(*array);
    }
    //call quick sort on the bi-section
    int mid_idx=left_slider;
    SortVec::quickSort(beg_idx,mid_idx-1);
    SortVec::quickSort(mid_idx,end_idx);
    // utils::printVec<float>(*array);
}
