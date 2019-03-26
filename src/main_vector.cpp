#include <iostream>
#include <vector>
#include "Vector.hpp"
#include "utils.hpp"

using namespace std;
using namespace DSA;
using namespace utils;

int main(int argc, char *argv[])
{
    cout<<"------TESTING OF ALL SORTING ALGORITHMS------"<<endl;
    //input vector which needs to be sorted
    Vector::FVector input_vec{10,80,30,90,40,50,70};
    //declaring an object of the class
    Vector vec_obj(input_vec);

    cout<<"------QUICK SORT TEST 1-------"<<endl;
    vec_obj.initSortVec(input_vec);
    cout<<"input vector: \t ";
    printVec<float>(input_vec); 
    vec_obj.quickSort(0,input_vec.size()-1);

    cout<<"------MERGE SORT TEST 1-------"<<endl;
    vec_obj.initSortVec(input_vec);
    cout<<"input vector: \t ";
    printVec<float>(input_vec);
    vec_obj.mergeSort(0,input_vec.size()-1);

    cout<<"------TESTING OF ALL SEARCHING ALGORITHMS------"<<endl;
    //find the index in sorted vector
    cout<<"-------BINARY SEARCH TEST 1------"<<endl;
    vec_obj.binarySearch(0,input_vec.size()-1,70);
    cout<<"-------BINARY SEARCH TEST 2------"<<endl;
    vec_obj.binarySearch(0,input_vec.size()-1,90);

}