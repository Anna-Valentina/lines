#ifndef DIVIDEPLOT_H_INCLUDED
#define DIVIDEPLOT_H_INCLUDED


int* findDifCountPoints(float **points, int n, int *index1, int* index2){
/*
������� ������������ ��� �����, ���������� ������ �� ������ ��������� 2 �����,
������� ����� � ������ ������������� (��� ������ ����� ������� ����������� �������������,
� ������� ����� ��������� ������������ ����������� ������), ����������� �������� � ����������
����� ���������
*/
 int i,j;
 for(i=0;i<n;i++)   //������ ����� ����
    for(j=i+1;j<n;j++)  //������ �����
         {
            //(points[0][i],points[1][i]) -(points[0][j],points[1][j])
            // (x1,y1)-(x2,y2): (y2-y1)*(x-x1)-(y-y1)*(x2-x1)=0
            // A*x+B*y+C=0 (y=k*x+b: x=1)


         }



}


#endif // DIVIDEPLOT_H_INCLUDED
