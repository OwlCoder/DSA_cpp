#include <iostream>
#include <vector>
#include "Algorithms.hpp"
#include "utils.hpp"

using namespace std;
using namespace algorithms;
using namespace utils;

int main(int argc, char *argv[])
{
    cout<<"------TESTING OF ALL SORTING ALGORITHMS------"<<endl;
    //input vector which needs to be sorted
    SortVec::FVector input_vec{10,80,30,90,40,50,70};
    //declaring an object of the class
    SortVec sort_vec;

    cout<<"------QUICK SORT TEST 1-------"<<endl;
    sort_vec.init(input_vec);
    cout<<"input vector: \t ";
    printVec<float>(input_vec); 
    sort_vec.quickSort(0,input_vec.size()-1);

    cout<<"------MERGE SORT TEST 1-------"<<endl;
    sort_vec.init(input_vec);
    cout<<"input vector: \t ";
    printVec<float>(input_vec);
    sort_vec.mergeSort(0,input_vec.size()-1);
    
}