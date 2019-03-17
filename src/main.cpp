#include <iostream>
#include <vector>
#include "Algorithms.hpp"
#include "utils.hpp"

using namespace std;
using namespace algortithms;
using namespace utils;

int main(int argc, char *argv[])
{
    //input vector which needs to be sorted
    SortVec::FVector input_vec{10,80,30,90,40,50,70};
    cout<<"input vector: \t ";
    printVec<float>(input_vec);
    //output where we are going to store the sorted vector
    SortVec::FVector output_vec;
    // //declaring an object of the class
    SortVec sort_vec(input_vec);
    sort_vec.quickSort(0,input_vec.size()-1);

}