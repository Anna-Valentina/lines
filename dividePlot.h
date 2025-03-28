#ifndef DIVIDEPLOT_H_INCLUDED
#define DIVIDEPLOT_H_INCLUDED
#include <math.h>



//функция, определяющая разность между кол-вом точек "над" прямой и "под" прямой
int countDifPointsForOnePair(float **points, int n, float x1, float y1, float x2, float y2)
{
    double dif; //хранит значение (y2-y1)*(x-x1)-(y-y1)*(x2-x1)
    //(y2-y1)*(x-x1)-(y-y1)*(x2-x1)>0

    //(y2-y1)*(x-x1)-(y-y1)*(x2-x1)<0
    double x,y;
    int countPointPlus=0;
    int countPointMinus=0;
    for(int i=0;i<n;i++){
        x=points[0][i];
        y=points[1][i];
        dif=(y2-y1)*(x-x1)-(y-y1)*(x2-x1);
        if(dif<0)
            countPointMinus++;
        else
            if(dif>0)
                countPointPlus++;
    }
    return countPointMinus-countPointPlus;

}


int* findDifCountPoints(float **points, int n, int * &index1, int* &index2){
/*
перебор всевозможных пар точек, построение прямой на основе выбранных 2 точек,
подсчет точек в каждой полуплоскости (для каждой точки массива определение полуплоскости,
в которой точка находится относительно построенной прямой), определение разности в количестве
точек результат
*/

 int* diffPoints=new int[n*(n-1)/2];
 index1=new int[n*(n-1)/2];
 index2=new int[n*(n-1)/2];
 int i,j;
 int k=0;
 // n*(n-1)/2;
 for(i=0;i<n;i++)   //первая точка пары (n)
    for(j=i+1;j<n;j++)  //вторая точка (n-1)
         {
            //1(points[0][i],points[1][i]) -2(points[0][j],points[1][j])
            // (x1,y1)-(x2,y2): (y2-y1)*(x-x1)-(y-y1)*(x2-x1)=0
            // A*x+B*y+C=0 (y=k*x+b: x=1)

            //перебор всех остальных точек с определением знака
            diffPoints[k]=countDifPointsForOnePair(points, n, points[0][i], points[1][i], points[0][j], points[1][j]);
            index1[k]=i;
            index2[k]=j;
            k++;
         }
 return diffPoints;
}

//вычисление элемента, в котором достигается минимум разности
int findMin(int*diff, int n) {

    int indexMin=0;
    for(int i=1;i<n;i++)
        if(abs(diff[i])<abs(diff[indexMin]))
           indexMin=i;

    return indexMin;

}


#endif // DIVIDEPLOT_H_INCLUDED
