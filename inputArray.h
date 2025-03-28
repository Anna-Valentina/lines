#include <iostream>
using namespace std;

// выходные параметры: массив 2xn
float ** inputFromKeyboard(int &n) {
    cout<<"Input number of points: ";
    cin>>n;
    //???n=0; n=-3???
    if(n<2)
    {
        cout<<"Task has sense only for number points >=2. Number of point was changed to 2";
        n=2;
    }

    float **a;  //2 x n
    a=new float*[2];
    a[0]=new float[n];
    a[1]=new float[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Input point #"<<i+1<<" (x): ";
        cin>>a[0][i];
        cout<<"Input point #"<<i+1<<" (y): ";
        cin>>a[1][i];
    }
    return a;
}

/*

void inc2(int x)
{
    x=2*x; //x=8
}

void inc_2(int &x)
{
    x=2*x; //x=8
}


int main()
{
  int x=4;
  inc2(x);
  //x=4
  inc_2(x); //x=8
}

*/
