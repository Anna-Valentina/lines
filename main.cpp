#include <iostream>
#include "inputArray.h"
#include "dividePlot.h"

using namespace std;

int main()
{
    float **arr;
    int n;
    arr=inputFromKeyboard(n);
    int *index1,*index2;
    int *res;
    res=findDifCountPoints(arr, n, index1, index2);
    int indexMin=findMin(res, n);
    cout<<"Points, which base for divide plot into 2 part with minimal difference: #"<<index1[indexMin]<<" and #"
            <<index2[indexMin]<<" with difference "<<res[indexMin];


    return 0;
}
